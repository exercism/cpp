#pragma once

#include <memory>
#include <stdexcept>

namespace linked_list {
    template<typename T>
    class Node {
        public:
            T data;
            std::shared_ptr<Node<T>> next;
            std::shared_ptr<Node<T>> previous;
    };

    template<typename T>
    class List {
        public:
            void push(T entry) {
                auto new_element = std::make_shared<Node<T>>(); 
                if (!head) {
                    head = new_element;
                    tail = head;
                } else {
                    tail->next = new_element;
                    new_element->previous = tail;
                    tail = new_element;
                }
                tail->data = entry;
                current_size++;
            }

            void unshift(T entry) {
                auto new_element = std::make_shared<Node<T>>(); 
                if (!head) {
                    head = new_element;
                    tail = head;
                } else {
                    new_element->next = head;
                    head->previous = new_element;
                    head = new_element;
                }
                head->data = entry;
                current_size++;
            }

            T pop() {
                if (!tail) throw new std::runtime_error("Cannot pop from empty list.");
                if (tail == head) head.reset();
                T data = tail->data;

                if (tail->previous) {
                    tail = tail->previous;
                    tail->next.reset(); 
                } else {
                    tail.reset();
                }
                current_size--;
                return data;
            }

            T shift() {
                if (!head) throw new std::runtime_error("Cannot shift from empty list.");
                if (tail == head) tail.reset();
                T data = head->data;

                if (head->next) {
                    head = head->next;
                    head->previous.reset(); 
                } else {
                    head.reset();
                }
                current_size--;
                return data;
            }

            bool erase(T entry) {
                auto ptr = head;
                while(ptr && ptr->data != entry) {
                    ptr = ptr->next;
                }
                if(!ptr) return false;
                current_size--;
                if (ptr == head) {
                    if (head->next) {
                        head = head->next;
                        head->previous.reset();
                    } else {
                        head.reset();
                    }
                }
                else if (ptr == tail) {
                    if (tail->previous) {
                        tail = tail->previous;
                        tail->next.reset();
                    } else {
                        tail.reset();
                    }
                }
                else {
                    ptr->next->previous = ptr->previous;
                    ptr->previous->next = ptr->next;
                }
                return true;
            }

            size_t count() {
                return current_size;
            }
        private:
            std::shared_ptr<Node<T>> head;
            std::shared_ptr<Node<T>> tail;
            size_t current_size{};
    };

} // namespace linked_list
