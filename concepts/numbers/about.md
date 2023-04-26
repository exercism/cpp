# About

TODO: Include text from introduction.md when final.


~~~~exercism/advanced
## Casting
Casting is the conversion from one type to another.
If a `double` is needed, an `int` can be used in its place.
The `5.0 / 2` example from above is handled by an implicit cast of `2` to `2.0`.
A `double`, that is cast into an `int` might lose information.
It is good practice to make these casts to another type T explicit via `static_cast<T>`.
The old C-style cast via `(T)` is discouraged in modern C++, but should be known nonetheless.
```cpp
double pi{3.14};
int about_2_times_pi_cpp ={static_cast<int>(pi) * 2};
// Old C-style cast:
int about_2_times_pi_c = {(int)pi * 2};
```

## Precision & Representation

Numbers in C++ cannot be abitrarily big.
`int` for example is represented by 32 bits.
That is enough for a set of `2^32` numbers - roughly 4 billion.
Including `0`, this sets the biggest and smallest `int` numbers as `-2^31` and `2^31 - 1`.

Floating point numbers are usually implemented using 15 decimal places of precision, but will vary in representation based on the host system.
~~~~