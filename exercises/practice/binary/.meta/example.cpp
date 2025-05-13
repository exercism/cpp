#include "binary.h"

namespace binary {

int convert(std::string const& text) {
    int result = 0;
    if (text.length() > sizeof(int) * 8 - 1) {
        return 0;
    }
    for (const char x : text) {
        result <<= 1;
        if (x == '1') {
            result |= 1;
        } else if (x != '0') {
            return 0;
        }
    }
    return result;
}

}  // namespace binary
