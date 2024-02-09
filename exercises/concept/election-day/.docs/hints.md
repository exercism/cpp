# Hints

## General

- Although you are receiving a `reference` to an `ElectionResult`, you can access its members with the dot `.` notation, as if it wasn't a `reference`!
- You can get a `reference` for a variable by using the `&` operator, e.g `int&`.
- If you are unsure how `references` work, try reading [Learn C++: References][learncpp-references].

## 1. Get the number of votes from an `ElectionResult`

- You need to create a function with a `reference` to an `ElectionResult`, in other words, a `ElectionResult&`.
- - Although you are receiving a `reference` to an `ElectionResult`, you can access its members with the dot `.` notation, as if it wasn't a `reference`!

## 2. Increment the votes of an `ElectionResult`

- You need to create a function with a `reference` to an `ElectionResult`, in other words, a `ElectionResult&`.
- - Although you are receiving a `reference` to an `ElectionResult`, you can change its member variables with the dot `.` notation, as if it wasn't a `reference`!

## 3. Vote counting and Presidency 

- You can iterate a reference to a `vector` like a normal vector with a loop.
- You can get the size of a vector with `myvector.size()`.


[learncpp-references]: https://www.learncpp.com/cpp-tutorial/lvalue-references/