[%bs.raw {|require('./App.css')|}];

[@bs.module] external logo : string = "./logo.svg";

/* let double = (x) => x * 2;
let square = (x) => x * x;
let doubleThenSquare = ((x) => double(x) |> (d => square(d)) |> (s => Js.log(s)))(5); */

module Styles = {
  open Css;

  let title = style([
    fontSize(rem(1.5)),
    color(red),
    marginBottom(px(10))
  ]);
};

let component = ReasonReact.statelessComponent("Home");

let reducer = (_action, _state) => ()

let make = (_children) => {
...component,
render: _self =>
  (
    Styles.(
      <div>
        <h2 className=title> (ReasonReact.string("Home")) </h2>
      </div>
    )
  )
};
