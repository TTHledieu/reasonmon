module Styles = {
  open Css;

  let hoverAnimation = keyframes([
    (0, [borderStyle(`dashed), width(px(280))]),
    (100, [borderStyle(`solid), width(px(300))]),
  ]);
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
    flexDirection(`column),
    alignItems(`center),
  ]);
  let pkmnItem = style([
    boxSizing(`borderBox),
    display(`inlineBlock),
    width(px(200)),
    margin(px(10)),
    borderColor(hex("048BA8")),
    color(hex("048BA8")),
    borderWidth(px(5)),
    textAlign(`center),
    borderStyle(`dashed),
    selector(":hover", [
      borderStyle(`solid),
      width(px(250)),
      animationName(hoverAnimation),
      animationDuration(200),
    ]),
  ]);
  let pkmnName = style([

  ]);
};

type pokemon = {
  name: string,
  url: string,
};

let renderItem = (pokemon: pokemon) => {
  let capitalisedName = String.capitalize(pokemon.name);
  <div key={pokemon.name} className=Styles.pkmnItem>
    <h3 className=Styles.pkmnName>
      (ReasonReact.string(capitalisedName))
    </h3>
  </div>
};

let component = ReasonReact.statelessComponent("Home");

let reducer = (_action, _state) => ()

let make = (~pokemons: array(pokemon), _children) => {
...component,
render: _self => {
  Styles.(
      <div className=container>
        <div className=top>
        (ReasonReact.string("Home"))
        </div>
        <div className=body>
          (
            Array.map(pokemon => renderItem(pokemon), pokemons)
            |> ReasonReact.array
          )
        </div>
      </div>
    )
  }
};
