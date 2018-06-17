module Styles = {
  open Css;

  let container = style([
    display(`flex),
    flex(1),
    justifyContent(`center),
  ]);
  let title = style([
    fontSize(rem(1.5)),
    color(red),
    marginBottom(px(10))
  ]);
};

let component = ReasonReact.statelessComponent("Home");

let reducer = (_action, _state) => ()

let make = (~pokemons, _children) => {
...component,
render: _self => {
  let body = (() => Js.log(pokemons))();
  Styles.(
      <div className=container>
        <h2 className=title> (ReasonReact.string("Home")) </h2>
      </div>
    )
  }
};
