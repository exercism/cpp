# Introduction

The process of the _all your base_ exercise can be divided into  up to four parts:
- conversion from input digit vector into a base 10 number
- conversion from intermediate number into target base vector
- possible reversing of the resulting vector
- argument error checking

## General structure

The key to solving all your base is to handle one digit at a time.
You will use the [remainder operator][remainder-operator] repeatedly in tandem with the [division operator][division-operator] or make use of the [`pow`][pow-function].

Algorithms for converting to an intermediate base 10 `int` can be grouped by possible performance.
Some approaches can be parallelized, others might use fewer or less expensive operations.

As the structure of the returning vector is build up in order, while modifying the same integer, there is no potential for a parallel process.

Reversing standard containers like vectors works the same way as discussed in the [reverse-string][reverse-string] exercise.
Depending on the algorithm to build the outgoing vector, the reversion might be unnecessary.

~~~~exercism/note
You might have heard Donald Knuth's famous words ["Premature Optimization Is the Root of All Evil"][pre-opt-blog].
With all the talk about best performance, please take care of the readability and therefore maintainability of your code.
~~~~

## Approach: Converting to base 10

```cpp
unsigned int intermediate = 0;
for (unsigned int d : input_digits) {
    intermediate = intermediate * input_base + d;
}
```

For more information, check the [converting to base 10 approach][to-base-ten].

## Approach: Converting from base 10

```cpp
while (intermediate != 0) {
    unsigned int new_digit = intermediate % output_base;
    intermediate = (unsigned int)(intermediate / output_base);
    b.insert(b.begin(), new_digit);
}
```

For more information, check the [converting from base 10 approach][from-base-ten].

## What about string operations?

There are the[ `std::from_chars`][from-chars] and [`std::to_chars`][to-chars] functions in the [`charconv`][charconv-lib] header. They can be used to convert something like 'FFF' in base 16 to an int in base 10 (4095) and back to a string in base 8: 7777.
There are two problems with this approach:
- Both functions only work with bases from 2 to 32.
- They operate on `char` type arrays.
The _all your base_ exercise asks you to convert integers from any positive base bigger than 2 to any other.
So even if you do the `char` to `int` conversion, you ware still blocked by any test for a base larger than 32 (and we do have a test for that).

[remainder-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[division-operator]: https://en.cppreference.com/w/cpp/language/operator_arithmetic
[pow-function]: https://en.cppreference.com/w/cpp/numeric/math/pow
[reverse-string]: https://exercism.org/tracks/cpp/exercises/reverse-string/dig_deeper
[pre-opt-blog]: https://effectiviology.com/premature-optimization/
[to-base-ten]: https://exercism.org/tracks/cpp/exercises/all-your-base/approaches/to-base-ten
[from-base-ten]: https://exercism.org/tracks/cpp/exercises/all-your-base/approaches/from-base-ten
[from-chars]: https://en.cppreference.com/w/cpp/utility/from_chars
[to-chars]: https://en.cppreference.com/w/cpp/utility/to_chars
[charconv-lib]: https://en.cppreference.com/w/cpp/header/charconv
