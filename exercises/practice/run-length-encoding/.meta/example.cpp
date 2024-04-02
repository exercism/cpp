#include <cstdlib>
#include <sstream>

#include "run_length_encoding.h"

namespace run_length_encoding {
std::string encode(const std::string& text) {
    if (text.empty()) return "";

    std::ostringstream encoded_text;
    char last{text[0]};
    int counter{0};
    for (char c : text) {
        if (last == c) {
            counter += 1;
        } else {
            if (counter > 1) {
                encoded_text << counter;
            }
            encoded_text << last;
            last = c;
            counter = 1;
        }
    }
    if (counter > 1) {
        encoded_text << counter;
    }
    encoded_text << last;

    return encoded_text.str();
}

std::string decode(const std::string& text) {
    std::ostringstream decoded_text;
    int multi = 0;
    for (char c : text) {
        if (c >= '0' && c <= '9') {
            multi = multi * 10 + c - '0';
        } else {
            if (multi == 0) multi = 1;
            for (int i{}; i < multi; ++i) {
                decoded_text << c;
            }
            multi = 0;
        }
    }
    return decoded_text.str();
}
}  // namespace run_length_encoding
