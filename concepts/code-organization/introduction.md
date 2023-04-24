# Introduction

Big projects often span over several files to keep the code organized in logical components.

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

Attention: the `;` is needed after the declaration, but not necessarily after the definition.

## Header Files

Often, declarations are bundled together in header files. 
The most common file extension for header files is `.h`.
Some projects use `.hpp` or skip the extension completely.
The definitions are located in a separate `.cpp` file.


## Includes

It is possible to include the content of other files with the `include` directive.
Includes should be stated at the top of the file.
The snippet below shows how to use the `example()` function that was declared in the `myProject.h` file.

```cpp
#include "myProject.h"
example();
```

If the `myProject.h` is located in the `some_folder` and not in the root directory, you would have to use `#include "some_folder/myProject.h"`.

## Include Guards

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
A modern form, that will achieve the same result is the #pragma directive `#pragma once`.
The problem is, that pragmas are not an official part of the C++ language and the implementation differs from compiler to compiler.

## Namespaces

An important method for code organization are namespaces.
Two functions `int foo()` can be used side-by-side if they are defined in different namespaces.
They can be called with the scope resolution operator `::`.
Namespaces can be nested.
They are kept as they are after includes.

```cpp
namespace my_ns {
    int foo() {
        return 44;
    }
    namespace my_inner_ns {
        int baz() {
            return 90;
        }
    }
}
namespace my_other_ns {
    int foo() {
        return -2;
    }
}

int myresult{my_ns::foo() + my_other_ns::foo() * my_ns::my_inner_ns::baz()};
```

Deeply nested namespaces might be too verbose.
It is possible to remove the verbosity with a namespace import via `using`.
To keep some differentiation aliases might be useful.

```cpp
int my_other_result{my_ns::my_inner_ns::baz()};

using namespace my_ns::my_inner_ns; // importing the complete namespace
int also_other_result{baz()};

namespace m = my_ns; // setting an alias
namespace o = my_other_ns;

int also_my_result{m::foo() + o::foo() * m::my_inner_ns::baz()};
```

## Standard Library Header Files
 
The standard library offers many common functions, algorithms, and data structures.
They are grouped into header files.
They are included with angled braces `<>` instead of double quotes `"`.
The difference with the braces is the location, where the compiler searches for the header files.
The search in the current project is skipped for the angled braces version, and it directly starts in the system's include directories.
The standard library headers are located in the `std` namespace.

One example is the C numerics library, with its "cmath" header.
The header file has declarations of many common mathematical operations.

```cpp
#include <cmath>

int cube_me(int a) {
    // raise `a` to the third power
    return std::pow(a, 3);
}
```