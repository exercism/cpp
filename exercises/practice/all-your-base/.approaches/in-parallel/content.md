# In parallel operations

The key for this group of approaches is to convert one digit at a time.
You will use the [remainder operator][remainder-operator] repeatedly in tandem with the [division operator][division-operator] or make use of the [`pow`][pow-function].

~~~~exercism/note
You might have heard Donald Knuth's famous words ["Premature Optimization Is the Root of All Evil"][pre-opt-blog].
With all the talk about best performance, please take care of the readability and therefore maintainability of your code.
~~~~

Keep in mind, that the number of digits you need to process is the most important factor for your algorithm's performance.
A simple serial for-loop can be a lot faster for a small number than a [parallel algorithm][parallel-computing] that has more overhead to be set up.

## Converting the `input_digits`

### Numeric's `accumulate` 

The for-loop with `*` and `+` can be written with the [`accumulate`][acuumulate-function] function from the [`numeric`][numeric-header] header.

```cpp
#include <numeric>
unsigned int intermediate = std::accumulate(input_digits.begin(),
                                            input_digits.end(), 0U,
        [&input_base] (unsigned int sum, unsigned int d) {
            return sum * input_base + d;
        });
```

 `accumulate` is guaranteed to run in order and thus is strictly serial as well.

### Algorithm's `transform_reduce` in parallel

There are several functions that can be run with a parallel policy in the [`algorithm`][algorithm-header] header.
As you need the position to calculate the correct exponent for the [`pow`][pow-function] function, you do need a second container with the position information.
To fill that container we can use numeric's [`iota`][iota-function], which will produce something like `{0, 1, 2, 3, ... }` for us.

```cpp
std::vector <unsigned int> positions(input_digits.size());
std::iota(positions.begin(), positions.end(), 0);
unsigned int intermediate = std::transform_reduce(
    std::execution::par_unseq,  // execution policy
    input_digits.cbegin(),      // first input container start
    input_digits.cend(),        // first input container end
    positions.crbegin(),        // start second container from the rear
    0U,                          // initial value
    std::plus {},               // reduce function
                                // transformation function:
    [ & input_base](unsigned int d, unsigned int pos) {
        return d * std::pow(input_base, pos);
    });
```

[`transform_reduce`][transform-reduce] can work on two containers at the same time.
In this case we use the `input_digits` and the positions from the back as exponents for the [`pow`][pow-function] function in the transformation function.
The reduce function is combining each result from the transformation with a simple addition ([`std::plus{}`][std-plus]).

The most important part is the [execution policy][execution-policies].
The example uses `std::execution::par_unseq` to indicate that the `transform_reduce` function can be run in parallel and vectorized.
With this statement you promise, that the execution does not violate any data dependencies.
The function calls are only reading, we do not need to set any locks.

