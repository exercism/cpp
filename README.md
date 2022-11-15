# Exercism C++ Track

Exercism Exercises in C++

## Contributing Guide

Please see the [contributing guides](https://github.com/exercism/docs/tree/main/building/github)

The most useful way to start contributing to this track is to review Pull Requests and/or some of the open track issues.
There are not many active contributors, so anyone reviewing PRs or Issues, even just to +1 someone elses opinion, is appreciated.

## Adding an exercise

Here is a list of things that need to be done to add an exercise to this track.

1. Add the exercise under the `exercises/` directory.
2. Create your test suite based on the canonical tests in the [problem specifications](https://github.com/exercism/problem-specifications) repo, and add a comment at the top of the test suite noting the version of the test suite it implements.
3. Create an example solution and name the files `example.cpp` and `example.h`. `example.cpp` is optional but encouraged.
4. Add the test to the list in the root CMakeLists.txt file.
5. Add the test to the config.json file. The [configlet](https://github.com/exercism/configlet) can help generate a unique UUID. You can download configlet using the script in `bin/fetch-configlet`.
6. Add at least one topic for the exercise in the config.json file. Check the available topics in [TOPICS.txt](https://github.com/exercism/problem-specifications/blob/master/TOPICS.txt).
7. Use the [configlet](https://github.com/exercism/configlet) tool to generate the README for your exercise.
8. Try to match the formatting used in the other tests as closely as possible.

## Testing an exercise

The Exercism build system has two unusual constraints. First, example solutions
must be named `example.h` and `example.cpp`; this prevents Exercism from sending
these files to the student. Second, student solutions must be named `<exercise>.h`
and `<exercise>.cpp`, for example `anagram.h` and `anagram.cpp`.

The current CMake build system navigates this with an unusual approach: it copies
all example solutions from the `exercises/` tree to an alternate directory
(which is ignored by git), renames the solutions as if they were student exercises,
and runs a complete build in this new directory.

Maintainers can largely ignore the alternate exercise directory if they recopy
their example solution before running a build. Re-running CMake will recopy
all exercise files.

For example, a maintainer can copy, configure, compile, and test all exercises by
running the following from the root directory:
```bash
cmake . && make
```

For an individual exercise, in this example `anagram`, the maintainer should edit:
```bash
exercises/anagram/example.h
exercises/anagram/example.cpp
exercises/anagram/anagram_test.cpp
```

Then copy, configure, compile, and test with:
```bash
cmake . && make test_anagram
```
