# Tests

Running the tests involves running `cmake -G` and then using the build command appropriate for your platform.
Detailed instructions on how to do this can be found on the [Running the Tests][cpp-tests-instructions] page for C++ on exercism.org.

## Passing the Tests

Get the first test compiling, linking and passing by following the [three rules of test-driven development][three-laws-of-tdd].
Create just enough structure by declaring namespaces, functions, classes, etc., to satisfy any compiler errors and get the test to fail.
Then write just enough code to get the test to pass.
Once you've done that, uncomment the next test by moving the following line past the next test.

```C++
#if defined(EXERCISM_RUN_ALL_TESTS)
```

This may result in compile errors as new constructs may be invoked that you haven't yet declared or defined.
Again, fix the compile errors minimally to get a failing test, then change the code minimally to pass the test, refactor your implementation for readability and expressiveness and then go on to the next test.

Try to use standard C++17 facilities in preference to writing your own low-level algorithms or facilities by hand.

[cpp-tests-instructions]: https://exercism.org/docs/tracks/cpp/tests
[three-laws-of-tdd]: http://butunclebob.com/ArticleS.UncleBob.TheThreeRulesOfTdd
