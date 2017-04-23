## Prerequisites

The C++ language track requires that you have the following software
installed on your system:
* a modern C++11 compiler
* the CMake cross-platform build system
* the Boost libraries

Microsoft's Visual Studio IDE and Apple's Xcode IDEs combine the compiler
and the
native build system into a single IDE (integrated development environment).
Linux environments typically expose the compiler and native build system
as separate command-line tools.

### Prerequisite: A Modern C++11 Compiler

This language track assumes [C++11](http://en.wikipedia.org/wiki/C%2B%2B11),
the latest version of the ISO C++ standard that is
[widely supported](http://en.cppreference.com/w/cpp/compiler_support) on all
major platforms (Linux, Windows and MacOS).
[C++14](http://en.wikipedia.org/wiki/C%2B%2B14) has been recently ratified
as the most recent version of the ISO standard.  The language track will
be updated to C++14 once support is sufficiently mature in the development
environments across all major platforms.

Free compilers exist for C++11 on all major platforms, although the version
of the C++ compiler installed on your system may be an older version that
doesn't fully support C++11.  A comparison chart of
[C++ compiler support](http://en.cppreference.com/w/cpp/compiler_support)
and related [discussion](http://en.cppreference.com/w/Talk:cpp/compiler_support)
shows that most of the major features of C++11 are available on all major
platforms.

#### Linux

Linux users will need gcc 4.8 or later or clang 3.4 or later for the compiler
and `make` will be needed for the native build.  Make is pre-installed on most
unix systems, but is available via `sudo apt-get install make` if not present.
Gcc 4.8 supports C++11 with the `-std=c++11` argument and can be installed and
set as the default compiler with the following recipe:

```bash
$ sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
$ sudo apt-get -qq -d update
$ sudo apt-get -qq install g++-4.8
$ # make g++ 4.8 the default g++ executable
$ sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 90
```

#### MacOS

MacOS users can install gcc 4.8 with [Homebrew](http://brew.sh/) via
`brew install gcc`.

#### Windows

Windows users can get
[Visual Studio Community](https://www.visualstudio.com/vs/community/),
a free download that will give you the Visual Studio IDE and the
latest version of the Microsoft Visual C++ compiler.

### Prerequisite: CMake

CMake is an open source cross-platform build system that generates build
scripts for your native build system (`make`, Visual Studio, Xcode, etc.).
Exercism's C++ track uses CMake to give you a ready-made build that:

* compiles the tests
* compiles your solution
* links the test executable
* automatically runs the tests as part of every build
* fails the build if the any tests fail

Using CMake allows exercism to provide a cross-platform build script that
can generate project files for integrated development environments like
Visual Studio and Xcode.  This allows you to focus on the problem and
not worry about setting up a build for each exercise.

Getting a portable build isn't easy and requires access to many kinds of
systems.  If you encounter any problems with the supplied CMake recipe,
please [report the issue](https://github.com/exercism/xcpp/issues) so we can
improve the CMake support.

[CMake 2.8.11 or later](http://www.cmake.org/) is required to use the provided build recipe.

### Prerequisite: Boost 1.59+

The unit tests use Boost.Test, the unit testing framework included with
[Boost](http://www.boost.org/index.html).  You may find other libraries
in Boost useful to you as you work through the exercises.  In particular,
gcc 4.8 does not have a proper implementation of the standard regular
expression library, but you can find a compatible library in Boost.
You will need to download and install Boost.  As of this writing Boost
1.59+ is the required version.  You will need a compiled version of the
boost libraries Boost.Test, Boost.DateTime and Boost.Regex, or you will
need to download from source and build the library yourself.

If you are having difficulties installing Boost for use with exercism,
[ask for help](https://github.com/exercism/xcpp/issues).

#### Linux

Linux users can usually get Boost from your distribution's package manager.
If a pre-built package is unavailable for your linux distribution, try
[installing Boost from source](http://www.boost.org/doc/libs/release/more/getting_started/index.html).

Alternately, there may be some other way to install Boost for your
distribution without installing from source. For example, you can install
Boost 1.60 for Ubuntu 16.04 LTS by using a PPA.

```
$ sudo add-apt-repository -y ppa:samuel-bachmann/boost
$ sudo apt-get install boost1.60
```

#### Windows

Windows users can download compiled binaries from [sourceforge](https://sourceforge.net/projects/boost/files/boost-binaries/).
You must download the version appropriate for your compiler. Note that
the version number is different from your Visual Studio version; the
compiler version in Visual Studio 2015 is MSVC 14.0.

In the descriptions, 32-bit refers to the kind of code generated by your
compiler and not the operating system.  Code compiled for 32-bit will run
on both 32-bit and 64-bit versions of Windows.  Code compiled for 64-bit
will only run on 64-bit versions of Windows.  The CMake recipes used in
exercism create 32-bit projects for Visual Studio, so download the
appropriate 32-bit version of Boost.

Once you download the compiled binaries, install them into a suitable
location.  The installed location will contain a libraries directory
named similarly to the install executable, such as `lib32-msvc-12.0`.
Rename this directory to `lib` so that CMake can find the precompiled
libraries.  If you don't rename the directory you will see an error
like this when you run CMake:

```
> cmake -DBOOST_INCLUDEDIR:PATH=D:/tmp/boost_1_59_0 ..
-- Building for: Visual Studio 12
-- The CXX compiler identification is MSVC 18.0.30723.0
-- Check for working CXX compiler using: Visual Studio 12
-- Check for working CXX compiler using: Visual Studio 12 -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
CMake Error at C:/Program Files (x86)/CMake 2.8/share/cmake-2.8/Modules/FindBoost.cmake:1106 (message):
  Unable to find the requested Boost libraries.

  Boost version: 1.59.0

  Boost include path: D:/tmp/boost_1_59_0

  The following Boost libraries could not be found:

          boost_unit_test_framework
          boost_date_time
          boost_regex

  No Boost libraries were found.  You may need to set BOOST_LIBRARYDIR to the
  directory containing Boost libraries or BOOST_ROOT to the location of
  Boost.
Call Stack (most recent call first):
  CMakeLists.txt:12 (find_package)


-- Configuring incomplete, errors occurred!
```

#### MacOS

MacOS users can install boost with [Homebrew](http://brew.sh/) via
`brew install boost`.

#### Building from Source

If all else fails you can download the source and build it yourself,
but you should prefer a prebuilt distribution to make things easier.
Bootstrap instructions are on the
[Boost getting started page](http://www.boost.org/doc/libs/release/more/getting_started/index.html).

