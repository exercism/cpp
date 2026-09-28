# Introduction

Reverse String can be solved in different ways, too many to describe them all in detail.
Most approaches can be classified in two ways:

1. They either do things "manually" or they use the standard library.
2. They either build a new reversed string, or they modify the parameter.

If you are new to (imperative) programming you might want to start with "manual" approaches, writing loops and appending/assigning characters explicitly.
That gives you an idea of how the computer manipulates entities and how the algorithms work.

If you want to learn best practices and "modern C++" you might want to try using the standard library.
That leads to concise, expressive, readable, idiomatic, and efficient code.

There are also some rather unsual approaches that are not necessarily the best (simple, easy to read, idiomatic, and reasonably efficient) but solve the task in an interesting and "fun" way (for *some* definition of "fun").


## Approach: Iterative

```cpp
std::string reverse_string(const std::string& original)
{
    // start with an empty string
    std::string result;

    // loop over the original string
    for (std::size_t i = 0; i < size(original); ++i)
    {
        std::size_t rindex = size(original) - i - 1;

        // append each character (starting with the last one)
        result.append(original[rindex]);
    }

    // result now contains a reversed version of the string
    return result;
}
```

This approach builds the reversed string iteratively, looping over the original string, appending or assigning each character to the result.
This is probably the most straighforward solution of the problem, it does everything "manually" and each step is easy to understand.

For more information and variations check out the [Iterative][approach-iterative] approach.


## Approach: Swapping characters

```cpp
std::string reverse_string(std::string str)
{
    // handle an empty string as a special case
    if (str.empty())
        return str;

    // use two indexes,
    // a starts at the beginning and gets incremented
    // b starts at the end and gets decremented
    std::size_t a = 0;
    std::size_t b = size(str) - 1;

    // swap characters until the two indexes meet
    while (a < b)
    {
        std::swap(str[a], str[b]);
        ++a;
        --b;
    }

    // str is now reversed
    return str;
}
```

This approach modifies the parameter directly.
It repeatedly swaps characters "manually" until the string is reversed.
Like the iterative approach above it does everything "manually" (except for the `std::swap`), each step is easy to understand.

For more information check out the [Swapping characters][approach-swapping-characters] approach.


## Approach: Using the standard library

```cpp
std::string reverse_string(std::string str)
{
    // call a function from the standard library that performs the reversal
    std::reverse(begin(str), end(str));

    // str is now reversed
    return str;
}
```

This approach modifies the parameter directly, calling `std::reverse`.
That function (internally) swaps the characters to reverse the string.
That is similar to the previous approach but the code is shorter, more expressive, idiomatic, and easier to read.

For more information check out the [Using the standard library][approach-using-the-standard-lib] approach.


## Approach: Direct construction

```cpp
std::string reverse_string(std::string_view original)
{
    // construct the reversed string directly
    // by combining the constructor with reverse iterators
    return std::string(rbegin(original), rend(original));
}
```

This approach constructs the reversed string directly.
It combines a constructor of `std::string` with the "reverse iterators" of the original string.
That makes the code concise, expressive, easy to read, idiomatic, and very efficient.

For more information check out the [Direct Construction][approach-direct-construction] approach.


## Approach: Stack operations

```cpp
std::string reverse_string(std::string_view original)
{
    // start with an empty string
    std::string result;

    // repeat as long as the parameter still contains characters
    while (!original.empty())
    {
        // pop the last character off the parameter and push it onto the result
        char c = original.back();
        original.remove_suffix(1);
        result.push_back(c);
    }

    // result now contains a reversed version of the string
    return result;
}
```

This approach treats the two strings as stacks.
It builds the result by repeatedly "popping" the top-most (i.e. last) character off the `original` and "pushing" (i.e. appending) it onto the `result`.
Once the `original` is empty, the `result` contains the reversed string.

For more information check out the [Stack Operations][approach-stack-operations] approach.


## Approach: Linear recursion

```cpp
void recursive_helper(std::string_view input, std::string& output)
{
    // handle the base case
    if (input.empty())
        return;

    // append the last character of the input to the output
    output.append(input.back());
    // and remove that last character from the input
    input.remove_suffix(1);

    // do the recursion
    recursive_helper(input, output);
}

std::string reverse_string(std::string_view original)
{
    // create an empty string
    std::string result;

    // pass it to the recursive helper function
    recursive_helper(original, result);

    // result now contains a reversed version of the string
    return result;
}
```

This approach builds the reversed string by using linear recursion.
It creates an empty string and passes that as an "output parameter" to the recursive helper function.
That helper function removes the last character from the input, appends it to the output, and calls itself recursively.
Be careful: That is only safe if you know what you are doing.

For more information check out the [Linear Recursion][approach-linear-recursion] approach.


## Approach: Divide and conquer

```cpp
std::string reverse_string(std::string_view original)
{
    // handle the base case where nothing needs to be done
    if (size(original) <= 1)
        return std::string{original};

    // "divide and conquer" by reversing the two halfs of the string separately
    auto half_size = size(str) / 2;
    return reverse_string(original.substr(half_size) +
           reverse_string(original.substr(0, half_size);
}
```

This approach builds the reversed string by using recursion.
Its "divide and conquer" strategy results in a linearithmic runtime, i.e. O(n log n).

For more information check out the [Divide and Conquer][approach-divide-and-conquer] approach.


## Approach: Over-Engineered

```cpp
std::string reverse_string(std::string&& str) noexcept
{
    // handle std::string rvalues efficiently
    // by modifying and returning the parameter
    std::reverse(begin(str), end(str));
    return str;
}

std::string reverse_string(std::string_view original)
{
    // handle unmodifiable strings efficiently
    // by constructing the reversed string directly
    return {rbegin(original), rend(original)};
}

std::string reverse_string(const char *str)
{
    // disambiguate manually if the parameter is a char pointer
    return reverse_string(std::string_view{str});
}
```

This approach uses an "overload set" of three different functions to solve the task as efficiently as possible.
Which function gets called depends on the type of the argument that the caller passes to the function.

That is clearly over-engineered, in most contexts it is just not necessary, and it makes the code hard to read and to maintain.
But it can be interesting to analyze because it uses some interesting features of C++.

For more information check out the [Over-Engineered][approach-over-engineered] approach.


[approach-iterative]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/iterative
[approach-swapping-characters]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/swapping-characters
[approach-using-the-standard-lib]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/using-the-standard-lib
[approach-direct-construction]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/direct-construction
[approach-stack-operations]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/stack-operations
[approach-linear-recursion]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/linear-recursion
[approach-divide-and-conquer]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/divide-and-conquer
[approach-over-engineered]: https://exercism.org/tracks/cpp/exercises/reverse-string/approaches/over-engineered
