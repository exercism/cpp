# About

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

## Include Guards via pragma once

You may have noticed the `#pragma once` line in the example header file above.
This include guard ensures that the content of the file is included only once during the compilation to avoid errors.
There is another, more complex variation that starts with `#ifndef` which serves the same purpose, that is detailed below.


~~~~exercism/advanced
## Forward Declarations
C++ code is evaluated procedurally.
If you want to use a function, it has to be known to the compiler at the moment of usage.
Sometimes it is not possible to find a linear fashion to lay out the definitions in the source code.
Take a look at the example below:

```cpp
int myFunction(int n) {
    if (n < 10) {
        return n;
    } else {
        return myOtherFunction(n / 10);
    }
}

int myOtherFunction(int m) {
    return myFunction(m / 2);
}
```

When `myFunction` is defined, the compiler does not know about `myOtherFunction` yet.
Unfortunately, the circle-reference problem cannot be solved by switching the order.

C++ offers **forward declarations** to let the compiler know of `myFunction` and `myOtherFunction` before they are defined.
The compiler assumes that the definition will follow at some later point after the declaration.
The next example shows how a forward declaration is used for functions.

```cpp
int myFunction(int n);          // Forward declaration of myFunction
int myOtherFunction(int m);     // Forward declaration of myOtherFunction

// Definition of myFunction
int myFunction(int n) {
    if (n < 0) {
        return 0;
    } else {
        return myOtherFunction(n - 2);
    }
}

// Definition of myOtherFunction
int myOtherFunction(int m) {
    return myFunction(m / 2);
}
```

## Include Guards via ifndef

It does not matter if the same file is included multiple times within a project.
Header files should not contain definitions.
The complete project cannot have the same definition more than once. 
This is called the "One definition rule".
It will be enforced by the compiler.

It is easy to avoid multiple unintended inclusions of the same definition with include guards.
They are formed by a special procedure during the compilation stages.
The aim is to only include a file only if a certain variable has not been set and then set it once the file is included.
Often the sequence of this variable is chosen as a variation of the name of the file.
Another method is the generation of a UUID to reduce the risk of accidentally using the sequence twice.
The syntax can be seen below with `MY_HEADER_FILE_H` as a variable.

```cpp
#ifndef MY_HEADER_FILE_H /* any name uniquely mapped to file name */
#define MY_HEADER_FILE_H
// file content
#endif
```

The problem with `#pragma once` is, that pragmas are not an official part of the C++ language and the implementation differs from compiler to compiler.
Many big projects have switched to the simpler pragma method, but a few are still cautious.
~~~~