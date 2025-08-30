# Installation

## Prerequisites

The C++ language track requires that you have the following software
installed on your system:
* a modern C++14 compiler
* the CMake cross-platform build system

We use [Catch2](https://github.com/catchorg/Catch2) for testing, which is a
header-only library that is bundled along with the exercises.

This set of dependencies is very common for C++ projects, so if you have any
issues setting it up you will find many helpful resources online.

Many IDE's, including Microsoft's Visual Studio, Apple's Xcode, and JetBrains'
CLion bundle a compiler and CMake together, so you should only need to install
the IDE.

### A Modern C++14 Compiler

This language track requires a compiler with [C++14](http://en.wikipedia.org/wiki/C%2B%2B14)
support, which was released in 2014. All major compilers released in the last few years should
be compatible, so as long as you are on a fairly recent version you should be fine.
Specifically, GCC version 7 or later, Clang version 6 or later, or Visual
Studio 2017 or later.

### CMake

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
please [report the issue](https://github.com/exercism/cpp/issues) so we can
improve the CMake support.

[CMake 3.5.1 or later](http://www.cmake.org/) is required to use the provided build recipe.

## Windows

Windows users can get
[Visual Studio Community](https://www.visualstudio.com/vs/community/),
a free download that will give you the Visual Studio IDE and the latest version
of the Microsoft Visual C++ compiler.

1. Follow [the instructions here](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio) to setup CMake.
1. Download the exercise using the [exercism cli](https://exercism.io/cli-walkthrough) tool.
1. Open Visual Studio 2017 or higher (With Visual C++ tools for CMake installed as described from the link above).
1. Open the exercise folder in VS.
1. Run "Build->Build the solution". The tests will execute with the build, with the output going to the build window. Since the test runs during the build, VS will say it is a build failure if one of the tests fail, and the test failure messages will be in the build output window.

You should be able to use other integrated IDE's such as JetBrains' CLion in a similar manner.

### Installing Boost on Windows

The `meetup` and `gigasecond` exercises depend on the [Boost][boost-website] libraries.
The following steps describe how to set that up.

1. Download the [prebuilt windows libraries][sourceforge-boost-binaries] for Boost.
   - The exercises require a minimum Boost version of 1.58.
   - You can find the version of MSVC by clicking "Modify" in the Visual Studio Installer.
1. Extract the libraries to a local folder.
1. Set the `BOOST_ROOT` environment variable to the folder where you installed the Boost libraries.
1. If you had Visual Studio open while doing this, close it to make sure the value of `BOOST_ROOT` gets picked up.
1. Start Visual Studio and open the folder containing the `gigasecond` or `meetup` exercise.
1. The "Startup Item" should be `gigasecond.exe` or `meetup.exe` and you should get build errors in either `gigasecond_test.cpp` or `meetup_test.cpp` telling you to implement missing items, similar to the other exercises.

## Linux

All recent Linux distribution releases have compatible C++14 compilers, you
should be able to install it using your package manager. The versions we support
are the default installed versions in Ubuntu LTS 18.04.

For example, on Ubuntu you would use the following command to install gcc.

```bash
$ sudo apt-get install gcc
$ gcc --version
```

If you are on an older distribution, you might not have a compiler that
supports C++14. If that's the case, you'll need to work with your distribution
to figure out how to install the minimum compiler version.

## MacOS

MacOS users can install GCC with [Homebrew](http://brew.sh/) via
`brew install gcc`.



[boost-website]: https://www.boost.org/
[sourceforge-boost-binaries]: https://sourceforge.net/projects/boost/files/boost-binaries/
