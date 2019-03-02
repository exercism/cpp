#include "binary_search.h"

namespace binary_search {

size_t find(std::vector<int> const& data, int value)
{
    size_t lpos = 0;
    size_t rpos = data.size() - 1;
    size_t mid = 0;

    while (lpos <= rpos)
    {
        mid = (lpos + rpos)/2;
        
        if (value < data[mid]) {
            rpos = mid - 1;
        } else if (value > data[mid]) {
            lpos = mid + 1;
        }
        
        if (data[mid] == value) { 
            return mid; 
        }
    }
        return -1;
}

}
