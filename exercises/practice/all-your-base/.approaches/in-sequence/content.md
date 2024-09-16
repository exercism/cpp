# In sequence operation

The key for this group of approaches is to convert one digit at a time.
You will use the [remainder operator][remainder-operator] repeatedly in tandem with the [division operator][division-operator] or make use of the [`pow`][pow-function].

Reversing standard containers like vectors works the same way as discussed in the [reverse-string][reverse-string] exercise.
Depending on the algorithm to build the outgoing vector, the reversion might be unnecessary.

## Converting the `input_digits`

First, you want to build the immediate value that is used for the translation into the outgoing base.
If you follow the description word by word, you might get something like this:

### For-loop with `pow`

```cpp
unsigned int intermediate = 0;
for (std::vector<unsigned>::size_type i = 0; i < input_digits.size(); ++i) {
    intermediate += input_digits[i] * std::pow(input_base, input_digits.size() - i - 1);
}
```

Every digit is multiplied by the base which is raised to the power of its position from the right and added to `intermediate`.
The advantage of this approach is the independent calculation for every digit.
That can be a start to write [parallelizable code][parallel-computing].
A downside is the cost of the [`pow`][pow-function] function, opposed to a simple multiplication as seen in the next approach.

### For-loop with `*` and `+`

```cpp
unsigned int intermediate = 0;
for (unsigned int d : input_digits) {
    intermediate = intermediate * input_base + d;
}
```

This for-loop does not use the [`pow`][pow-function] function and should be much cheaper.
As it works through the `input_digits` vector, every digit is still multiplied by the `input_base` raised to the power of its position from the right.
As the repeated multiplication of each digit is only done when all digits are fed through the loop, the process must work in order and is therefore serial.

## Converting into `output_digits`

### While-loop with `%` and `/`

This part uses a [while-loop][while-loop] to repeatedly divide the `intermediate` by the `output_base`, extracting the [remainders][remainder-operator] as digits which are then stored in the `output_digits` vector.

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

### For-loop with `%` and `/`

Instead of the while-loop from the approach above, you can also use a [for-loop][for-loop].

```cpp
std::vector <unsigned int> output_digits{};
for (; intermediate > 0; intermediate /= output_base) {
    output_digits.emplace_back(intermediate % output_base);
}
```

The result is a bit more concise, but has the same properties as the while version.

### Using `div`

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
You do need to define a variable `v` of type `std::ldiv_t`.
As the order of the resulting digits has not changed, you still need to reverse the vector.

## How to avoid reversing

If you do not have the luxury to use a countdown like in approach #4, you can switch `emplace_back` to `insert` or `push_front`.
Depending on the size of your input it might be faster to reverse a vector that was filled with elements via `emplace_back`, than constantly pushing or inserting them at the front.
The reason is, that a new element at the front results in a move operation for every other existing element.

## All parts together

If you combine the parts above with `reverse` from the [`algorithm`][algorithm-header] header, and error checking code, you might get something like this:

```cpp
#include <algorithm>
#include <stdexcept>

std::vector<unsigned int> convert(unsigned int input_base,
                                  const std::vector<unsigned int>& input_digits,
                                  unsigned int output_base) {
    if (input_base < 2 || output_base < 2)
        throw std::invalid_argument("Bases must be at least 2");
    unsigned int intermediate = 0;
    for (unsigned int d : input_digits) {
            if (d >= input_base) 
                throw std::invalid_argument("Digits cannot be bigger than the base");
        intermediate = intermediate * input_base + d;
    }
    std::vector <unsigned int> output_digits{};
    std::ldiv_t v{intermediate, 0};        
    while (v.quot > 0) {
        v = std::div(v.quot, output_base);
        output_digits.emplace_back(v.rem);
    }
    
    std::reverse(output_digits.begin(), output_digits.end());
    
    return output_digits;
}
```

[remainder-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[division-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[pow-function]: https://en.cppreference.com/w/cpp/numeric/math/pow
[reverse-string]: https://exercism.org/tracks/cpp/exercises/reverse-string/dig_deeper
[parallel-computing]: https://en.wikipedia.org/wiki/Parallel_computing
[while-loop]: https://en.cppreference.com/w/cpp/language/while 
[for-loop]: https://en.cppreference.com/w/cpp/language/for 
[algorithm-header]: https://en.cppreference.com/w/cpp/algorithm
[div-function]: https://en.cppreference.com/w/cpp/numeric/math/div
