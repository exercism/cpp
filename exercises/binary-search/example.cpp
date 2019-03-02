#include <stdexcept>
#include "binary_search.h"

namespace binary_search {

size_t find(std::vector<int> const& data, int const value)
{
    if(data.empty() || value < data.front() || data.back() < value)    
    {
        throw std::domain_error("Value not in input vector!");
    }
    
    size_t lpos {0};
    size_t rpos {data.size() - 1};
    size_t mid  {0};

    while (lpos <= rpos)
    {
        mid = (lpos + rpos) >> 1;

        if (data.at(mid) == value) 
        { 
            return mid; 
        }
        else
        {
            if (value < data.at(mid)) 
            {
                rpos = mid - 1;
            } 
            else if (value > data[mid]) 
            {
                lpos = mid + 1;
            }
        }
    }
    throw std::domain_error("Value not in input vector!");
}

}
