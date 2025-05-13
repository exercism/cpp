#pragma once

#include <string>

namespace atbash_cipher {

std::string encode(std::string const& plaintext);
std::string decode(std::string const& ciphertext);

}  // namespace atbash_cipher
