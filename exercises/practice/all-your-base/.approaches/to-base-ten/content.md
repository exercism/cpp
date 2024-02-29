# Converting to base 10

There are different strategies to convert the input digits to base 10.
Here is a selection of a few approaches and thoughts on their performance.
Keep in mind, that the number of digits you need to process is the most important factor for your algorithms performance.
A simple for loop can be a lot faster for a few digits than a parallel algorithm that has more overhead to be set up.

## For-loop with `pow`

If you follow the description word by word, you might get something like this:

```cpp
unsigned int intermediate = 0;
for (std::vector<unsigned>::size_type i = 0; i < input_digits.size(); ++i) {
    intermediate += input_digits[i] * std::pow(input_base, input_digits.size() - i - 1);
}
```

Every digit is multiplied by the base which is raised to the power of it's position from the right and added to `intermediate`.
The advantage of this approach is the independent calculation for every digit, that can be a start to write [parallelizable code][parallel-computing].
A downside is the cost of the [`pow`][pow-function] function, opposed to a simple multiplication as seen in the next approach.

## For-loop with `*` and `+`

```cpp
unsigned int intermediate = 0;
for (unsigned int d : input_digits) {
    intermediate = intermediate * input_base + d;
}
```

This for-loop does not use the [`pow`][pow-function] function and should be much cheaper.
As it works through the `input_digits` vector, every digit is still multiplied by the `input_base` raised to the power of its position from the right.
As the repeated multiplication of each digit is only done when all digits are fed through the loop, the process must work in order.
It is strictly serial.

## Numeric's `accumulate` 

The for-loop with `*` and `+` can be written with the [`accumulate`][acuumulate-function] function from the [`numeric`][numeric-header] header.

```cpp
#include <numeric>
unsigned int intermediate = std::accumulate(input_digits.begin(),
                                            input_digits.end(), 0,
        [&input_base] (unsigned int sum, unsigned int d) {
            return sum * input_base + d;
        });
```
 `accumulate` is guaranteed to run in order and thus strictly serial as well.

## Algorithm's `transform_reduce` in parallel

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
    0,                          // initial value
    std::plus {},               // reduce function
                                // transformation function:
    [ & input_base](unsigned int d, unsigned int pos) {
        return d * std::pow(input_base, pos);
    });
```

`transform_reduce` can work on two containers at the same time.
In this case we use the `input_digits` and the positions from the back as exponents for the [`pow`][pow-function] function in the transformation function.
The reduce function is combining each result from the transformation with a simple addition for us ([`std::plus{}`][std-plus]).

The most important part is the [execution policy][execution-policies].
The example uses `std::execution::par_unseq` to indicate that the `transform_reduce` function might be run in parallel and vectorized.
With this statement you promise, that the execution does not violate any data dependencies.
The function calls are only reading, we do not need to set any locks.

~~~~exercism/note
If the compiler will transform the code into something that actually works in parallel and/or vectorized is a whole different chapter.
There is a lot of ifs and whens that lead to the final code.
One of the more direct ways to parallel processing is the use of [Intel's thread building blocks][tbb].
~~~~

# snippets all in the same way

[parallel-computing]: https://en.wikipedia.org/wiki/Parallel_computing
[pow-function]: https://en.cppreference.com/w/cpp/numeric/math/pow
[acuumulate-function]: https://en.cppreference.com/w/cpp/algorithm/accumulate
[numeric-header]:https://en.cppreference.com/w/cpp/header/numeric
[transform-reduce]: https://en.cppreference.com/w/cpp/algorithm/transform_reduce
[algorithm-header]: https://en.cppreference.com/w/cpp/algorithm
[iota-function]: https://en.cppreference.com/w/cpp/algorithm/iota
[std-plus]: https://en.cppreference.com/w/cpp/utility/functional/plus
[execution-policies]: https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t
[tbb]: https://github.com/oneapi-src/oneTBB
