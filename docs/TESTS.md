# Tests

Each exercise supplies the unit tests and a CMake build recipe.  You
provide the implementation.
Each test file is meant to link against your implementation to provide a
console executable that runs the tests.  Running the test executable
prints messages for each failing test and reports a non-zero exit status
when tests fail.

*Note:* Your code is being tested against the test suite every time you build
your project. If your code does not pass the one or more tests but is valid C++
code, it will still be compiled.

Working through each exercise is a process of:

* Creating the initial build with CMake
* For each unit test:
  * Satisfy compile errors to make the test fail.
  * Implement just enough to make the test pass.
  * Refactor your implementation to enhance readability, reduce duplication, etc.
  * Uncomment the next test

## Creating the Initial Build with CMake

Each exercise will bring a `CMakeLists.txt` file along with the unit
tests.  It contains the canned CMake recipe to handle the build for you.
You should not need to edit this file.  The provided recipe assumes that
your implementation exists as a header file and a source file named after
the exercise.

For instance, the exercise `bob` expects an implementation in `bob.h`
and `bob.cpp`.  For exercises with dashes in their name, the source
files are assumed to use underscores, so `word-count` expects
`word_count.h` and `word_count.cpp`.  You may decide that your
implementation is sufficiently simple that it can live entirely in the
header, in which case you can omit the `cpp` file.

**Create your initial implementation files before running CMake.**  If
you do not have files `bob.h` and `bob.cpp` when running
CMake for exercise `bob`, then CMake will generate an error about files
not being found.  **These files can be empty, but they must exist.**

Using this recipe, CMake can generate a suitable project for your environment
by running `cmake -G` with a suitable generator and the location of the
directory for the exercise.  CMake will generate a build script appropriate
for your operating system.  To keep those generated files separate from
your exercise source code, it is common to create a directory called `build`
to hold these generated build files, as well as the compiled code.  This
will keep your exercise folder uncluttered and tidy.

Once the build environment has been created by CMake, you can build your
code using the appropriate command for your environment:

* Linux with make: `make`
* Windows with Visual Studio: Select Build / Build Solution from the menu.
* MacOS with Xcode: Select Build from the toolbar
* MacOS with "Unix Makefile": `make` _If using the exercism CLI app_

Examples of running CMake for different environments are shown below.

### Linux with Make

The generator name for CMake is `Unix Makefiles`.
Assuming the current exercise is `bob` and we're in the exercise folder:

```sh
$ touch bob.{h,cpp}
$ mkdir build
$ cd build
$ cmake -G "Unix Makefiles" ..
$ make
```

This example shows creating empty files for the implementation before
running CMake.

Simply type `make` in the build directory to compile the tests. This should
generate compile time errors. Once the errors are fixed, `make` will build and
run the tests.

### Windows with Visual Studio

Visual Studio has native support for CMake projects, so you should not need to
install CMake separately or run it outside of Visual Studio. Follow
[this guide](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio)
to setup the CMake project in Visual Studio.

### MacOS with Xcode

The generator name for CMake is `Xcode`.
Assuming the current exercise is `bob` and we're in the exercise folder:

```sh
$ touch bob.{h,cpp}
$ mkdir build
$ cd build
$ cmake -G Xcode ..
```

This example generates the XCode files so that you can open the project in XCode.
With the project opened in XCode you may need to add another target.
For a new target go to File -> New -> Target from the menu, _OS X \ Application \ Command Line Tool_ -> Next _C++_ as the language and provide a target name. Run the code using the target.

If your terminal throws an `Xcode x.x not supported` error, it is highly likely that Xcode is not installed on your machine or that your version is out of date.
Please download and install Xcode via the App Store or via [this link][web-xcode-download].
Errors similar to `The CXX compiler identification is unknown` will likely be resolved by following the [instructions to install GCC][cpp-installation-instructions] or by adding another target in Xcode as per the above paragraph.

[web-xcode-download]: https://apps.apple.com/us/app/xcode/id497799835?mt=12
[cpp-installation-instructions]: https://exercism.org/docs/tracks/cpp/installation

### MacOS with Make _when using the Exercism CLI_
#### This example specifically assists those who want to use the Exercism CLI app for configuring, testing, and submitting their C++ exercises.

The generator name for CMake is `Unix Makefiles`.
Assuming the current exercise is `bob` and we're in the exercise folder:

```sh
$ touch bob.{h,cpp}
$ cmake -G "Unix Makefiles" .
$ exercism test
```

In this example, we do create empty files for the implementation before running CMake, but we do **not** create an empty build directory.
This is because the Exercism CLI uses the `.exercism/metadata.json` file in the root directory to parse the test cases.

Simply type `exercism test` in the root directory to compile the tests. This should generate compile-time errors.
Once the errors are fixed, running `exercism test` again will build and execute the tests using the Exercism CLI.

[cpp-installation-instructions]: https://exercism.org/docs/tracks/cpp/installation
