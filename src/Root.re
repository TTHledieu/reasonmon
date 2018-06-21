module Styles = {
open Css;
  let rootContainer = style([
    display(`flex),
    flexDirection(`column),
  ]);
};

let getPokemons = "https://pokeapi.co/api/v2/pokemon/";

type route = 
  | Home
  | About;

type fetchState = 
  | Loaded
  | Loading
  | Error;

type action =
  | ChangeRoute(route)
  | PokemonsFetch
  | PokemonsFetched(array(Home.pokemon))
  | PokemonsFetchFailure;

type state = {
  route: route,
  fetching: fetchState,
  pokemons: array(Home.pokemon),
};

module Decode = {
  open Json.Decode;
  let pokemon = json : Home.pokemon => {
      url: json |> field("url", string),
      name: json |> field("name", string)
    };
  let pkmn = json : array(Home.pokemon) =>
    json |> field("results", array(pokemon))
};

let component = ReasonReact.reducerComponent("Root");

let handleClick = (tuple, _self) => {
  let (route, event) = tuple;
  if (! ReactEventRe.Mouse.defaultPrevented(event)) {
    ReactEventRe.Mouse.preventDefault(event);
    ReasonReact.Router.push(route)
  };
};

let renderBody = (state: state) => {
  switch (state.route) {
    | Home => {
      switch(state.fetching) {
      | Loading => <h1>(ReasonReact.string("Loading..."))</h1>
      | Error => <h1>(ReasonReact.string("An error happened... Check your network !"))</h1>
      | Loaded => <Home pokemons=state.pokemons />
      }
    }
    | About => <div>(ReasonReact.string("About Page is working"))</div>
  };
}

let reducer = (action, state) => 
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({...state, route: route })
  | PokemonsFetch => ReasonReact.UpdateWithSideEffects(
    {...state, fetching: Loading},
    (
      self => Js.Promise.(
        Fetch.fetch(getPokemons)
        |> then_(Fetch.Response.json)
        |> then_(json =>
          json
          |> Decode.pkmn
          |> pokemons => self.send(PokemonsFetched(pokemons))
          |> resolve
        )
        |> catch(_err => self.send(PokemonsFetchFailure) |> resolve)
        |> ignore
      )
    ),
  )
  | PokemonsFetched(pokemons) => ReasonReact.Update({...state, pokemons, fetching: Loaded })
  | PokemonsFetchFailure => ReasonReact.Update({...state, fetching: Error})
  };

let make = (_children) => {
...component,
initialState: () => {route: Home, fetching: Loading, pokemons: [||]},
didMount: self => {
  let watcherId = ReasonReact.Router.watchUrl(url => {
    switch url.path {
    | [] => self.send(ChangeRoute(Home))
    | ["about"] => self.send(ChangeRoute(About))
    | _ => ()
    };
  });
  self.onUnmount(() => ReasonReact.Router.unwatchUrl(watcherId));
  self.send(PokemonsFetch);
},
reducer,
render: self => {
  let body = renderBody(self.state);
  <div>
    <Header handleClick=handleClick/>
    body
  </div>
  }
};

