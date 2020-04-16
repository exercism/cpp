# Sieve

## Task

Use the Sieve of Eratosthenes to find all the primes from 2 up to a given number.

The Sieve of Eratosthenes is a simple, ancient algorithm for finding all prime numbers up to any given limit. It does so by iteratively marking as composite (i.e. not prime) the multiples of each prime, starting with the multiples of 2. It does not use any division or remainder operation.

Create your range, starting at two and continuing up to and including the given limit. (i.e. [2, limit])

The algorithm consists of repeating the following over and over:

    take the next available unmarked number in your list (it is prime)
    mark all the multiples of that number (they are not prime)

Repeat until you have processed each number in your range.

When the algorithm terminates, all the numbers in the list that have not been marked are prime.

The wikipedia article has a useful graphic that explains the algorithm: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes

Notice that this is a very specific algorithm, and the tests don't check that you've implemented the algorithm, only that you've come up with the correct list of primes. A good first test is to check that you do not use division or remainder operations (div, /, mod or % depending on the language).```

## Example

`sieve.h`

```cpp
#if !defined(SIEVE_H)
#define SIEVE_H

#include <vector>

namespace sieve
{
std::vector<int> primes(int n) noexcept;
} // namespace sieve

#endif // SIEVE_H
```

`sieve.cpp`

```cpp
#include <cmath>

#include "sieve.h"

namespace sieve
{
std::vector<int> primes(int n) noexcept
{
    // Create the sieve
    std::vector<bool> sieve(n + 1, true);
    for (int i = 2; i <= std::sqrt(n); i++)
    {
        if (sieve.at(i))
        {
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }

    // Apply the sieve
    std::vector<int> result;
    for (unsigned int i = 2; i < sieve.size(); i++)
    {
        if (sieve.at(i))
        {
            result.emplace_back(i);
        }
    }
    return result;
}
} // namespace sieve
```

## Concepts

- .h file: the tests include `"sieve.h"`
- .cpp file: the most common approach is to use a `.cpp` for declaring member functions
- include guard: protect against multiple inclusion within a single translation unit
- namespaces: the class/struct is member of a namespace
- return values: the result is returned by the function
- `noexcept` function specifier: none of the functions in this exercise are throwing
- loops: use `for`s to create and apply the sieve
- conditionals: use `if/else` or `switch` to execute different code branches
- variables: use a specific name to store the result being calculated
- arithmetic: use `+=` and `++` to increment numbers and `cmath` functions
- comparison: use `<=` and `<` to compare numbers
- generics: `vector` can contain different types
- std::vector: sequence container that encapsulates dynamic size array
- std::vector<bool>: specialized version of std::vector which is optimized to store bit values
- integer: results are a collection of `int`s
- boolean: a collection of `bool`s is used to filter prime numbers

## Alternative approaches

- Declaring the function in the header file
- Using `switch` instead of `for`
- Create an list of numbers from 2 to `n`, find and delete non prime numbers

## Common mistakes

- Forgetting to submit the `.h` file
- Forgetting to enable and/or run all the tests
- No include guards
- Bad variable and constants names
- Writing to `std::cout` or `std::cerr`
- Not initializing the sieve `vector` with a explicit size to avoid reallocation

## Common suggestions to improve a solution

- Use `constexpr` whenever the result of computation does not depend on run-time data
- Add `noexcept` to mark all functions that are not expected to throw exceptions
