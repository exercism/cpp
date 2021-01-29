# Meetup

Calculate the date of meetups.

Typically meetups happen on the same day of the week.  In this exercise, you
will take a description of a meetup date, and return the actual meetup date.

Examples of general descriptions are:

- The first Monday of January 2017
- The third Tuesday of January 2017
- The wednesteenth of January 2017
- The last Thursday of January 2017

The descriptors you are expected to parse are:
first, second, third, fourth, fifth, last, monteenth, tuesteenth, wednesteenth,
thursteenth, friteenth, saturteenth, sunteenth

Note that "monteenth", "tuesteenth", etc are all made up words. There was a
meetup whose members realized that there are exactly 7 numbered days in a month
that end in '-teenth'. Therefore, one is guaranteed that each day of the week
(Monday, Tuesday, ...) will have exactly one date that is named with '-teenth'
in every month.

Given examples of a meetup dates, each containing a month, day, year, and
descriptor calculate the date of the actual meetup.  For example, if given
"The first Monday of January 2017", the correct meetup date is 2017/1/2.

## Getting Started

Make sure you have read the [Installing](https://exercism.io/tracks/cpp/installation) and
[Running the Tests](https://exercism.io/tracks/cpp/tests) pages for C++ on exercism.io.
This covers the basic information on setting up the development
environment expected by the exercises.

This problem requires you to install and use the Boost [`date_time`](http://www.boost.org/doc/libs/1_58_0/doc/html/date_time.html) library.
CMake will try to find and configure it for you if it is installed on your system.
See the documentation for [`boost::gregorian::date`](https://www.boost.org/doc/libs/1_58_0/doc/html/date_time/gregorian.html#date_time.gregorian.date_class).

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

Jeremy Hinegardner mentioned a Boulder meetup that happens on the Wednesteenth of every month [https://twitter.com/copiousfreetime](https://twitter.com/copiousfreetime)

## Submitting Incomplete Solutions
It's possible to submit an incomplete solution so you can see how others have completed the exercise.
