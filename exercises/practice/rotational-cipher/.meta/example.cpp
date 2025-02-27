#include <sstream>

#include "rotational_cipher.h"

namespace rotational_cipher {
std::string rotate(const std::string& text, int shift_key) {
    std::ostringstream encoded_text;

    for (char c : text) {
        if (c >= 'a' && c <= 'z') {
            c = (c + shift_key - 'a') % 26 + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c + shift_key - 'A') % 26 + 'A';
        }
        encoded_text << c;
    }
    return encoded_text.str();
}

}  // namespace rotational_cipher
