# Introduction

There are two main branches of _All Your Base_ solutions: direct and indirect.
The indirect approaches convert the input vector to an intermediate numeric value and then back to the vector representation of the output base.
The direct approach skips the intermediate value and translates the incoming vector directly to the desired solution.

## Indirect approaches

The process of the indirect _All Your Base_ solutions can be divided into up to four parts:
- conversion from input digit vector into an intermediate number
- conversion from the intermediate value into the target base vector
- possible reversing of the resulting vector
- argument error checking

### Approach: sequential operation

For many people this is the most obvious algorithm.
It transforms the input to a numeric value.
Afterwards, that numeric value is converted to the output base, using loops in a serial manner.

```cpp
unsigned int intermediate = 0;
for (unsigned int d : input_digits) {
    intermediate = intermediate * input_base + d;
}
std::vector <unsigned int> output_digits{};
while (intermediate > 0) {
    output_digits.emplace_back(intermediate % output_base);
    intermediate /= output_base;
}
```

For more information, check the [converting in-sequence approach][in-sequence].

### Approach: parallel operation

A parallel and concurrent approach that uses the standard library is another option.
It is more complex and therefore more bug-prone.
Depending on the size of the input vector it is not necessarily faster than the sequential approach.

```cpp
std::vector <unsigned int> positions(input_digits.size());
std::iota(positions.begin(), positions.end(), 0);
unsigned int intermediate = std::transform_reduce(
    std::execution::par_unseq,
    input_digits.cbegin(),
    input_digits.cend(),
    positions.crbegin(),
    0U,
    std::plus {},
    [ & input_base](unsigned int d, unsigned int pos) {
        return d * std::pow(input_base, pos);
    });
unsigned int digit_limit{static_cast<unsigned int>(std::log(intermediate) / std::log(output_base)) + 1};
std::vector <unsigned int> output_digits(digit_limit);
std::iota(output_digits.rbegin(), output_digits.rend(), 1);
std::for_each(
    std::execution::par_unseq,
    output_digits.begin(),   
    output_digits.end(),    
    [&](unsigned int digit) {
        output_digits[digit_limit - digit] = 
            intermediate
                / static_cast<unsigned int>(std::pow(output_base, digit - 1))
                % output_base;
});
```

For more information, check the  [converting in-parallel approach][in-parallel].

## A direct approach

To do the conversion directly, we can take inspiration from functions that are usually found in _arbitrary-precision integer_ a.k.a. [_BigInteger_][big-int-example] implementations:

```cpp
std::vector<unsigned int> output_digits{};
for (auto digit: input_digits)
{
    multiply(output_digits, output_base, input_base);
    add(output_digits, output_base, digit);
}
std::reverse(output_digits.begin(), output_digits.end());
return output_digits;
```

The idea is based on two functions:
- `multiply`, which takes the `output_digits` vector and the two bases.
- `add`, which takes an `output_digits` vector and a single digit from the `input_digits` and the `output_base`.

```cpp
void add(std::vector<unsigned int>& a, unsigned int a_base, unsigned int b) {
    auto it = a.begin();
    for (; b && it != a.end(); ++it) {
        b += *it;
        *it = b % a_base;
        b /= a_base;
    }
    for (; b; b /= a_base)
        a.push_back(b % a_base);
}
void multiply(std::vector<unsigned int>& a, unsigned int a_base, unsigned int b) {
    unsigned int carry = 0;
    for (auto& digit: a) {
        carry += digit * b;
        digit = carry % a_base;
        carry /= a_base;
    }
    for (; carry; carry /= a_base)
        a.push_back(carry % a_base);
}
```

## What about string operations?

There are the[ `std::from_chars`][from-chars] and [`std::to_chars`][to-chars] functions in the [`charconv`][charconv-lib] header. They can be used to convert something like 'FFF' in base 16 to an int in base 10 (4095) and back to a string in base 8: 7777.
There are two problems with this approach:
- Both functions only work with bases from 2 to 32.
- They operate on `char` type arrays.
The _All Your Base_ exercise asks you to convert integers from any positive base bigger than 2 to any other.
So even if you do the `char` to `int` conversion, you ware still blocked by any test for a base larger than 32 (and we do have a test for that).

[in-sequence]: https://exercism.org/tracks/cpp/exercises/all-your-base/approaches/in-sequence
[in-parallel]: https://exercism.org/tracks/cpp/exercises/all-your-base/approaches/in-parallel
[big-int-example]: https://www.delftstack.com/howto/cpp/cpp-biginteger/
[from-chars]: https://en.cppreference.com/w/cpp/utility/from_chars
[to-chars]: https://en.cppreference.com/w/cpp/utility/to_chars
[charconv-lib]: https://en.cppreference.com/w/cpp/header/charconv
