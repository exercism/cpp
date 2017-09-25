Each exercise supplies the unit tests and a CMake build recipe.  You
provide the implementation.
Each test file is meant to link against your implementation to provide a
console executable that runs the tests.  Running the test executable
prints messages for each failing test and reports a non-zero exit status
when tests fail.

*Note:* Your code is being tested against the test suite every time you build your project. If your code does not pass the one or more tests but is valid C++ code, it will still be compiled.

Working through each exercise is a process of:

* Creating the initial build with CMake
* For each unit test:
 * Satisfy compile errors to make the test fail.
 * Implement just enough to make the test pass.
 * Refactor your implementation to enhance readability, reduce duplication, etc.
 * Uncomment the next test

### Creating the Initial Build with CMake

Each exercise will bring a `CMakeLists.txt` file along with the unit
tests.  It contains the canned CMake recipe to handle the build for you.
You should not need to edit this file.  The provided recipe assumes that
your implementation exists as a header file and a source file named after
the exercise.

For instance, the exercise `bob` expects an implementation in `bob.h`
and `bob.cpp`.  For exercises with dashes in their name, the source
files are assumed to use underscores, so `word-count` expects
`word_count.h` and `word_count.cpp`.  You may decide that your
impementation is sufficiently simple that it can live entirely in the
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

Since you will be running CMake to create the build instructions for each
assignment, you might want to create a bash script (Linux/MacOS) or
batch file (Windows) for this command.

Once the build environment has been created by CMake, you can build your
code using the appropriate command for your environment:

* Linux with make: `make`
* Windows with Visual Studio 2013: Select Build / Build Solution from the menu.
* MacOS with Xcode: Select Build from the toolbar

Examples of running CMake for different environments are shown below.

#### Linux\MacOS with Make

The generator name for CMake is `Unix Makefiles`.
Assuming the current exercise is `bob` and we're in the exercise folder:

```
$ touch bob.{h,cpp}
$ mkdir build
$ cd build
$ cmake -G "Unix Makefiles" ..
```

This example shows creating empty files for the implementation before
running CMake.

"Simply type make in the build directory to compile the tests. This should 
generate compile time errors. Once the errors are fixed make will build and 
run the tests."

#### Windows with Visual Studio 2013

The generator name for CMake is `Visual Studio 12`.  The same generator
supports all editions of Visual Studio 2013: Express, Professional,
Ultimate, etc.
Assuming the current exercise is `bob` and we're in the exercise folder:

```
> copy nul: bob.h
> copy nul: bob.cpp
> mkdir build
> cd build
> cmake -G "Visual Studio 12" ..
```

This example shows creating empty files for the implementation before
running CMake.

On Linux and MacOS boost packages install the headers and libraries to
a standard global location on the system.  On Windows, you unpack the
binaries wherever you like or build from source wherever you like and
there is no standard install location on the system.

If you get complaints from CMake about not being able to find Boost, you
need to supply additional arguments to tell CMake where to find it by
setting the `BOOST_INCLUDEDIR` variable on the command-line.  Here is an
example using the Visual Studio 2013 generator:

```
> cmake -G "Visual Studio 12" -DBOOST_INCLUDEDIR:PATH=D:/Code/boost/boost_1_59_0 ..
```

**Note:** Path locations passed to CMake always use slash (`/`) as the
directory separator, even on Windows.

#### MacOS with Xcode

The generator name for CMake is `Xcode`.
Assuming the current exercise is `bob` and we're in the exercise folder:

```
$ touch bob.{h,cpp}
$ mkdir build
$ cd build
$ cmake -G Xcode ..
```

This example shows creating empty files for the implementation before
running CMake.

## Boost.Test Documentation

The Boost.Test documentation is being rewritten to improve usability
and is nearly complete.
Prefer the documentation rewrite to look up something if you're unfamiliar
with Boost.Test and want to know more.

* [Boost.Test documentation rewrite](http://user.xmission.com/~legalize/boost.test/)
* [Boost.Test 1.55 official documentation](http://www.boost.org/doc/libs/1_55_0/libs/test/doc/html/index.html)
