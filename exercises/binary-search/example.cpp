#include "binary_search.h"

namespace binary_search {

int find(std::vector<int> const& data, int value)
{
    int lpos = 0;
    int rpos = data.size() - 1;
    int mid = 0;

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
