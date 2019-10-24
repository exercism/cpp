# Accumulate
Implement the `accumulate` operation, which, given a collection and an
operation to perform on each element of the collection, returns a new
collection containing the result of applying that operation to each element of
the input collection.

## Getting Started

Make sure you have read the [Installing](https://exercism.io/tracks/cpp/installation) and
[Running the Tests](https://exercism.io/tracks/cpp/tests) pages for C++ on exercism.io.
This covers the basic information on setting up the development
environment expected by the exercises.


## Passing the Tests

Given the collection of numbers as a vector of integers:

{1, 2, 3, 4, 5}

And the operation named with some string:

"square"

The only possible operations are "square", "cube", "square root", and "factorial". You will need to write functions that perform some of these operations yourself since you are not allowed to use any additional libraries except for vector.

Your code should be able to produce the collection of squares through returning a vector named "output":

{1, 4, 9, 16, 25}

Check out the test suite to see the expected function signature.

Do this without including any additional libraries except for <vector>.
