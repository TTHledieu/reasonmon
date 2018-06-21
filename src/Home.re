module Styles = {
  open Css;

  let container = style([
    display(`flex),
    flexDirection(`column),
    justifyContent(`center),
    backgroundColor(hex("F5F6F7")),
  ]);
  let title = style([
    fontSize(rem(1.5)),
    color(red),
    marginBottom(px(10))
  ]);
  let top = style([
    display(`flex),
    flex(1),
  ]);
  let body = style([
    display(`flex),
    flex(9),
  ]);
};

type pokemon = {
  name: string,
  url: string,
};

let component = ReasonReact.statelessComponent("Home");

let reducer = (_action, _state) => ()

let make = (~pokemons: array(pokemon), _children) => {
...component,
render: _self => {
  let test = (() => {
    let pokemon = pokemons[0];
    Js.log(pokemon.name);
    Array.map(pokemon => Js.log(pokemon.name), pokemons);
  })();
  Styles.(
      <div className=container>
        <div className=top>
        (ReasonReact.string("Home"))
        </div>
        <div className=body>
        (ReasonReact.string("Home"))
        </div>
      </div>
    )
  }
};
