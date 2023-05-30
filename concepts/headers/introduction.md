# Introduction

In C++ declarations are often separated from definitions.
Declarations are grouped into so-called header files and the respective implementation is placed in source files.
You can think of the header files as an API.
The header file will tell you what a codebase has to offer without going into the details of how.

## Header and Source

The most common file extension for header files is `.h`.
Some projects use `.hpp` or skip the extension completely.

The definitions are located in a separate `.cpp` file. 
To reunite both parts, this source file starts by including the respective header file.

If you want to write a library called "myLib", that offers a function "my_func" that returns your favorite number, the files would look like this:

```cpp
// A file named myLib.h
#pragma once
namespace magic {
    int my_func(int a, int b);
}
```

```cpp
// A file named myLib.cpp
#include "myLib.h"
int magic::my_func(int a, int b) {
    return 47 * a + 3 * b;
}
```

Attention: the `;` is needed after the declaration in the header file, but not after the definition in the source file.

~~~~exercism/note
Many C++ exercises on Exercism start with two almost empty files: header and source.
You have to check the `*_test.cpp` file to see the names and namespaces of the expected functions to solve the exercise.
~~~~

## Include Guards

You may have noticed the `#pragma once` line in the example header file above.
This include guard ensures that the content of the file is included only once during the compilation to avoid errors.
There is another, more complex variation that starts with `#ifndef` which serves the same purpose.
