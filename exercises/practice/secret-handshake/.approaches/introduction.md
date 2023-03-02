# Introduction

There are many ways to solve Secret Handshake.
One general approach is to use a series of `if` statements and then use [`reverse()`][reverse] if needed.
Another general approach is to iterate once even if the signals are meant to be reversed.

## Approach: `if` statements with `reverse()`

**secret_handshake.h**
```cpp
#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H
#include <vector>
#include <string>

namespace secret_handshake {
    std::vector<std::string> commands (unsigned int signal);
}  // namespace secret_handshake

#endif // SECRET_HANDSHAKE_H
```

**secret_handshake.cpp**
```cpp
#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {

std::vector<std::string> commands(unsigned int signal)
{
    std::vector<std::string> result;
    if (signal & 0b0001)  result.emplace_back("wink");
    if (signal & 0b0010)  result.emplace_back("double blink");
    if (signal & 0b00100)  result.emplace_back("close your eyes");
    if (signal & 0b01000)  result.emplace_back("jump");
    if (signal & 0b10000) std::reverse(begin(result), end(result));
    return result;
}
}  // namespace secret_handshake
```

For more information, check the [`if` statements with `reverse()` approach][approach-if-statements-with-reverse].

## Approach: Iterate once

**secret_handshake.h**
```cpp
#if !defined(SECRET_HANDSHAKE_H)
#define SECRET_HANDSHAKE_H
#include <vector>
#include <string>

namespace secret_handshake {
    std::vector<std::string> commands (unsigned int signal);
}  // namespace secret_handshake

#endif // SECRET_HANDSHAKE_H
```

**secret_handshake.cpp**
```cpp
#include "secret_handshake.h"

namespace {
    const std::vector<std::string> signals = {
        "wink",
        "double blink",
        "close your eyes",
        "jump",
    };
}

namespace secret_handshake {
    std::vector<std::string> commands (unsigned int signal) {
        std::vector<std::string> output;

        int action = 0, action_incr = 1, end = signals.size();
        if (signal & 16) {action = 3; action_incr = -1; end = -1;}        
            
        for (; action != end; action+=action_incr)
            if (signal & (1 << action))
                output.emplace_back(signals[action]);
        return output;
    }
}  // namespace secret_handshake
```

For more information, check the [Iterate once approach][approach-iterate-once].

## Which approach to use?

Since benchmarking is currrently outside the scope of this document, which to use is pretty much a matter of personal preference,
but the `if` statements with `reverse()` may be considered to be more idiomatic as well as more readable.

[reverse]: https://en.cppreference.com/w/cpp/algorithm/reverse
[approach-if-statements-with-reverse]: https://exercism.org/tracks/cpp/exercises/secret-handshake/approaches/if-statements-with-reverse
[approach-iterate-once]: https://exercism.org/tracks/cpp/exercises/secret-handshake/approaches/iterate-once
