[@bs.module]
external transform: (string, string, bool) => string = "./ast_operations.js";

let convert = (name, source, useTailwind) =>
  transform(name, source, useTailwind);
