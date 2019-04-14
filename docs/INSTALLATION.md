## Prerequisites

The C++ language track requires that you have the following software
installed on your system:
* a modern C++11 compiler
* the CMake cross-platform build system

We use [Catch2](https://github.com/catchorg/Catch2) for testing, which is a
header-only library that is bundled along with the exercises.

This set of dependencies is very common for C++ projects, so if you have any
issues setting it up you will find many helpful resources online.

Many IDE's, including Microsoft's Visual Studio, Apple's Xcode, and Jetbrain's
Clion bundle a compiler and CMake together, so you should only need to install
the IDE. 

### A Modern C++11 Compiler

This language track requires a compiler with [C++11](http://en.wikipedia.org/wiki/C%2B%2B11)
support, which was released in 2011. All major compilers released in the last few years should
be compatible, so as long as you are on a fairly recent version you should be fine.
Specifically, GCC version 5.1 or later, Clang version 3.8 or later, or Visual
Studio 2015 or later.

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

[CMake 3.1.3 or later](http://www.cmake.org/) is required to use the provided build recipe.

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

You should be able to use other integrated IDE's such as Jetbrain's Clion in a similar manner.

## Linux

Ubuntu 16.04 and later have compatible compilers in the package manager, so
installing the necessary compiler can be done with `sudo apt-get install gcc`.
If you're on an older version of Ubuntu, you should be able to install a newer
GCC version using the following:

```bash
$ sudo add-apt-repository -y ppa:ubuntu-toolchain-r/test
$ sudo apt-get -qq -d update
$ sudo apt-get -qq install g++-5
$ # make g++ 5 the default g++ executable
$ sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-5 90
```

For other distributions, you should be able to acquire the compiler through your
package manager.

## MacOS

MacOS users can install GCC with [Homebrew](http://brew.sh/) via
`brew install gcc`.

