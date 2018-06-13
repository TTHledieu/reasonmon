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

let handleClick = (tuple, _self) => {
  let (route, event) = tuple;
  if (! ReactEventRe.Mouse.defaultPrevented(event)) {
    ReactEventRe.Mouse.preventDefault(event);
    ReasonReact.Router.push(route)
  };
};

let reducer = (action, _state) => 
  switch action {
  | ChangeRoute(route) => ReasonReact.Update({route: route})
  };

let make = (_children) => {
...component,
initialState: () => {route: Home},
didMount: self => {
  let _watcherId = ReasonReact.Router.watchUrl(url => {
    switch url.path {
    | [] => self.send(ChangeRoute(Home))
    | ["home"] => self.send(ChangeRoute(Home))
    | ["about"] => self.send(ChangeRoute(About))
    | _ => ()
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
    <Header handleClick=handleClick/>
    body
  </div>
  }
};

