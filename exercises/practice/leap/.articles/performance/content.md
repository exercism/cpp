# Performance

In this article, we'll find out how to most efficiently calculate if a year is a leap year in C++.

The [approaches page][approaches] lists two idiomatic approaches and mentions three further ideas to solving this exercise:

1. [Using a boolean chain][approach-boolean-chain] with best use of short-circuiting
2. [Using a ternary operator][approach-ternary-operator]
3. Using the `chrono` library (requires C++20)
4. Using the `boost` libraries
5. Using a boolean chain with worst use of short-circuiting as comparison.

## Benchmarks

To benchmark the approaches, we wrote a [small benchmark application][benchmark-application] using [Google's benchmark library][google-benchmark].

The benchmark prepares a vector of 1000 random elements in the range of 1400 to 9999 (limited by the boost library).
Each approach implementation is called and timed with those same 1000 vector elements.
The benchmark is repeated 100 times via the `--benchmark_repetitions` flag.

The aggregated runs give the following results:

| Approach      | Avg. CPU time per call [ns] | CPU time [%] |
|---------------|-----------------------------|--------------|
| Boolean Chain | 12.444                      | 100          |
| Ternary       | 15.86                       | 127          |
| Chrono        | 14.816                      | 119          |
| Boost         | 26.691                      | 214          |
| Inverse Chain | 27.178                      | 218          |

You can see that the boolean chain has the lowest average cpu time.
On the test system the ternary approach was a few nanoseconds slower, which translates to about 27 %.
As expected the worst-case chaining is the slowest approach.
Calling `boost::gregorian::gregorian_calendar::is_leap_year` is almost as slow, probably because a
`boost::gregorian::gregorian_calendar::year` object is constructed for the test.

Here is a box-plot if you want more statistical information:

![Boxplot comparing performance metrics for different algorithms. The plot displays upper and lower whiskers, quartiles, and the median, highlighting variations in data distribution. Notably, Boolean Chain exhibits the best performance with the lowest median values, followed by Chrono, Ternary, Boost, and Inverse Chain, which shows the slowest median performance among the algorithms.](https://assets.exercism.org/images/tracks/cpp/leap/leap_benchmark_boxplot_invertable.svg)

This article discusses very low level differences that might be altered by the compiler or even the processor's own optimizations.
While it is interesting to compare functions in this detail on a theoretical level, they are seldomly the bottleneck at runtime.

~~~~exercism/note
Please notice that benchmarks can be very dependent on the architecture of the benchmarking system, the compiler and its arguments.
The data above was run on an AMD multi-core system and, compiled with g++ version 14.10.0 without optimizations.
~~~~

[approaches]: https://exercism.org/tracks/cpp/exercises/leap/approaches
[approach-boolean-chain]: https://exercism.org/tracks/cpp/exercises/leap/approaches/boolean-chain
[approach-ternary-operator]: https://exercism.org/tracks/cpp/exercises/leap/approaches/ternary-operator
[benchmark-application]: https://github.com/exercism/cpp/blob/main/exercises/practice/leap/.articles/performance/benchmark/leap_benchmark.cpp
[google-benchmark]: https://github.com/google/benchmark
