#include "circular_buffer.h"

int circular_buffer::circular_buffer::read() {
    if (is_empty()) throw std::domain_error("Circular buffer is empty."); 
    std::size_t index = read_position_++ % buffer_.size();
    int data = buffer_[index];
    occupancy_[index] = false;
    return data;
}

void circular_buffer::circular_buffer::write(int item) {
    if (is_full()) throw std::domain_error("Circular buffer is full.");
    insert(item);
}

void circular_buffer::circular_buffer::overwrite(int item) {
    if (is_full()) occupancy_[read_position_++ % buffer_.size()] = false;
    insert(item);
}

void circular_buffer::circular_buffer::clear() {
    occupancy_.assign(occupancy_.size(), false);
}

bool circular_buffer::circular_buffer::is_empty() const {
    return std::all_of(occupancy_.cbegin(), occupancy_.cend(), [](bool v) { return !v; });
}

bool circular_buffer::circular_buffer::is_full() const {
    return std::all_of(occupancy_.cbegin(), occupancy_.cend(), [](bool v) { return v; });
}

void circular_buffer::circular_buffer::insert(int item) {
    std::size_t index = write_position_++ % buffer_.size();
    buffer_[index] = item;
    occupancy_[index] = true;
}