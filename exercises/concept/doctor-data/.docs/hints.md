# Hints

## General

- Pay attention to any enumerators you come across.
- The tests can only be run when you have implemented every task.
  To see the test results you only need a rough skeleton of the functions and classes.
- Every function, class, and enumeration that is used by the tests must be declared in the header file.

## 1. Try to extract some first clues

- The class and the enum are in different namespaces.
- Use a `class enum` for `System`
- You can either have two constructors, or one constructor with a default argument.

## 2. Find more details

- The first `REQUIRE` line checks for the default `System`.
- `generation` seems to increase by one in a cloned vessel.
- The `System` seems to be untouched by the cloning process.

## 3. Look into the inner workings

- The `shoot_buster` member function seems to be dependent on an internal counter.
