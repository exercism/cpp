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

If you want to write a library called "quick_math", that offers a function "super_root" that you want to use often, the files would look like this:

```cpp
// A file named quick_math.h
#pragma once
namespace quick_math {
    double super_root(double x, int n);
}
```

```cpp
// A file named quick_math.cpp
#include "quick_math.h"
#include <cmath>
double quick_math::super_root(double x, int n) {
    while(n) { x = sqrt(x), --n;}
    return x;
}
```

If you need to include another header, that is only needed by the implementation, the respective `#include` line is only needed in the source file.
Everything that is included in the header, is also available in the `.cpp` file, like the `string` library in the example below.
Attention: the `;` is needed after the declaration in the header file, but not after the definition in the source file.

~~~~exercism/note
Many C++ exercises on Exercism start with two almost empty files: header and source.
You have to check the `*_test.cpp` file to see the names and namespaces of the expected functions to solve the exercise.
~~~~

## Classes and Headers

Classes can become very complex.
Many developers separate the public interface from the inner workings.
Often, all declarations are decoupled from the implementation via header and source files, but there are some exceptions.
The split between those two might seem arbitrary and the following example can give some guidance.

```cpp
// A file named robot_flower.h
#if !defined(ROBOT_FLOWER_H)
#define ROBOT_FLOWER_H
#include <string>
namespace robots {
    class Flower {
        private:
            bool needs_water{};
            int size{};
            std::string name{};
        public:
            Flower(std::string name, int size = 0);
            void give_water() {needs_water = false;}
            std::string get_name() {return name;}
            int get_size() {return size;}
            void start_next_day();
    };
}
#endif
```

```cpp
// A file named robot_flower.cpp
#include "robot_flower.h"
robots::Flower::Flower(std::string name, int size) {this->name = "Robotica " + name; this->size = size;}
void robots::Flower::start_next_day() {if (!needs_water) ++size; needs_water = true;}
```

Member variables are usually kept in the header together with the implementation of trivial member functions.
The simple `give_water`, `get_name` and `get_size` functions are so small, that one would not move them into the `.cpp` file.
The constructor and the `start_next_day` functions shall be considered more _complex_ in this example and have thus been moved.
The definitions are prefixed with the namespace `robots` and the class type `Flower`.

## Include Guards

You may have noticed the `#pragma once` line in the example header file above.
This include guard ensures that the content of the file is included only once during the compilation to avoid errors.
There is another, more complex variation that starts with `#if !defined` and ends with `#endif`.
It serves the same purpose and its usage is shown in the `Flower` class example above.
