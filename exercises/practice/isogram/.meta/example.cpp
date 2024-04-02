#include <unordered_set>

#include "isogram.h"

namespace isogram {

bool is_isogram(std::string const& input_str) {
    std::unordered_set<char> chars;

    for (char const ch : input_str) {
        if (isalnum(ch)) {
            auto ret = chars.insert(tolower(ch));
            if (ret.second == false) {
                return false;
            }
        }
    }

    return true;
}

}  // namespace isogram
