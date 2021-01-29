# Hello World

The classical introductory exercise. Just say "Hello, World!".

["Hello, World!"](http://en.wikipedia.org/wiki/%22Hello,_world!%22_program) is
the traditional first program for beginning programming in a new language
or environment.

The objectives are simple:

- Write a function that returns the string "Hello, World!".
- Run the test suite and make sure that it succeeds.
- Submit your solution and check it at the website.

If everything goes well, you will be ready to fetch your first real exercise.

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

This is an exercise to introduce users to using Exercism [http://en.wikipedia.org/wiki/%22Hello,_world!%22_program](http://en.wikipedia.org/wiki/%22Hello,_world!%22_program)

## Submitting Incomplete Solutions
It's possible to submit an incomplete solution so you can see how others have completed the exercise.
