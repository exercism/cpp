# Instructions

Your task is to convert a number into a string that contains raindrop sounds corresponding to certain potential factors.
A factor is a number that evenly divides into another number, leaving no remainder.
The simplest way to test if one number is a factor of another is to use the [modulo operation][modulo].

The rules of `raindrops` are that if a given number:

- has 3 as a factor, add 'Pling' to the result.
- has 5 as a factor, add 'Plang' to the result.
- has 7 as a factor, add 'Plong' to the result.
- _does not_ have any of 3, 5, or 7 as a factor, the result should be the digits of the number.

## Examples

- 28 has 7 as a factor, but not 3 or 5, so the result would be "Plong".
- 30 has both 3 and 5 as factors, but not 7, so the result would be "PlingPlang".
- 34 is not factored by 3, 5, or 7, so the result would be "34".

## Things to consider
- You're expected to define a function named *convert* inside the *raindrops* namespace.
- Notice that there are two different files in the editor: the *raindrops.cpp* file and the *raindrops.h* file. The former is where you want to actually define your function, while the latter (*raindrops.h*) is where you want to import all the things you need **and** declare the function. A function declaration tells the compiler about a function name and how to call the function. The actual body of the function can be defined separately. This body (which is the actual stuff that's supposed to do the job) is what has to go in the *raindrops.cpp* file.

For more information about the concepts mentioned above, check the following resources:

- [Testing on the C++ track](https://exercism.org/docs/tracks/cpp/tests)
- [C++ Functions](https://www.tutorialspoint.com/cplusplus/cpp_functions.htm)
- [What is the difference between a .cpp file and a .h file?](https://stackoverflow.com/questions/875479/what-is-the-difference-between-a-cpp-file-and-a-h-file)

[modulo]: https://en.wikipedia.org/wiki/Modulo_operation
