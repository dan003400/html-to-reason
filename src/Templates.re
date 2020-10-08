open React;
let header =
  <div className="flex items-center justify-between p-6 mb-6 bg-white shadow">
    <div className="flex-1 min-w-0">
      <h2
        className="text-2xl font-bold text-gray-700 leading-7 sm:text-3xl sm:leading-9 sm:truncate">
        "HTML to Rescript"->string
      </h2>
    </div>
    <div className="text-sm text-gray-400">
      "Brought to you by  "->string
      <a
        href="https://mrmurphy.dev/" target="_blank" className="text-blue-400">
        "Murphy Randle"->string
      </a>
      " and "->string
      <a
        href="https://twitter.com/sgrove"
        target="_blank"
        className="text-blue-400">
        "Sean Grove"->string
      </a>
    </div>
  </div>;

let footer =
  <div className="p-6 py-6 text-xs text-gray-600 bg-gray-400">
    <div className="grid grid-cols-2 gap-4">
      <div>
        <h2 className="mb-2 text-lg font-semibold text-gray-700">
          "What this does"->string
        </h2>
        <ul>
          <li>
            "Fixes all reserved keywords, like 'class'=>'className='"->string
          </li>
          <li> "Converts attributes to CamelCase"->string </li>
          <li>
            "Decodes entities in text, then wraps it in quotes and ->string"
            ->string
          </li>
          <li> "Converts HTML comments to Rescript comments"->string </li>
          <li> "Closes self-closing attributes"->string </li>
          <li>
            "Converts 'style' attribute into "->string
            <code> "ReactDOMRe.make"->string </code>
            " calls"->string
          </li>
        </ul>
      </div>
      <div>
        <h2 className="mb-2 text-lg font-semibold text-gray-700">
          "Made Possible By"->string
        </h2>
        <ul>
          <li className="underline">
            <a href="https://feathericons.com/?query=copy" target="_blank">
              "Feather Icons"->string
            </a>
          </li>
          <li className="underline">
            <a href="https://nextjs.org/" target="_blank">
              "Next.js"->string
            </a>
          </li>
          <li className="underline">
            <a href="https://tailwindui.com" target="_blank">
              "Tailwind & Tailwind UI"->string
            </a>
          </li>
          <li className="underline">
            <a href="https://netlify.com/" target="_blank">
              "Netlify"->string
            </a>
          </li>
          <li className="underline">
            <a href="https://reasonml.github.io/reason-react/" target="_blank">
              "Reason React"->string
            </a>
          </li>
          <li className=""> "And many more, as I'm sure you know"->string </li>
        </ul>
      </div>
    </div>
  </div>;

let clipboard =
  <svg
    xmlns="http://www.w3.org/2000/svg"
    width="24"
    height="24"
    viewBox="0 0 24 24"
    fill="none"
    stroke="currentColor"
    strokeWidth="2"
    strokeLinecap="round"
    strokeLinejoin="round"
    className="stroke-current">
    <path
      d="M16 4h2a2 2 0 0 1 2 2v14a2 2 0 0 1-2 2H6a2 2 0 0 1-2-2V6a2 2 0 0 1 2-2h2"
    />
    <rect x="8" y="2" width="8" height="4" rx="1" ry="1" />
  </svg>;
