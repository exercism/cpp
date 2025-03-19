#include <stdexcept>

#include "simple_linked_list.h"

namespace simple_linked_list {
List::~List() {
    while (head != nullptr) {
        Element* next = head->next;
        delete head;
        head = next;
    }
}

std::size_t List::size() const { return current_size; }

void List::push(int entry) {
    auto element = new Element{entry};
    element->next = head;
    head = element;
    current_size++;
}

int List::pop() {
    if (head == nullptr) {
        throw std::runtime_error("Cannot pop from empty list.");
    } else {
        auto element = head;
        head = head->next;
        int data = element->data;
        delete element;
        current_size--;
        return data;
    }
}

void List::reverse() {
    Element* new_head = nullptr;
    while (head != nullptr) {
        auto temp = new_head;
        new_head = head;
        head = head->next;
        new_head->next = temp;
    }
    head = new_head;
}
}  // namespace simple_linked_list
