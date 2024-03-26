#include "trinary.h"

namespace trinary {

int to_decimal(std::string const &text) {
    int result = 0;
    for (const char digit : text) {
        if (digit < '0' || digit > '2') {
            return 0;
        }
        result *= 3;
        result += digit - '0';
    }
    return result;
}

}  // namespace trinary
