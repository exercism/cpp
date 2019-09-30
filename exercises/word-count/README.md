# Word Count

Given a phrase, count the occurrences of each _word_ in that phrase.

For the purposes of this exercise you can expect that a _word_ will always be one of:

1. A _number_ composed of one or more ASCII digits (ie "0" or "1234") OR
2. A _simple word_ composed of one or more ASCII letters (ie "a" or "they") OR
3. A _contraction_ of two _simple words_ joined by a single apostrophe (ie "it's" or "they're")

When counting words you can assume the following rules:

1. The count is _case insensitive_ (ie "You", "you", and "YOU" are 3 uses of the same word)
2. The count is _unordered_; the tests will ignore how words and counts are ordered
3. Other than the apostrophe in a _contraction_ all forms of _punctuation_ are ignored
4. The words can be separated by _any_ form of whitespace (ie "\t", "\n", " ")

For example, for the phrase `"That's the password: 'PASSWORD 123'!", cried the Special Agent.\nSo I fled.` the count would be:

```text
that's: 1
the: 2
password: 2
123: 1
cried: 1
special: 1
agent: 1
so: 1
i: 1
fled: 1
```

## Getting Started

Make sure you have read the [Installing](https://exercism.io/tracks/cpp/installation) and
[Running the Tests](https://exercism.io/tracks/cpp/tests) pages for C++ on exercism.io.
This covers the basic information on setting up the development
environment expected by the exercises.

## Passing the Tests

Get the first test compiling, linking and passing by following the [three
rules of test-driven development](http://butunclebob.com/ArticleS.UncleBob.TheThreeRulesOfTdd).
Create just enough structure by declaring namespaces, functions, classes,
etc., to satisfy any compiler errors and get the test to fail.  Then write
just enough code to get the test to pass.  Once you've done that,
uncomment the next test by moving the following line past the next test.

```C++
#if defined(EXERCISM_RUN_ALL_TESTS)
```

This may result in compile errors as new constructs may be invoked that
you haven't yet declared or defined.  Again, fix the compile errors minimally
to get a failing test, then change the code minimally to pass the test,
refactor your implementation for readability and expressiveness and then
go on to the next test.

Try to use standard C++14 facilities in preference to writing your own
low-level algorithms or facilities by hand.  [CppReference](http://en.cppreference.com/)
is a wiki reference to the C++ language and standard library.  If you
are new to C++, but have programmed in C, beware of
[C traps and pitfalls](http://www.slideshare.net/LegalizeAdulthood/c-traps-and-pitfalls-for-c-programmers).

## Source

This is a classic toy problem, but we were reminded of it by seeing it in the Go Tour.

## Submitting Incomplete Solutions
It's possible to submit an incomplete solution so you can see how others have completed the exercise.
