#pragma once

#include <vector>

namespace sublist {
    enum class List_comparison { equal, sublist, superlist, unequal };
    
    List_comparison sublist(const std::vector<int>& list_one, const std::vector<int>& list_two);
}  // namespace sublist
