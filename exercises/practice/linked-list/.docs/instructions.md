# Description

Implement a doubly linked list.

Like an array, a linked list is a simple linear data structure.
Several common data types can be implemented using linked lists, like queues, stacks, and associative arrays.

A linked list is a collection of data elements called *nodes*.
In a *singly linked list* each node holds a value and a link to the next node.
In a *doubly linked list* each node also holds a link to the previous node.

You will write an implementation of a doubly linked list.
Implement a Node to hold a value and pointers to the next and previous nodes.
Then implement a List which holds references to the first and last node and offers an array-like interface for adding and removing items:

- `push` (*insert value at back*);
- `pop` (*remove and return value at back*);
- `shift` (*remove and return value at front*).
- `unshift` (*insert value at front*);
- `erase` (*delete the first element with the specified value from list*);
- `size` (*return number of elements in the list*);

If `pop` or `shift` are called on an empty list, they should return a runtime_error.

Read more about [linked lists on Wikipedia][linked-lists].

[linked-lists]: https://en.wikipedia.org/wiki/Linked_list