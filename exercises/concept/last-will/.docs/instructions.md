# Instructions

You work for a prestigious law firm that is specialized in handling unique testament requests.

In this exercise, you are going to open a mysterious vault.
You are the executor of the estate and will assemble the long-kept secret codes of three families to get an account number and the matching code.

To prevent any family from opening the vault alone, it can only be opened by combining their knowledge with a secret modifier that you know from the last will.

You have three tasks, all related to helping the families to open the vault.

## 1. Take your seat in front of the families and lay out your papers

Define a namespace called `estate_executor`.
The code from the next tasks should be defined in the body of the `estate_executor` namespace.

```cpp
namespace some_name {
    // The space between the curly brackets
    // is called body of the  namespace.
}
```

## 2. Find the secret account number

This is your big moment.
Only you have the secret modifier key to reveal the secret account number.

Define the `assemble_account_number(int secret_modifier)` function that takes the secret modifier as an argument and returns the assembled account number as an `int`.

To get the correct number, you have to sum up the `bank_number_part` from each of the three families.

## 3. Last step: Enter the secret code

The instructions in the testament ask you to add all the blue and then all the red fragments.
The resulting code is obtained by multiplying both sums.

Define the `assemble_code()` function that returns the resulting code by combining the fragments from the three families to a single `integer`.
The function does not have any arguments and relies solely on the information in the relevant namespaces from the families.
