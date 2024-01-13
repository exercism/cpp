#include "sublist.h"

#include <algorithm>

namespace sublist {
    bool is_sublist(const std::vector<int>& sublist, const std::vector<int>& superlist) {
        for (auto it{superlist.begin()}; it < superlist.end(); ++it) {
            if (std::equal(sublist.begin(), sublist.end(), it)) return true;
        }
        return false;
    }

    List_comparison sublist(const std::vector<int>& list_one, const std::vector<int>& list_two) {
        if(list_one == list_two){
            return List_comparison::equal;
        }
        if(list_one.size() < list_two.size() && is_sublist(list_one, list_two)) {
            return List_comparison::sublist;
        }
        if(list_one.size() > list_two.size() && is_sublist(list_two, list_one)) {
            return List_comparison::superlist;
        }
        return List_comparison::unequal;
    }
}  // namespace sublist
