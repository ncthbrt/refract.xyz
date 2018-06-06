// Generated by BUCKLESCRIPT VERSION 3.1.5, PLEASE EDIT WITH CARE
'use strict';

var Path = require("path");
var Js_exn = require("bs-platform/lib/js/js_exn.js");
var Express = require("bs-express/src/Express.js");
var Process = require("process");
var Belt_Option = require("bs-platform/lib/js/belt_Option.js");
var Js_primitive = require("bs-platform/lib/js/js_primitive.js");

var app = Express.express(/* () */0);

var dName = Belt_Option.getExn(Js_primitive.undefined_to_opt(typeof (__dirname) === "undefined" ? undefined : (__dirname)));

Express.App[/* use */0](app, Express.Static[/* asMiddleware */4](Express.Static[/* make */3](Path.resolve(dName, "../build/"), Express.Static[/* defaultOptions */0](/* () */0))));

Express.App[/* use */0](app, Express.Static[/* asMiddleware */4](Express.Static[/* make */3](Path.resolve(dName, "../static"), Express.Static[/* defaultOptions */0](/* () */0))));

Express.App[/* get */4](app, "/", Express.Middleware[/* from */5]((function (_, _$1) {
            var partial_arg = Path.resolve(dName, "../src/index.html");
            var partial_arg$1 = Express.Response[/* sendFile */1];
            return (function (param) {
                return partial_arg$1(partial_arg, /* () */0, param);
              });
          })));

function onListen(e) {
  var exit = 0;
  var val;
  try {
    val = e;
    exit = 1;
  }
  catch (raw_exn){
    var exn = Js_exn.internalToOCamlException(raw_exn);
    if (exn[0] === Js_exn.$$Error) {
      console.log(exn[1]);
      Process.exit(1);
      return /* () */0;
    } else {
      throw exn;
    }
  }
  if (exit === 1) {
    console.log("Listening at http://127.0.0.1:3000");
    return /* () */0;
  }
  
}

Express.App[/* listen */19](app, /* Some */[3000], /* Some */[onListen], /* () */0);

exports.app = app;
exports.dName = dName;
exports.onListen = onListen;
/* app Not a pure module */
