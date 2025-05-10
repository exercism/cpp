# `if` statements with `reverse()`

**secret_handshake.h**
```cpp
#pragma once
#include <vector>
#include <string>

namespace secret_handshake {
    std::vector<std::string> commands (unsigned int signal);
}  // namespace secret_handshake
```

**secret_handshake.cpp**
```cpp
#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {

std::vector<std::string> commands(unsigned int signal)
{
    std::vector<std::string> result;
    if (signal & 0b00001) result.emplace_back("wink");
    if (signal & 0b00010) result.emplace_back("double blink");
    if (signal & 0b00100) result.emplace_back("close your eyes");
    if (signal & 0b01000) result.emplace_back("jump");
    if (signal & 0b10000) std::reverse(begin(result), end(result));
    return result;
}
}  // namespace secret_handshake
```

The `commands` function starts by defining the `vector` to hold the returned actions.

It then has a series of `if` statements, each of which uses the [bitwise AND operator][bitwise-operators] to check if the input signal contains a particular action.
Each action is represented by a binary literal, but could just as well be represented by its decimal value

```cpp
    if (signal & 1)  result.emplace_back("wink");
    if (signal & 2)  result.emplace_back("double blink");
    if (signal & 4)  result.emplace_back("close your eyes");
    if (signal & 8)  result.emplace_back("jump");
    if (signal & 16) std::reverse(begin(result), end(result));
```

or its hexadecimal value

```cpp
    if (signal & 0x01)  result.emplace_back("wink");
    if (signal & 0x02)  result.emplace_back("double blink");
    if (signal & 0x04)  result.emplace_back("close your eyes");
    if (signal & 0x08)  result.emplace_back("jump");
    if (signal & 0x010) std::reverse(begin(result), end(result));
```

The [`emplace_back()`][emplace-back] function is used to add the action to the result `vector` if the action's value is contained in the input signal.

If the reverse value is contained in the input signal, then the [`reverse()`][reverse] function is used to  reverse the elements in the result `vector`.

The [`begin()`][begin] and [`end()`][end] member functions could be called as free functions like so

```cpp
if (signal & 0x010) std::reverse(result.begin(), result.end());
```

The result will be the same (at least in this exercise.)

When all of the if statements are gone through, the function returns the result `vector`.

[bitwise-operators]: https://www.geeksforgeeks.org/bitwise-operators-in-c-cpp/
[emplace-back]: https://en.cppreference.com/w/cpp/container/vector/emplace_back
[reverse]: https://en.cppreference.com/w/cpp/algorithm/reverse
[begin]: https://en.cppreference.com/w/cpp/iterator/begin
[end]: https://en.cppreference.com/w/cpp/iterator/end
