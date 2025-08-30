# Introduction

In general, you don't want to reinvent the wheel when it comes to programming.
For many standard algorithms, there will be someone who might have already done your work for you.

## Includes

To include the content of other files C++ uses the `include` directive.
These includes should be stated at the top of the file.
During compilation, the line with the directive is replaced by the content of the respective file.
Namespaces are kept as they are in the original file after includes.

## The Standard Library

The standard library offers many common functions, algorithms, and data structures.
The standard library uses the `std` namespace.

One example is the C numerics library `cmath`.
It provides many common mathematical operations.

```cpp
#include <cmath>

int cube_me(int a) {
    // raise `a` to the third power
    return std::pow(a, 3);
}
```

~~~~exercism/note
Standard libraries are included with angled braces `<>` instead of double quotes `"`.
The difference is the location, where the compiler searches for the respective files.
The search in the current project is skipped for the angled braces version, and it directly starts in the system's include directories.
If you want to include local files you would use double quotes: `#include "myfile"`
~~~~
