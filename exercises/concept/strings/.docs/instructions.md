In this exercise you'll be processing log-lines.

Each log line is a string formatted as follows: `"[<LEVEL>]: <MESSAGE>"`.

There are three different log levels:

- `INFO`
- `WARNING`
- `ERROR`

You have three tasks, each of which will take a log line and ask you to do something with it.

## 1. Get message from a log line

Implement the `log_line::message` method to return a log line's message:

```cpp
log_line::message("[ERROR]: Invalid operation")
// => "Invalid operation"
```

## 2. Get log level from a log line

Implement the `log_line::log_level` method to return a log line's log level, which should be returned in lowercase:

```cpp
log_line::log_level("[ERROR]: Invalid operation")
// => "ERROR"
```

## 3. Reformat a log line

Implement the `log_line::reformat` method that reformats the log line, putting the message first and the log level after it in parentheses:

```cpp
log_line::reformat("[INFO]: Operation completed")
// => "Operation completed (INFO)"
```
