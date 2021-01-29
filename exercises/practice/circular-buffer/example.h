#if !defined(CIRCULAR_BUFFER_H_)
#define CIRCULAR_BUFFER_H_

#include <vector>
#include <stdexcept>

namespace circular_buffer {

template <typename ValueType>
class circular_buffer {
public:
    circular_buffer(std::size_t capacity) 
        : buffer_(capacity + 1), head_(0), tail_(0) {}
    ValueType read();
    void write(ValueType item);
    void overwrite(ValueType item);
    void clear() { head_ = tail_; }

private:
    std::vector<ValueType> buffer_;
    std::size_t head_;
    std::size_t tail_;

    void push_back(ValueType item);
    void move_position(std::size_t& position) { position = (position + 1) % buffer_.size(); }
    bool is_empty() const { return head_ == tail_; }
    bool is_full() const { return head_ == (tail_ + 1) % buffer_.size(); }
};

template <typename ValueType>
ValueType circular_buffer<ValueType>::read() {
    if (is_empty()) throw std::domain_error("Circular buffer is empty."); 
    ValueType item = buffer_[head_];
    move_position(head_);
    return item;
}

template <typename ValueType>
void circular_buffer<ValueType>::write(ValueType item) {
    if (is_full()) throw std::domain_error("Circular buffer is full.");
    push_back(item);
}

template <typename ValueType>
void circular_buffer<ValueType>::overwrite(ValueType item) {
    if (is_full()) move_position(head_);
    push_back(item);
}

template <typename ValueType>
void circular_buffer<ValueType>::push_back(ValueType item) {
    buffer_[tail_] = item;
    move_position(tail_);
}

} // namespace circular_buffer

#endif // !CIRCULAR_BUFFER_H_