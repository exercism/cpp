# Converting from base 10

There are different strategies to convert a decimal number to another base.
Here is a selection of a few approaches and thoughts on their performance.
Keep in mind, that the number of digits you need to process is the most important factor for your algorithms performance.
A simple for loop can be a lot faster for a small number than a [parallel algorithm][parallel-computing] that has more overhead to be set up.


## 1: While-loop with `%` and `/`

This approach uses a [while-loop][while-loop] to repeatedly divide the `intermediate` by the `output_base`, extracting the [remainders][remainder-operator]c as digits which are then stored in the `output_digits` vector.

```cpp
std::vector <unsigned int> output_digits{};
while (intermediate > 0) {
    output_digits.emplace_back(intermediate % output_base);
    intermediate /= output_base;
}
```

The approach is simple, straightforward, and easy to understand.
The order of operation makes it necessary to revert the final `vector`.
As the loop constantly writes to the `intermediate` variable and needs to do so in order, the approach is strictly serial.

## 2: For-loop with `%` and `/`

Instead of the while-loop from the approach above, you can also use a [for-loop][for-loop].

```cpp
std::vector <unsigned int> output_digits{};
for (; intermediate > 0; intermediate /= output_base) {
    output_digits.emplace_back(intermediate % output_base);
}
```

The result is a bit more concise, but has the same properties as the while version.

## 3: Using `div`

When you need both the remainder and the quotient from a division operation, you can use [`std::div`][div-function].

```cpp
std::vector <unsigned int> output_digits{};
std::ldiv_t v{intermediate, 0};        
while (v.quot > 0) {
    v = std::div(v.quot, output_base);
    output_digits.emplace_back(v.rem);
}
```

Depending on the processor this might save one operation per loop iteration.
You do need to allocate some memory for the `v` variable of type `std::ldiv_t`.
As the order of the resulting digits has not changed, you still need to reverse the vector.

## 4: For-loop with `pow`

As discussed in the [approach to convert to base 10][to-base-ten], you can use [`pow`][pow-function] to move to an independent approach, that does not need to change the `intermediate` variable.

To set up the for loop, you need to calculate the number of digits beforehand with `std::log(intermediate) / std::log(output_base)`.

```cpp
std::vector <unsigned int> output_digits{};
unsigned int digit_limit{static_cast<unsigned int>(std::log(intermediate) / std::log(output_base) + 1)};
for(unsigned int digit{digit_limit}; digit > 0; --digit) {
    output_digits.emplace_back(intermediate / static_cast<unsigned int>(std::pow(output_base, digit - 1)) % output_base);
}
```

In serial execution this operation is more costly than the approaches above, but you do not need to reverse the resulting vector.

## 5: Algorithm's `for_each` in parallel

With the `pow` approach, you gained the option to move to parallel territory.
The stl container functions in C++17 expect an iterator.
You cannot decrement an integer like above.
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
The [for-each][for-each] then uses the prepared vector in the fashion of approach #4.
The most important part is the [execution policy][execution-policies].
The approach uses `std::execution::par_unseq` to indicate that the `transform_reduce` function might be run in parallel and vectorized.
With this statement you promise, that the execution does not violate any data dependencies.
The function calls are never writing to the same vector element, we do not need to set any locks.

~~~~exercism/note
If the compiler will transform the code into something that actually works in parallel and/or vectorized is a whole different chapter.
There is a lot of ifs and whens that lead to the final code.
One of the more direct ways to parallel processing is the use of [Intel's thread building blocks][tbb].
~~~~

## How to avoid reversing

If you do not have the luxury to use a countdown like in approach #4, you can switch `emplace_back` to `insert` or `push_front`.
Depending on the size of your input it might be faster to reverse a vector that was filled with elements via `emplace_back`, than constantly pushing or inserting them at the front.
The reason is, that a new element at the front results in a move operation for every other existing element.

[parallel-computing]: https://en.wikipedia.org/wiki/Parallel_computing
[remainder-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[while-loop]: https://en.cppreference.com/w/cpp/language/while 
[for-loop]: https://en.cppreference.com/w/cpp/language/for 
[div-function]: https://en.cppreference.com/w/cpp/numeric/math/div
[numeric-header]: https://en.cppreference.com/w/cpp/header/numeric
[pow-function]: https://en.cppreference.com/w/cpp/numeric/math/pow
[for-each]: https://en.cppreference.com/w/cpp/algorithm/for_each
[execution-policies]: https://en.cppreference.com/w/cpp/algorithm/execution_policy_tag_t
