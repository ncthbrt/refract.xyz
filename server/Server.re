open Express;

let app = express();

let dName = [%bs.node __dirname] |. Belt.Option.getExn;

App.use(
  app,
  Express.Static.make(
    Node.Path.resolve(dName, "../build/"),
    Express.Static.defaultOptions(),
  )
  |. Express.Static.asMiddleware,
);

App.use(
  app,
  Express.Static.make(
    Node.Path.resolve(dName, "../static"),
    Express.Static.defaultOptions(),
  )
  |. Express.Static.asMiddleware,
);

App.get(app, ~path="/") @@
Middleware.from((_, _) =>
  Response.sendFile(Node.Path.resolve(dName, "../src/index.html"), ())
);

let onListen = e =>
  switch (e) {
  | exception (Js.Exn.Error(e)) =>
    Js.log(e);
    Node.Process.exit(1);
  | _ => Js.log @@ "Listening at http://127.0.0.1:3000"
  };

App.listen(app, ~port=3000, ~onListen, ());