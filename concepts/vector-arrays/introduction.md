# Introduction

## Arrays and Vectors

C++ offers different containers to store elements of the same type in an ordered way.
There is `std::array` for containers of a fixed size and `std::vector`, which comes with dynamic resizing capabilities.

### Construction

When you declare an array or a vector you need to specify the type of elements, that container will hold.
Arrays also need a size.
Look at these examples to see the two container types' initializations:

```cpp
#include <array>
#include <string>

// std::array<element_type, size> variable_name {list of elements}
std::array<std::string, 3> indie_rock {"yeah", "yeah", "yeah"};
// indie_rock contains the elements "yeah" three times
```

Vectors usually need more space, as they allocate memory for further growth.
You do not need to specify a size:

```cpp
#include <vector>

// std::vector<element_type> variable_name {list of elements}
std::vector<int> countdown {3, 2, 1};
// countdown contains the elements 3, 2 and 1
```

> Note: You do not need to know the exact mechanics behind the template concept yet, it will have its own concept further down the syllabus tree.

### Element access

Vectors and arrays share the same functions to access their elements.
You can use the member functions `front` and `back` to get the first and last elements of the container.
There is also `at` and the `[]` operator to access speficic elements.

```cpp
countdown[0];
// => 3
countdown.at(2);
// => 1
countdown[1] = 4;
// countdown now contains 3, 4 and 1
indie_rock.back() = "yeahs"; 
// indie_rock is now "yeah", "yeah", "yeahs"
```

> Note: If you pick a position that is not in the range of your container, `[]` might lead to undefined behavior.
> The `at` function would raise an exception, which might make your life easier in the long term.

### Vector modifiers

As a `vector` is not fixed in size, it is possible to add or remove elements. 
Two common functions for that purpose are `emplace_back` and `pop_back`.

```cpp
std::vector<std::string> witches {"Holly", "Alyssa", "Shannen"};
witches.pop_back(); 
// Shannen is no longer with the witches
witches.emplace_back("Rose");
// Rose has joined the team
```

### Capacity

You can check the containers for emptiness with the member function `empty`.
If you want to know the number of elements, you can use `size`.
