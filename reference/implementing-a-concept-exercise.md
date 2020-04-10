# How to implement a C++ concept exercise

This document describes how to implement a concept exercise for the C++ track.

**Please please please read the docs before starting.** Posting PRs without reading these docs will be a lot more frustrating for you during the review cycle, and exhaust Exercism's maintainers' time. So, before diving into the implementation, please read the following documents:

- [The features of v3][docs-features-of-v3].
- [Rationale for v3][docs-rationale-for-v3].
- [What are concept exercise and how they are structured?][docs-concept-exercises]

As this document is generic, the following placeholders are used:

- `<SLUG>`: the name of the exercise in kebab-case (e.g. `anonymous-methods`).
- `<NAME>`: the name of the exercise in snake_case (e.g. `anonymous_methods`).

Before implementing the exercise, please make sure you have a good understanding of what the exercise should be teaching (and what not). This information can be found in the exercise's GitHub issue. Having done this, please read the [C++ concept exercises introduction][concept-exercises].

To implement a concept exercise, the following files must be created:

<pre>
languages
└── cpp
    └── exercises
        └── concept
            └── &lt;SLUG&gt;
              ├── .docs
              │   ├── after.md
              │   ├── hints.md
              │   ├── instructions.md
              │   └── introduction.md
              ├── .meta
              |   |── config.json
              │   ├── design.md
              │   ├── example.cpp
              │   └── example.h
              ├── CMakeLists.txt
              ├── &lt;NAME&gt;.cpp
              ├── &lt;NAME&gt;.h
              ├── &lt;NAME&gt;_test.cpp
              └── test
                  └── tests_main.cpp
</pre>

## Step 1: add .docs/introduction.md

This file contains an introduction to the concept. It should make the exercise's learning goals explicit and provide a short introduction with enough detail for the student to complete the exercise. The aim is to give the student just enough context to figure out the solution themselves, as research has shown that self-discovery is the most effective learning experience. Using the proper technical terms in the descriptions will be helpful if the student wants to search for more information. If the exercise introduces new syntax, an example of the syntax should always be included; students should not need to search the web for examples of syntax.

As an example, the introduction to a "strings" exercise might describe a string as just a "Sequence of Unicode characters" or a "series of bytes". Unless the student needs to understand more nuanced details in order to solve the exercise, this type of brief explanation (along with an example of its syntax) should be sufficient information for the student to solve the exercise.

## Step 2: add .docs/instructions.md

This file contains instructions for the exercise. It should explicitly explain what the student needs to do (define a method with the signature `X(...)` that takes an A and returns a Z), and provide at least one example usage of that function. If there are multiple tasks within the exercise, it should provide an example of each.

## Step 3: add .docs/hints.md

If the student gets stuck, we will allow them to click a button requesting a hint, which shows this file. This will not be a "recommended" path and we will (softly) discourage them using it unless they can't progress without it. As such, it's worth considering that the student reading it will be a little confused/overwhelmed and maybe frustrated.

The file should contain both general and task-specific "hints". These hints should be enough to unblock almost any student. They might link to the docs of the functions that need to be used.

The hints should not spell out the solution, but instead point to a resource describing the solution (e.g. linking to documentation for the function to use).

## Step 4: add .docs/after.md

Once the student completes the exercise they will be shown this file, which should provide them with a summary of what the exercise aimed to teach. This document can also link to any additional resources that might be interesting to the student in the context of the exercise.

See the C++ strings exercise's [after.md][example-after-md] file for an example.

## Step 5: update languages/cpp/config.json

An entry should be added to the track's `config.json` file for the new concept exercise:

```json
{
  ...
  "exercises": {
    "concept": [
      ...
      {
        "slug": "<SLUG>",
        "uuid": "<UUID>",
        "concepts": ["<CONCEPT-1>"],
        "prerequisites": ["<PREREQUISITE-1>", "<PREREQUISITE-2>"]
      }
    ]
  }
}
```

## Step 6: adding track-specific files

These files are specific to the C++ track:

- `<NAME>.h` and `<NAME>.cpp`. the stub implementation files, which is the starting point for students to work on the exercise.
- `CMakeLists.txt`: the C++ project file.
- `<NAME>_test.cpp`: the test suite.
- `.meta/example.h` and `.meta/example.cpp`: an example implementation that passes all the tests.
- `test/tests_main.cpp`: generates test main from test library

## Step 7: updating list of implemented exercises

- Add the exercise to the [list of implemented exercises][implemented-exercises].

## Step 8: add .meta/design.md:

This file contains information on the exercise's design, which includes things like its goal, its teaching goals, what not to teach, and more ([example][meta-design]). This information can be extracted from the exercise's corresponding GitHub issue.

## Step 9: add .meta/config.json:

This file contains meta information on the exercise, which currently only includes the exercise's contributors ([example][meta-config-json]).

## Inspiration

When implementing this exercise, it can be very useful to look at [already implemented C++ exercises][implemented-exercises].

## Help

If you have any questions regarding implementing the exercise, please post them as comments in the exercise's GitHub issue.

[example-after-md]: https://github.com/exercism/v3/blob/master/languages/cpp/exercises/concept/strings/.docs/after.md
[implemented-exercises]: https://github.com/exercism/v3/blob/master/languages/cpp/exercises/concept/README.md
[meta-design]: https://github.com/exercism/v3/blob/master/languages/cpp/exercises/concept/strings/.meta/design.md
[meta-config-json]: https://github.com/exercism/v3/blob/master/languages/cpp/exercises/concept/strings/.meta/config.json
[docs-concept-exercises]: ../../../docs/concept-exercises.md
[docs-rationale-for-v3]: ../../../docs/rationale-for-v3.md
[docs-features-of-v3]: ../../../docs/features-of-v3.md
