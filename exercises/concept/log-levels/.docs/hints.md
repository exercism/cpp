# Hints

## General

- [This tutorial][strings-tutorial] offers a nice introduction to C++ strings.
- The `std::basic_string` class has many useful [built-in methods][cpp-reference-string].

## 1. Get the message from a log line

- The built-in methods offer some ways to [find][cpp-reference-string-find] text in a string.
- The built-in methods can help us [get a portion][cpp-reference-string-substr] of a string

## 2. Get the log level from a log line

There are several ways to concatenate strings, the simplest is using the [`+` operator][cpp-reference-string-concatenation] but there are [more advanced ways][cpp-reference-printf] as well.

[strings-tutorial]: https://www.learncpp.com/cpp-tutorial/4-4b-an-introduction-to-stdstring/
[cpp-reference-string]: https://en.cppreference.com/w/cpp/string/basic_string
[cpp-reference-string-find]: https://en.cppreference.com/w/cpp/string/basic_string/find
[cpp-reference-string-substr]: https://en.cppreference.com/w/cpp/string/basic_string/substr
[cpp-reference-string-concatenation]: https://en.cppreference.com/w/cpp/string/basic_string/operator%2B
[cpp-reference-printf]: https://en.cppreference.com/w/cpp/io/c/fprintf
