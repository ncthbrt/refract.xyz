/* This is the basic component. */
module R = ReasonReact;

let component = R.statelessComponent("LandingPage");

let make = _children => {
  ...component,
  render: self =>
    R.array([|
      <div className="main-splash page">
        <div className="main-splash-content">
          <img className="main-logo" src="/RefractLogo.svg" />
          <h1> (R.string("REFRACT")) </h1>
          <h2>
            (R.string("A composable web framework"))
            <br />
            (R.string("for OCaml & ReasonML"))
          </h2>
        </div>
      </div>,
      <div className="page"> <h2> (R.string("WHY?")) </h2> </div>,
    |]),
};