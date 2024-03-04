# Hints

## 1. Estimate the preparation time

- Use the vector's [`size()`][size-func] to determine the number of layers (length of the layers slice).

## 2. Compute the amounts of noodles and sauce needed

- First, set up an `amount` object to track the amount of noodles and sauce.
- Use a [for-loop][for-loop] to iterate through the layers.
- If you encounter a `"noodles"` or `"sauce"` layer in your loop, increase the amount stored in the `amount` object accordingly.

## 3. Add the secret ingredient

- Revisit [vectors][concept-vector] to find out how to retrieve an element from a a vector and how to replace an element in a vector.
- The index of the last element in a vector `a` is `a.size() - 1` or you can use `a.back()` directly.

## 4. Scale the recipe

- First make a new slice of the same size as the input slice
- Use a [for-loop][for-loop] to iterate through the input slice and generate the output slice

## 5. Unlock the Family Secret

- You can re-use your code from task 3.
- This tasks needs [function overloading][function overloading].

[size-func]: https://en.cppreference.com/w/cpp/container/vector/size
[concept-vector]: https://exercism.org/tracks/cpp/concepts/vector-arrays
[for-loop]: https://exercism.org/tracks/cpp/concepts/loops
[function overloading]: https://www.learncpp.com/cpp-tutorial/introduction-to-function-overloading/
