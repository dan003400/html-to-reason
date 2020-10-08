open React;

let defaultText = {j|<div class="flex items-center w-full" style="font-weight: bolder">Hello there! Go on &amp; convert your html!</div>|j};

type state = {
  html: string,
  jsx: string,
};

type action =
  | UpdateHTML(string, bool);

let initialState = {
  html: defaultText,
  jsx: HtmlConverter.convert("__DEFAULT__", defaultText, false),
};

let reducer = (_state, action) =>
  switch (action) {
  | UpdateHTML(str, useTailwind) => {
      html: str,
      jsx: HtmlConverter.convert("_INLINE_", str, useTailwind),
    }
  };

[@bs.module] external copy_text: (~id: string) => unit = "../copy_text.js";
let copyOutput = () => {
  copy_text(~id="copyMe");
};

[@react.component]
let default = () => {
  let (state, dispatch) = React.useReducer(reducer, initialState);
  let (tailwind, setTailwind) = React.useState(_ => false);

  let tailwindClass = tailwind ? "bg-indigo-600" : "bg-gray-200";
  let switchClass = tailwind ? "translate-x-5" : "translate-x-0";

  React.useEffect1(
    () => {
      dispatch(UpdateHTML(state.html, tailwind));
      /* clean up the subscription */
      None;
    },
    [|tailwind|],
  );

  let view =
    <div className="flex flex-col w-screen h-screen bg-gray-200">
      Templates.header
      <div className="flex-1 w-full px-4 mx-auto mb-8 grid grid-cols-2 gap-4">
        <div
          id="input"
          className="overflow-hidden bg-white border-b-2 border-yellow-400 rounded-lg shadow shadow-lg">
          <div
            className="flex items-center px-3 py-4 text-yellow-600 bg-yellow-200 border-b-2 border-yellow-400 sm:px-6">
            <h1 className="flex-1 text-lg font-bold">
              "Paste HTML"->string
            </h1>
            <div className="mr-2"> "Tailwind PPX"->string </div>
            <span
              onClick={_ => setTailwind(_ => !tailwind)}
              role="checkbox"
              tabIndex=0
              className={j|relative inline-flex flex-shrink-0 h-7 bg-gray-200 border-2 border-transparent rounded-full
                cursor-pointer w-12 transition-colors ease-in-out duration-200 focus:outline-none focus:shadow-outline
                  $tailwindClass|j}>
              <span
                ariaHidden=true
                className={j|inline-block w-6 h-6 bg-white rounded-full shadow translate-x-0 transform transition
                    ease-in-out duration-200 $switchClass|j}
              />
            </span>
          </div>
          <div className="h-full p-1">
            <textarea
              placeholder={|<div class="placeholder">Paste something in here!</div>|}
              className="w-full h-full p-4 outline-none focus:shadow-outline"
              value={state.html}
              onChange={evt => {
                let v = evt->ReactEvent.Form.target##value;
                dispatch(UpdateHTML(v, tailwind));
              }}
            />
          </div>
        </div>
        <div
          id="output"
          className="overflow-hidden bg-white border-b-2 border-red-400 rounded-lg shadow shadow-lg">
          <div
            className="flex justify-between px-3 py-4 text-red-600 bg-red-200 border-b-2 border-red-400 sm:px-6">
            <h1 className="text-lg font-bold"> "Copy Rescript"->string </h1>
            <button onClick={_ => copyOutput()}> Templates.clipboard </button>
          </div>
          <div className="h-full p-1">
            <textarea
              readOnly=true
              id="copyMe"
              value={state.jsx}
              className="w-full h-full p-4 outline-none focus:shadow-outline"
            />
          </div>
        </div>
      </div>
      Templates.footer
    </div>;
  view;
};
