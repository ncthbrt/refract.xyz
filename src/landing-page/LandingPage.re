/* This is the basic component. */
module R = ReasonReact;

let component = R.statelessComponent("LandingPage");

let make = _children => {
  ...component,
  render: self =>
    R.array([|
      <div className="main-splash page">
        <div className="main-splash-nav">
          <div>
            <a href="https://github.com/ncthbrt/refract">
              (R.string("Github"))
            </a>
          </div>
          <div>
            <a href="https://github.com/ncthbrt/refract">
              (R.string("Reference"))
            </a>
          </div>
          <div>
            <a href="https://github.com/ncthbrt/refract">
              (R.string("Guides"))
            </a>
          </div>
        </div>
        <div className="main-splash-content">
          <img className="main-logo " src="/RefractLogo.svg" />
          <h1> <a href="/"> (R.string("REFRACT")) </a> </h1>
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