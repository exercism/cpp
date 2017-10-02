# C++

[![Travis Build Status](https://api.travis-ci.org/exercism/cpp.svg?branch=master)](https://travis-ci.org/exercism/cpp)

Exercism Exercises in C++

## Contributing Guide

Please see the [contributing guide](https://github.com/exercism/docs/blob/master/contributing-to-language-tracks/README.md)

The most useful way to start contributing to this track is to review Pull Requests and/or some of the open track issues.
There are not many active contributors, so anyone reviewing PRs or Issues, even just to +1 someone elses opinion, is appreciated.

## Adding an exercise

Here is a list of things that need to be done to add an exercise to this track.

1. Add the exercise under the exercises/ directory.
2. Create your test suite based on the canonical tests in the [problem specifications](https://github.com/exercism/problem-specifications) repo.
3. Create an example solution and name the files 'example.cpp' and 'example.h'.
4. Add the test to the list in the root CMakeLists.txt file.
5. Add the test to the config.json file. The [configlet](https://github.com/exercism/configlet) can help generate a unique UUID.
6. Use the [configlet](https://github.com/exercism/configlet) tool to generate the README for your exercise.
7. Try to match the formatting used in the other tests as closely as possible.
