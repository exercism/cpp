#include <cctype>

#include "pangram.h"

namespace {

bool found_letter(char a, const std::string &s) {
    for (auto c : s) {
        if (tolower(c) == a) {
            return true;
        }
    }
    return false;
}

}  // namespace

namespace pangram {

bool is_pangram(const std::string &s) {
    char letters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                      'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
                      's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (char l : letters) {
        if (!found_letter(l, s)) {
            return false;
        }
    }
    return true;
}

}  // namespace pangram
