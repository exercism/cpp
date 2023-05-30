# Instructions

Mary-Emilia, Mary-Eugenia, and Mary-Laura are called into the kitchen by their Auntie Becky.
They have to answer for the missing cookies from the cookie jar.

As they spend a lot of time together, the triplet has developed a secret body language.
The three have agreed on certain movements that can be translated into common excuses.

In this exercise, you're going to write some code to help Mary-Emilia, Mary-Eugenia, and Mary-Laura get out of trouble.

You have three tasks, all related to telling a convincing lie to their Auntie Becky.

## 1. Preparation: Write down the excuses for the body language

It is your task to distribute the secret signs among the triplet.

When someone scratches their knee, the location should be "the garden".
A rub on the chin has "the treehouse" and a raised shoulder is the sign for "the attic".
They also prepared to pin the blame on someone else.
A cough means that they target "the parrot".
A tap with the foot indicates "the cat".
To blame "the neighbor", they adjust their socks.

The body language functions are already declared in the `body_language.h` header file.
Look up the correct namespace and function names and define them in the girls source files of your choice.

```cpp
#include "body_language.h"
mary::knee_scrached();
// => "the garden"
```

## 2. Training: Practice the excuses

Their auntie is asking all of them together where they have been and who they have seen in the kitchen.
The trio wants her to be unaware of their secret communication.

Auntie Becky is using the `auntie_answers.h` header for communication.
She should not be able to translate the body language.

The triplet gets their excuses from the body language and relays the answers to Aunt Becky. 
The `all_three.cpp` source file has to be paired up with both headers.

Prepare both files accordingly with the correct includes - if any adjustment is necessary.


## 3. Execution: Get out of trouble

Now is the time to get everything together.
Act natural!

Becky is asking where you have been.
A girl rubs her chin.
She seems convinced.

Aunt Becky wants to know if they have seen anyone near the kitchen.
One of the girls is adjusting her left sock.
Becky goes outside to find the culprit.
Time to flee the scene.

Declare the `where_where_you()` and the `who_was_near_the_kitchen()` functions in the `auntie_answers.h` header. They should be in the `becky` namespace, and return strings.

Then define the functions in the `all_three.cpp` source file according to the two body language hints above.