~~~~exercism/note
If the compiler will transform the code into something that actually works in parallel and/or vectorized is a whole different chapter.
There is a lot of ifs and whens that lead to the final code.
One of the more direct ways to parallel processing is the use of [Intel's thread building blocks][tbb].
~~~~

## Converting into `output_digits`

### For-loop with `pow`

As discussed in the [serial approach][in-sequence] and above, you can use [`pow`][pow-function] to move to an independent approach, that does not change the `intermediate` variable.

To set up the [for-loop][for-loop], you need to calculate the number of digits beforehand with `std::log(intermediate) / std::log(output_base)`.

```cpp
std::vector <unsigned int> output_digits{};
unsigned int digit_limit{static_cast<unsigned int>(std::log(intermediate) / std::log(output_base) + 1)};
for(unsigned int digit{digit_limit}; digit > 0; --digit) {
    output_digits.emplace_back(intermediate / static_cast<unsigned int>(std::pow(output_base, digit - 1)) % output_base);
}
```

With this approach you do not need to reverse the resulting vector.

## Algorithm's `for_each` in parallel

With the `pow` approach, you gained the option to move to parallel territory.
You cannot decrement an integer like above, as the std container functions in C++17 expect an iterator.
[`iota`][iota-function] helps to set up the vector with the correct values.

```cpp
unsigned int digit_limit{static_cast<unsigned int>(std::log(intermediate) / std::log(output_base)) + 1};
std::vector <unsigned int> output_digits(digit_limit);
std::iota(output_digits.rbegin(), output_digits.rend(), 1);
std::for_each(std::execution::par_unseq,
                output_digits.begin(),   
                output_digits.end(),    
                [&](unsigned int digit) {
                output_digits[digit_limit - digit] = 
                    intermediate
                        / static_cast<unsigned int>(std::pow(output_base, digit - 1))
                        % output_base;
});
```

The [for-each][for-each] function then uses the prepared vector in the fashion of approach #4.
The most important part is the [execution policy][execution-policies].
The approach uses `std::execution::par_unseq` to indicate that the `transform_reduce` function can be run in parallel and vectorized.
With this statement you promise, that the execution does not violate any data dependencies.
The function calls are never writing to the same vector element, we do not need to set any locks.

## All together

```cpp
#include <algorithm>
#include <cmath>
#include <execution>
#include <numeric>
#include <stdexcept>

std::vector<unsigned int> convert(unsigned int input_base,
    const std::vector<unsigned int>& input_digits, unsigned int output_base) {
    if (input_base < 2 || output_base < 2) {
        throw std::invalid_argument("Bases must be at least 2");
    }
    if (std::any_of(input_digits.begin(), input_digits.end(),
            [input_base](unsigned int digit) {
                return digit >= input_base;
            }))
        throw std::invalid_argument("Digits cannot be bigger than the base");

    std::vector <unsigned int> positions(input_digits.size());
    std::iota(positions.begin(), positions.end(), 0U);
    unsigned int intermediate = std::transform_reduce(
        std::execution::par_unseq,
        input_digits.cbegin(),
        input_digits.cend(),
        positions.crbegin(),
        0U,
        std::plus {},
        [&input_base](unsigned int d, unsigned int pos) {
            return d * std::pow(input_base, pos);
        });

    unsigned int digit_limit{static_cast<unsigned int>(std::log(intermediate) / std::log(output_base) + 1)};
    std::vector <unsigned int> output_digits(digit_limit);
    std::iota(output_digits.rbegin(), output_digits.rend(), 1);
    std::for_each(
        std::execution::par_unseq,
        output_digits.begin(),
        output_digits.end(),
        [&](unsigned int digit) {
            output_digits[digit_limit - digit] = 
                intermediate / static_cast<unsigned int>(std::pow(output_base, digit - 1)) % output_base;
    });

    return output_digits;
}
```

[remainder-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[division-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[pow-function]: https://en.cppreference.com/w/cpp/numeric/math/pow
[reverse-string]: https://exercism.org/tracks/cpp/exercises/reverse-string/dig_deeper
[pre-opt-blog]: https://effectiviology.com/premature-optimization/
[parallel-computing]: https://en.wikipedia.org/wiki/Parallel_computing
[acuumulate-function]: https://en.cppreference.com/w/cpp/algorithm/accumulate
[numeric-header]:https://en.cppreference.com/w/cpp/header/numeric
[algorithm-header]: https://en.cppreference.com/w/cpp/algorithm
[iota-function]: https://en.cppreference.com/w/cpp/algorithm/iota
[transform-reduce]: https://en.cppreference.com/w/cpp/algorithm/transform_reduce
[std-plus]: https://en.cppreference.com/w/cpp/utility/functional/plus
[execution-policies]: https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t
[tbb]: https://github.com/oneapi-src/oneTBB
[in-sequence]: https://exercism.org/tracks/cpp/exercises/all-your-base/approaches/in-sequence
[for-loop]: https://en.cppreference.com/w/cpp/language/for 
[for-each]: https://en.cppreference.com/w/cpp/algorithm/for_each
