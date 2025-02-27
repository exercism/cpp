#include <sstream>
#include <string>

#include "atbash_cipher.h"

namespace atbash_cipher {

const char ALPHA_START = 'a';
const char ALPHA_END = 'z';

char atbash_transform(char c) {
    return std::isalpha(c) ? ALPHA_END - std::tolower(c) + ALPHA_START : c;
}

std::string encode(std::string const& plaintext) {
    int chunkSize = 5;
    int chunkCounter = 0;
    std::ostringstream os;

    for (std::size_t i = 0; i < plaintext.length(); i++) {
        char currentChar = plaintext.at(i);

        if (std::isalnum(currentChar)) {
            if ((chunkCounter > 0) && ((chunkCounter) % chunkSize == 0)) {
                os << " ";
            }

            os << atbash_transform(currentChar);
            chunkCounter++;
        }
    }

    return os.str();
}

std::string decode(std::string const& ciphertext) {
    std::ostringstream os;

    for (std::size_t i = 0; i < ciphertext.length(); i++) {
        char currentChar = ciphertext.at(i);

        if (std::isalnum(currentChar)) {
            os << atbash_transform(currentChar);
        }
    }

    return os.str();
}

}  // namespace atbash_cipher
