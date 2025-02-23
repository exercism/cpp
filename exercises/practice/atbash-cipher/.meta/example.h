#if !defined(ATBASH_CIPHER_H)
#define ATBASH_CIPHER_H

#include <string>

namespace atbash_cipher {

std::string encode(std::string const& plaintext);
std::string decode(std::string const& ciphertext);

}  // namespace atbash_cipher
#endif
