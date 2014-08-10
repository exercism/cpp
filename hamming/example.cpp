#include "hamming.h"
#include <algorithm>

namespace hamming
{

int compute(std::string const& lhs, std::string const& rhs)
{
    if (rhs.length() < lhs.length()) {
        return compute(rhs, lhs);
    }
    int count = 0;
    for (auto p = std::mismatch(lhs.begin(), lhs.end(), rhs.begin());
            p.first != lhs.end();
            p = std::mismatch(p.first, lhs.end(), p.second)) {
        ++p.first;
        ++p.second;
        ++count;
    }
    return count;
}

}
