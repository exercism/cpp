#include <regex>

#include "isbn_verifier.h"

namespace isbn_verifier {
bool is_valid(const std::string& isbn) {
    auto raw_string = std::regex_replace(isbn, std::regex("-"), "");

    if (!std::regex_match(raw_string, std::regex("\\d{9}[0-9X]"))) {
        return false;
    }

    int sum{0};

    for (size_t i = 0; i < 9; ++i) {
        sum += (raw_string[i] - '0') * (10 - i);
    }

    sum += ((raw_string[9] == 'X') ? 10 : raw_string[9] - '0');

    return sum % 11 == 0;
}

}  // namespace isbn_verifier
