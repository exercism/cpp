#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

/* Hints:
 * We have provided the general structure of a `List` class for you.
 * It has the private variables `head` of type `Element*` and
 * `current_size` of type `size_t` that you can use.
 *
 * The `Element` class was given as well, it has two public
 * variables: `data` of type `int` and `next` of type `Element*`.
 *
 * You can see the details in `simple_linked_list.h`. You do not have
 * to change that file, but you can if it fits your needs.
 *
 * The tests use the functions below, don't change their signature.
 */

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
}

size_t List::size() {
    // TODO: Return the correct size of the list.
    return 0;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.
    return 0;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.
}
}  // namespace simple_linked_list
