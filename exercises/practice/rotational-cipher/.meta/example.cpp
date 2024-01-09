#include "rotational_cipher.h"

#include <sstream>

namespace rotational_cipher {
    std::string  rotate(const std::string& text, int shiftKey) {

        std::ostringstream encoded_text;

        for(char c : text) {
            if (c >= 'a' && c <= 'z') {
                c = (c + shiftKey - 'a') % 26 + 'a';
            }
            else if (c >= 'A' && c <= 'Z') {
                c = (c + shiftKey - 'A') % 26 + 'A';
            }
            encoded_text << c;
        }
        return encoded_text.str();
    }

}  // namespace rotational_cipher
