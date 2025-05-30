# Introduction

Loops are used to repeatedly execute some logic.
The two most common types are the `while loop` (indefinite looping) and the `for loop` (definite, or counted looping).
There is also the `for each` loop, that will come up in a later concept.


## General Syntax

The `for loop` consists of a header and a code block that contains the body of the loop wrapped in curly brackets.
The header consists of 3 components separated by semicolons `;`:  init-statement, condition, and another expression.
Each of these may be empty.

```cpp
for (init-statement; condition; expression) {
  some_statement;
}
```

- The **init** component is some code that runs only once before the loop starts.
- The **condition** component must be some expression that evaluates to a boolean and controls when the loop should stop.
The code inside the loop will run as long as this condition evaluates to true.
As soon as this expression evaluates to false, no more iterations of the loop will run.
- The **expression** component is some code that will run at the end of each iteration.


The `while loop` executes its body as long as its condition check is true.
The code snippet below shows how to transform a for into a while loop.

```cpp
init-statement;
while(condition) {
    some_statement;
    expression;
}
```

## Interlude: Increments and Decrements

When working with loops is often required to add 1 or subtract 1 from a counter variable.
This is so common, that the operation has special operators: `++` and `--`.

They come in a prefix and a postfix form.
The prefix changes the variable before use in the statement and the postfix version afterward.
You probably want the prefix version most of the time.

```cpp
int a{3};
int b{--a};
// b is 2, a is now 2
int c{a++};
// c is 2, a is now 3
```

## For Loops - An example

The init component usually sets up a counter variable, the condition checks whether the loop should be continued or stopped and the post component usually increments the counter at the end of each repetition.

```cpp
int sum{0};
for (int i{1}; i < 10; ++i) {
  sum += i;
}
```

This loop will sum the numbers from `1` to `9` (including `9`).

## Break and Continue

Inside a loop body, you can use the `break` keyword to stop the execution of the loop entirely:

```cpp
int sum{2};
while(true) {
    sum *= 2;
    if (sum > 1000)
        break;
}
// sum is now 1024
```

In contrast, the keyword `continue` only stops the execution of the current iteration and continues with the next one:

```cpp
int equal_sum{0};
for (int i{1}; i < 7; ++i) {
  if  (i%2 == 1) {
    continue;
  }
  equal_sum += i;
}
// equal_sum is now 12
```
> Note: it is usually easier to understand the logic of the loop, when the use of `break` and `continue` is minimized or entirely avoided.
