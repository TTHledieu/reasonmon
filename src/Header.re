module Styles = {
  open Css;

  let container = style([
    height(px(70)),
    backgroundColor(hex("D34E37")),
    display(`flex),
    flexDirection(`row),
    alignItems(`center),
  ]);

  let nameContainer = style([
    display(`flex),
    flex(6),
  ]);
  let name = style([
    fontSize(px(20)),
    color(white),
    display(`flex),
    paddingLeft(px(20)),
  ]);
  
  let navContainer = style([
    display(`flex),
    flex(4),
  ]);
  let nav = style([
    fontSize(px(17)),
    fontWeight(500),
    color(white),
    display(`flex),
    paddingRight(px(10)),
  ]);

};

let component = ReasonReact.statelessComponent("Header");

let make = (~handleClick, _children) => {
  let click = (route, event, self) => {
    handleClick((route, event), self);
  };
  {
    ...component,
    render: self =>
    (
      Styles.(
        <div className=container>
          <div className=nameContainer>
            <h3 className=name>(ReasonReact.string("ReasonMon"))</h3>
          </div>
          <div className=navContainer>
            <a href="home" onClick=self.handle(click("home")) className=nav>(ReasonReact.string("Home"))</a>
            <a href="about" onClick=self.handle(click("about")) className=nav>(ReasonReact.string("About"))</a>
          </div>
        </div>
      )
    )
  }
};
