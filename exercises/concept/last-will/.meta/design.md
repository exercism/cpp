# Design

## Learning objectives

- Know what namespaces are.
- Know how to define a namespace.
- Know how to use nested namespaces.
- Know the namespace-resolution operator.

## Out of scope

- -

## Concepts

- `namespaces`: know what namespaces are; know how to define a namespace; know how to use nested namespace; know the namespace-resolution operator.

## Prerequisites

- `basics`: know what a variable is; know how to declare and initialize a variable; know how to update a variable; know how to call a function; know how to return a value from a function; know how to define an integer; know how to use mathematical operators on integers; know how to define single- and multiline comments.

## Analyzer

This exercise could benefit from the following rules added to the [analyzer][analyzer]:

- Verify that the `assemble_account_number()` method calls the `bank_number_part()` method from each namespace.
- Verify that the `assemble_code()` method calls the `code_fragment()` method from each namespace.

[analyzer]: https://github.com/exercism/cpp-analyzer
