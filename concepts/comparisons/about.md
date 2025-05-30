# About

In C++, you can compare values using the comparison operators.

| Comparison        | Operator  |
| ------------------| --------- |
| equal             | `==`      |
| not equal         | `!=`      |
| less              | `<`       |
| less or equal     | `<=`      |
| greater           | `>`       |
| greater or equal  | `>=`      |

The result of these comparisons is always a boolean value:

```cpp
int a{3};

bool eq1 = a != 4; // true

bool eq2 = a > 5;  // false
```

The operators `==` and `!=` check whether a value is equal to another or not, respectively.
Here are some common examples:

```cpp
bool eq3 = 2 == 3; // false, integer comparison

bool eq4 = 2.1 != 2.2; // true, float comparison

bool eq5 = "hello" == "hello"; // true, string comparison
```

The other operators check if one value is greater than (`>`), greater or equal to (`>=`), less than (`<`), and less or equal to (`<=`) to another value.
This kind of comparison is available for numbers and strings.
When comparing strings, the dictionary order (also known as lexicographic order) is followed.

```cpp
bool eq6 = 2 > 3; // false, integer comparison

bool eq7 = 1.2 < 1.3; // true, float comparison

bool eq8 = "Hello" < "World"; // true, string comparison
```
