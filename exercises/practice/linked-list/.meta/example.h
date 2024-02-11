#pragma once

#include <memory>
#include <stdexcept>

namespace linked_list {
template <typename T>
struct Node {
    Node() {}
    Node(std::shared_ptr<Node<T>> prev, std::shared_ptr<Node<T>> next, T value)
        : previous(prev), next(next), data(value) {}
    std::shared_ptr<Node<T>> previous;
    std::shared_ptr<Node<T>> next;
    T data;
};

template <typename T>
class List {
   public:
    List() {
        sentinel = std::make_shared<Node<T>>();
        sentinel->next = sentinel;
        sentinel->previous = sentinel;
    }

    void push(T entry) { insert(sentinel->previous, sentinel, entry); }

    void unshift(T entry) { insert(sentinel, sentinel->next, entry); }

    T pop() { return remove(sentinel->previous); }

    T shift() { return remove(sentinel->next); }

    bool erase(T entry) {
        auto ptr = sentinel->next;
        while (ptr->data != entry) {
            if (ptr == sentinel) return false;
            ptr = ptr->next;
        }
        remove(ptr);
        return true;
    }

    size_t count() { return current_size; }

   private:
    std::shared_ptr<Node<T>> sentinel;
    size_t current_size{};

    T remove(std::shared_ptr<Node<T>> to_be_deleted) {
        if (current_size < 1)
            throw std::runtime_error("Cannot remove elements from empty list.");
        T data = to_be_deleted->data;
        to_be_deleted->next->previous = to_be_deleted->previous;
        to_be_deleted->previous->next = to_be_deleted->next;
        --current_size;
        return data;
    }

    void insert(std::shared_ptr<Node<T>> prev, std::shared_ptr<Node<T>> next,
                T value) {
        auto new_element = std::make_shared<Node<T>>(prev, next, value);
        prev->next = new_element;
        next->previous = new_element;
        ++current_size;
    }
};

}  // namespace linked_list
