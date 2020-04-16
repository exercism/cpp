The key thing to remember about C++ strings is that they are mutable objects representing text as a sequence of Unicode characters (letters, digits, punctuation, etc.).

Manipulating a string can be be done by calling one of its [methods][methods]. C++ strings are not immutable and their value can be changed after definition.

A string is delimited by double quotes (`"`) characters. Some special characters need [escaping][escaping] using the backslash (`\`) character.

Finally, there area many ways to concatenate a string. The simplest one is by using the [`+` operator][cpp-reference-string-concatenation]. For any string formatting more complex than simple concatenation [`sprintf`][cpp-reference-printf] is preferred.

[methods]: https://en.cppreference.com/w/cpp/string/basic_string
[escaping]: https://en.cppreference.com/w/cpp/language/escape
[cpp-reference-string-concatenation]: https://en.cppreference.com/w/cpp/string/basic_string/operator%2B
[cpp-reference-printf]: https://en.cppreference.com/w/cpp/io/c/fprintf
