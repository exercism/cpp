## Passing the Tests

Get the first test compiling, linking and passing.  Once you've done that,
uncomment the next test by moving the following line past the next test.

```C++
#if defined(EXERCISM_RUN_ALL_TESTS)
```

This may result in compile errors as new constructs may be invoked that
you haven't yet declared or defined.  Fix the compile errors minimally
to get a failing test, then change the code minimally to pass the test,
refactor your implementation for readability and expressiveness and then
go on to the next test.

Try to use standard C++11 facilities in preference to writing your own
low-level algorithms or facilities by hand.  [CppReference](http://en.cppreference.com/)
is a wiki reference to the C++ language and standard library.  If you
are new to C++, but have programmed in C, beware of
[C traps and pitfalls](http://www.slideshare.net/LegalizeAdulthood/c-traps-and-pitfalls-for-c-programmers).

## Building and Running the Tests

The C++ language track assumes that you have the appropriate development tools
installed on your system: a modern C++11 compiler, some sort of build
system and the Boost libraries.  MacOS Xcode and Windows Visual Studio
IDEs combine the compiler and the build system into a single IDE (integrated
development environment).  Linux environments typically expose the
compiler and build system as separate command-line tools.

### Prerequisite: Using a Modern C++11 Compiler

This language track assumes C++11, the latest version of the ISO C++ standard.
Free compilers exist for C++11 on all major platforms, although the version
of the C++ compiler installed on your system may be an older version that
doesn't fully support C++11.

Linux users will need gcc 4.8 or later or clang 3.4 or later for the compiler
and `make` will be needed for build engine.  Make is pre-installed on most
unix systems, but is available via `sudo apt-get install make` if not present.
Gcc 4.8 supports C++11 with the `-std=c++11` argument and can be installed and
set as the default compiler with the following recipe:

```bash
$ sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
$ sudo apt-get -qq -d update
$ sudo apt-get -qq install g++-4.8
$ sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90
```

Windows users can get
[Visual Studio Express 2013 for Windows Desktop](http://www.visualstudio.com/downloads/download-visual-studio-vs#d-express-windows-desktop),
a free download that will give you the Visual Studio 2013 IDE and the
latest version of the Microsoft Visual C++ compiler.

MacOS users can install gcc 4.8 with [Homebrew](http://brew.sh/) via
`brew install gcc`.

### Prerequisite: Installing Boost.Test

The unit tests use Boost.Test, the unit testing framework included with
[Boost](http://www.boost.org/index.html).  You will need to download and
install Boost.  As of this writing Boost 1.55 is the current version.
You will need a compiled version of the boost libraries Boost.Test,
Boost.DateTime and Boost.Regex, or you will need to download
from source and build the library yourself.

Linux users may be able to get pre-built packages with the following recipe:

```bash
$ sudo add-apt-repository -y ppa:boost-latest/ppa
$ sudo apt-get -qq -d update
$ sudo apt-get -qq install libboost1.55-all-dev
```

Note: These prepackaged Linux binaries are not compiled with gcc 4.8 and
some libraries may have issues as a result.  If you encounter any issues
with these prepackaged libraries, try building from source.

Windows users can download compiled binaries from [sourceforge](http://sourceforge.net/projects/boost/files/boost-binaries/1.55.0-build2/).

MacOS users can install boost with [Homebrew](http://brew.sh/) via
`brew install boost`.

If all else fails you can download the source and build it yourself,
but you should prefer a prebuilt distribution to make things easier.
Bootstrap instructions are on the
[Boost getting started page](http://www.boost.org/doc/libs/release/more/getting_started/index.html).

### Building the Exercises with CMake

Each test file is meant to link against your implementation to provide a
console executable that runs the tests.  The test executable prints messages
on failure and reports a non-zero exit status when tests fail.  A canned
CMake recipe is provided that builds the executable accordingly.
CMake 2.8.11 or later is required to use the recipe.
CMake is a [free download](http://www.cmake.org/).

Each exercise will bring a `CMakeLists.txt` file along with the unit
tests.  It contains the canned recipe to handle the build for you.
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
not being found.  These files can be empty, but they must exist.

Using this recipe, CMake can generate a suitable project for your environment
by running `cmake -G` with a suitable generator and the location of the
exercise specific directory.  Assuming the current directory is `bob`,
some examples are:
* Linux with make: `cmake -G "Unix Makefiles" .`
* Windows with Visual Studio 2013: `cmake -G "Visual Studio 12" .`
* MacOS with Xcode: `cmake -G Xcode`, or with make: `cmake -G "Unix Makefiles" .`

Once the build environment has been created by CMake, you can build your
code using the appropriate command for your environment:
* Linux with make: `make`
* Windows with Visual Studio 2013: Select Build / Build Solution from the menu.
* MacOS with Xcode: Select Build from the toolbar

### Boost.Test Documentation

The Boost.Test documentation is being rewritten and is nearly complete.
Prefer the documentation rewrite to look up something if you're unfamiliar
with Boost.Test and want to know more.
* [Boost.Test 1.55 official documentation](http://www.boost.org/doc/libs/1_55_0/libs/test/doc/html/index.html)
* [Boost.Test documentation rewrite](http://user.xmission.com/~legalize/boost.test/)
