module Styles = {
  open Css;

  let container = style([
    height(px(70)),
    backgroundColor(hex("D34E37")),
    display(`flex),
    flexDirection(`row),
  ]);

  let name = style([
    fontSize(px(20)),
    color(white),
    display(`flex),
    alignItems(`center),
    justifyContent(`flexStart),
  ])

};

let component = ReasonReact.statelessComponent("Header");

let make = (_children) => {
...component,
render: _self =>
  (
    Styles.(
      <div className=container>
          <h3 className=name>(ReasonReact.string("ReasonMon"))</h3>
          <p>(ReasonReact.string("Menu"))</p>
      </div>
    )
  )
};
