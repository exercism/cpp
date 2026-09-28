# Hints

## 1. Set up user types and permissions.

- To handle each `AccountStatus` enumerator, you could use an `if` statement, but a [`switch` statement][switch] is a great alternative.


## 2. Promote trolls only to other trolls.

- You can compare enumerations like any other type with the `!=` and `==` operators.

## 3. Check permissions for different users.

- If you solve the task with a switch statement, [fallthroughs][fallthrough] might be helpful.
- You can use [sequential labels][fallthrough] and the [default][switch] label to group permissions.

## 4. Grant game access and pair players.

- Your main concern are `guest` and `troll` accounts, for other combinations you do not need to split up your logic.

## 5. Build priority queuing.

- If you order your `AccountStatus` enumeration correctly, you can use `static_cast<int>` to compare the enumerators in a compact manner.

[switch]: https://www.learncpp.com/cpp-tutorial/switch-statement-basics/
[fallthrough]: https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
