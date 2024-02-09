## Implementation Hints

We have provided the general structure of a `List` class for you.
It has the private variables `head` of type `Element*` and `current_size` of type `size_t` that you can use.

The `Element` struct was given as well, it has two variables: `data` of type `int` and `next` of type `Element*`.

You can see the details in `simple_linked_list.h`. You do not have to change that file, but you can if it fits your needs.

The tests use the functions as they are supplied in `simple_linked_list.cpp`, don't change their signature. You can add more functions and members if you want to.

## Can I use smart pointers?

Although the header-file includes raw pointers, you are free to choose a different implementation.
