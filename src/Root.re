module Styles = {
open Css;
  let rootContainer = style([
    display(`flex),
    flexDirection(`column),
  ]);
};


type route = 
  | Home
  | About;

type action =
  | ChangeRoute(route);

type state = {
  route: route,
};

let component = ReasonReact.reducerComponent("Root");

let handleClick = (event) => {
  Js.log(event);
  if (! ReactEventRe.Mouse.defaultPrevented(event)) {
    ReactEventRe.Mouse.preventDefault(event);
    ReasonReact.Router.push("about")
  };
};

let reducer = (action, _state) => 
  switch action {
  | ChangeRoute(route) => ReasonReact.UpdateWithSideEffects({route: route}, (_self) => Js.log(action))
  };

let make = (_children) => {
...component,
initialState: () => {route: Home},
didMount: self => {
  let _watcherId = ReasonReact.Router.watchUrl(url => {
    switch url.path {
    | [] => self.send(ChangeRoute(Home))
    | ["about"] => self.send(ChangeRoute(About))
    | _ => Js.log("nothing")
    };
  });
},
reducer,
render: self => {
  let body =
    switch (self.state.route) {
    | Home => <Home />
    | About => <div>(ReasonReact.string("About Page is working"))</div>
  };
  <div>
    <Header />
    body
    <div>
      <a href="about" onClick=handleClick>(ReasonReact.string("About"))</a>
    </div>
  </div>
  }
};

