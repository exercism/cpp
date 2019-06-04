#if !defined(CIRCULAR_BUFFER_H_)
#define CIRCULAR_BUFFER_H_

#include <vector>
#include <algorithm>
#include <stdexcept>

namespace circular_buffer {

class circular_buffer {
public:
    circular_buffer(std::size_t capacity) 
        : buffer_(capacity), occupancy_(capacity), read_position_(0), write_position_(0) {}
    int read();
    void write(int item);
    void overwrite(int item);
    void clear();

private:
    std::vector<int> buffer_;
    std::vector<bool> occupancy_;
    std::size_t read_position_;
    std::size_t write_position_;

    void insert(int item);
    bool is_empty() const;
    bool is_full() const;
};

} // namespace circular_buffer

#endif // !CIRCULAR_BUFFER_H_