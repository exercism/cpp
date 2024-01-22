# Practice exercise creation helper

This folder contains `exercise_creation_helper.py`.
It expects a current version of the `configlet` tool in the same directory.

To generate the folder structure and a test scaffolding for an exercise, it can be called via: `$ exercise_creation_helper.py all-your-base vaeng`.
It takes a kebab-case slug name like `allergies` and the github name of the author and will populate the exercise directory in `exercises/practice/allergies` with the files from `bin/exercise_template_files`.

## Test generation

The script will generate a test for every uuid that is listed in the .toml file according to the principles described in the [github-wiki][github-wiki].

### In-directory testing

Optionally it also takes the `--testing-folder` option.
This will create a subfolder in the practice-exercises' directory that is ready to be used with cmake, without polluting the source control tracked, as it will also create a `.gitignore` file.

When the tests and the the exercise are satisfactory, the files can then copied to the tracked example files. That are checked with github actions after pushing.

#### Resulting Folder structure

```text
.
  |-.meta
  |  |-config.json
  |  |-example.cpp
  |  |-example.h
  |  |-tests.toml
  |-allergies.cpp
  |-.docs
  |  |-instructions.md
  |  |-instructions.append.md
  |-allergies_test.cpp
  |-test
  |  |-catch.hpp
  |  |-tests-main.cpp
  |-CMakeLists.txt
  |-allergies // <--- Optional subdirectory for in-folder testing
  |  |-allergies.cpp
  |  |-allergies_test.cpp
  |  |-test
  |  |  |-catch.hpp
  |  |  |-tests-main.cpp
  |  |-CMakeLists.txt
  |  |-allergies.h
  |-allergies.h
  |-.gitignore
```

[github-wiki]: https://github.com/exercism/cpp/wiki/Test-Cases-for-Practice-Exercises
