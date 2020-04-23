# How to implement a C++ concept exercise

This document describes how to implement a concept exercise for the C++ track.

**Please please please read the docs before starting.** Posting PRs without reading these docs will be a lot more frustrating for you during the review cycle, and exhaust Exercism's maintainers' time. So, before diving into the implementation, please read the following documents:

- [The features of v3][docs-features-of-v3].
- [Rationale for v3][docs-rationale-for-v3].
- [What are concept exercise and how they are structured?][docs-concept-exercises]

Please also watch the following video:

- [The Anatomy of a Concept Exercise][anatomy-of-a-concept-exercise].

As this document is generic, the following placeholders are used:

- `<SLUG>`: the name of the exercise in kebab-case (e.g. `anonymous-methods`).
- `<NAME>`: the name of the exercise in snake_case (e.g. `anonymous_methods`).

Before implementing the exercise, please make sure you have a good understanding of what the exercise should be teaching (and what not). This information can be found in the exercise's GitHub issue. Having done this, please read the [C++ concept exercises introduction][concept-exercises].

To implement a concept exercise, the following files must be added:

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
              │   ├── introduction.md
              |   └── source.md (required if there are third-party sources)
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

## Step 1: Add code files

The code files are track-specific and should be designed to help the student learn the exercise's concepts. The following C++ code files must be added (not necessarily in this order):

- `<NAME>.h` and `<NAME>.cpp`. the stub implementation files, which is the starting point for students to work on the exercise.
- `CMakeLists.txt`: the C++ project file.
- `<NAME>_test.cpp`: the test suite.
- `.meta/example.h` and `.meta/example.cpp`: an example implementation that passes all the tests.
- `test/tests_main.cpp`: generates test main from test library

## Step 2: Add documentation files

How to create the files common to all tracks is described in the [how to implement a concept exercise document][how-to-implement-a-concept-exercise].

## Step 3: Update list of implemented exercises

- Add the exercise to the [list of implemented exercises][implemented-exercises].

## Inspiration

When implementing this exercise, it can be very useful to look at [already implemented C++ exercises][implemented-exercises].

## Help

If you have any questions regarding implementing the exercise, please post them as comments in the exercise's GitHub issue.

[example-after-md]: https://github.com/exercism/v3/blob/master/languages/cpp/exercises/concept/strings/.docs/after.md
[implemented-exercises]: https://github.com/exercism/v3/blob/master/languages/cpp/exercises/concept/README.md#implemented-exercises
[meta-design]: https://github.com/exercism/v3/blob/master/languages/cpp/exercises/concept/strings/.meta/design.md
[meta-config-json]: https://github.com/exercism/v3/blob/master/languages/cpp/exercises/concept/strings/.meta/config.json
[docs-concept-exercises]: ../../../docs/concept-exercises.md
[docs-rationale-for-v3]: ../../../docs/rationale-for-v3.md
[docs-features-of-v3]: ../../../docs/features-of-v3.md
[anatomy-of-a-concept-exercise]: https://www.youtube.com/watch?v=gkbBqd7hPrA
[how-to-implement-a-concept-exercise]: ../../../docs/maintainers/generic-how-to-implement-a-concept-exercise.md
