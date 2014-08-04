## Passing the Tests

Get the first test compiling, linking and passing.  Once you've done that,
uncomment the next test by moving the line `#if defined(EXERCISM_RUN_ALL_TESTS)`
past the next test.
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

### Using a Modern C++ Compiler

This language track assumes C++11, the latest version of the ISO C++ standard.
Free compilers exist for C++11 on all major platforms, although the version
of the C++ compiler installed on your system may be an older version that
doesn't fully support C++11.

Unix users will need gcc 4.8 or later or clang 3.4 or later for the compiler
and `make` will be needed for build engine.  Make is pre-installed on most
unix systems, but is available via `sudo apt-get install make` if not present.
Gcc 4.8 supports C++11 with the `-std=c++11` argument can be obtained and
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
latest version of the Microsoft Visual C++ compiler.  The CMake generator
name for this environment is `Visual Studio 12`.

MacOS users can install gcc 4.8 with [Homebrew](http://brew.sh/) via
`brew install gcc48`.

### Installing Boost.Test

The unit tests use Boost.Test, the unit testing framework included with
[Boost](http://www.boost.org/index.html).  You will need to download and
install Boost.  As of this writing Boost 1.55 is the current version.
Instructions are on their
[getting started page](http://www.boost.org/doc/libs/release/more/getting_started/index.html).
You will need a compiled version of the boost libraries Boost.Test,
Boost.DateTime and Boost.Regex, or you will need to download
from source and build the library yourself.

Unix users may be able to get pre-built packages with the following recipe:

```bash
$ sudo add-apt-repository -y ppa:boost-latest/ppa
$ sudo apt-get -qq -d update
$ sudo apt-get -qq install libboost1.55-all-dev
```

Windows users can download compiled binaries from [sourceforge](http://sourceforge.net/projects/boost/files/boost-binaries/1.55.0-build2/).

MacOS users can install boost with [Homebrew](http://brew.sh/) via
`brew install boost`.

### Building the Exercise with CMake

Each test file is meant to link against your implementation to provide a
console executable that runs the tests.  The test executable prints messages
on failure and reports a non-zero exit status when tests fail.

CMake is recommended to simplify the procedure for any environment and is
a [free download](http://www.cmake.org/).
The solutions to the exercises were developed with the following CMake recipe in the
`cpp` directory.  The recipe compiles and links the test executable and
runs it as part of the build.  This makes failing tests fail the build.  In
the following recipe, the `BOOST_INCLUDEDIR` variable tells CMake where it
can find your Boost distribution.  You will need to edit this variable
value to the appropriate location on your system.

```
# cpp/CMakeLists.txt
cmake_minimum_required(VERSION 2.8.11)
project(exercism CXX)

# TODO: a hint to the location of the Boost distribution on your system
# CMake may be able to locate your boost distribution without this.
set(BOOST_INCLUDEDIR D:/Code/boost/boost_1_55_0)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)

find_package(Boost 1.55 REQUIRED COMPONENTS unit_test_framework date_time regex)

function(exercism exe)
    string(REPLACE "-" "_" file ${exe})
    if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file}.cpp)
        set(exercise_cpp ${file}.cpp)
    else()
        set(exercise_cpp "")
    endif()
    add_executable(${exe} ${file}_test.cpp ${exercise_cpp} ${file}.h)
    target_include_directories(${exe} PRIVATE ${Boost_INCLUDE_DIRS})
    target_link_libraries(${exe} ${Boost_LIBRARIES})
    add_custom_command(TARGET ${exe} POST_BUILD COMMAND ${exe})
endfunction()

foreach(exercise
# TODO: add the name of each exercise subdirectory here as you progress
    bob
)
    add_subdirectory(${exercise})
endforeach()
```

Each exercise subdirectory has a `CMakeLists.txt` that invokes the `exercism`
function defined at the top-level:

```
# cpp/bob/CMakeLists.txt
exercism(bob)
```

This function combines *exercise*`.h`, *exercise*`.cpp` and *exercise*`_test.cpp`
where *exercise* is the name given to the `exercism()` CMake function.  If your
implementation is header-only, simply omit the *exercise*`.cpp` file, the CMake
recipe above will only include it in the build if the file exists.

Using this recipe, CMake can generate a suitable project for your environment
by running `cmake -G` with a suitable generator.  Examples are:
* Windows with Visual Studio 2013: `cmake -G "Visual Studio 12"`
* MacOS with Xcode: `cmake -G Xcode`, or with make: `cmake -G "Unix Makefiles"`
* Unix with make: `cmake -G "Unix Makefiles"`

### Boost.Test Documentation

The Boost.Test documentation is being rewritten and is nearly complete.
Prefer the documentation rewrite to look up something if you're unfamiliar
with Boost.Test and want to know more.
* [Boost.Test 1.55 official documentation](http://www.boost.org/doc/libs/1_55_0/libs/test/doc/html/index.html)
* [Boost.Test documentation rewrite](http://user.xmission.com/~legalize/boost.test/)
