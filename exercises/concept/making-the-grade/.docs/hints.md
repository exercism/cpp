# Hints

## General

- `while` loops are used for _indefinite_ (uncounted) iteration
- `for` loops are used for _definite_, (counted) iteration.
- The keywords `break` and `continue` help customize loop behavior.
- `std::to_string()` from `string` library can be used to convert a integer to string

Also being familiar with the following can help with completing the tasks:

- [`vectors`][vectors]: indexing, size, [`<vector>.emplace_back`][emplace], [`<vector>.pop_back()`][pop].
- [`string`][string]: using the `+` to concatenate strings, integer to string conversion, [`to_string`][to\_string].

## 1. Rounding Scores

- `While` loops will continue to execute until their test condition evaluates to `False`.
- `<vector>.pop_back()` will remove and return the last item in a `vector`.

## 2. Non-Passing Students

- A results counter does need to be set up and _incremented_ -- you'll want to `return` the count of non-passing students when the loop terminates.

## 3. The "Best"

- - Having an empty `vector` to add the "best" marks to is helpful here.
- `<vector>.emplace_back()` can help add things to the results `vector`.

## 4. Calculating Letter Grades

- These are _lower thresholds_. The _lower threshold_ for a "D" is a score of **41**, since an "F" is **<= 40**.
- `static_cast<int>` without parameters should round off increments nicely.
- You are expected to return an array, not a vector.

## 5. Matching Names to Scores

- If both containers are the same length and sorted the same way, could you use the `index` from one to retrieve a `value` from the other?
- `std::to_string(int)` can be used to convert a number to string.
- Don't forget the follow the format of the example's output.

## 6. A "Perfect" Score

- There may be or may not be a student with a score of 100, and you can't return an empty string without checking **all** scores.
- The `control flow` statements `continue` and `break` may be useful here to move past unwanted values.

[vectors]: https://en.cppreference.com/w/cpp/container/vector
[string]: https://en.cppreference.com/w/cpp/string/basic_string
[to\_string]: https://en.cppreference.com/w/cpp/string/basic_string/to_string
[emplace]: https://en.cppreference.com/w/cpp/container/vector/emplace_back
[pop]: https://en.cppreference.com/w/cpp/container/vector/pop_back