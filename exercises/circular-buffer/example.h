#if !defined(CIRCULAR_BUFFER_H_)
#define CIRCULAR_BUFFER_H_

#include <vector>
#include <stdexcept>

namespace circular_buffer {

template <typename ValueType>
class circular_buffer {
public:
    circular_buffer(std::size_t capacity) 
        : buffer_(capacity), head_(0), tail_(0) {}
    ValueType read();
    void write(ValueType item);
    void overwrite(ValueType item);
    void clear() { head_ = 0; tail_ = 0; }

private:
    std::vector<ValueType> buffer_;
    std::size_t head_;
    std::size_t tail_;

    void insert(ValueType item);
    bool is_empty() const { return head_ == tail_; }
    bool is_full() const { return head_ == (tail_ + 1) % (buffer_.size() + 1); }
};

template <typename ValueType>
ValueType circular_buffer<ValueType>::read() {
    if (is_empty()) throw std::domain_error("Circular buffer is empty."); 
    return buffer_[head_++ % buffer_.size()];
}

template <typename ValueType>
void circular_buffer<ValueType>::write(ValueType item) {
    if (is_full()) throw std::domain_error("Circular buffer is full.");
    insert(item);
}

template <typename ValueType>
void circular_buffer<ValueType>::overwrite(ValueType item) {
    if (is_full()) head_ = ++head_ % buffer_.size();
    insert(item);
}

template <typename ValueType>
void circular_buffer<ValueType>::insert(ValueType item) {
    buffer_[tail_++ % buffer_.size()] = item;
}

} // namespace circular_buffer

#endif // !CIRCULAR_BUFFER_H_