# Instructions append

## Some Additional Notes for C++ Implementation

This exercise uses the [vector container][vector].
You might find it useful to use the [algorithm][algorithm] header to solve this exercise.

Some of the algorithm functions need [`iterators`][iterator] as arguments.
Those can be seen as markers of where a container starts and ends.
If you want to cover the complete container, you start with `my_container.begin()` and end with `my_container.end()`.
If you just want the elements 2, 3, and 4 of a vector you could use `my_vector.begin() + 2` and `my_vector.begin() + 4`.

The last tests check for [immutability][immutability].
None of the functions that you are tasked to write should change the scores of the game.

If you want some extra practice, you can implement a function that adds new scores to the game.

[vector]: https://en.cppreference.com/w/cpp/container/vector
[algorithm]: https://en.cppreference.com/w/cpp/algorithm
[immutability]: https://en.wikipedia.org/wiki/Immutable_object
[iterator]: https://www.learncpp.com/cpp-tutorial/introduction-to-iterators/
