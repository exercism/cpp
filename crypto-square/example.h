#if !defined(CRYPTO_SQUARE_H)
#define CRYPTO_SQUARE_H

#include <string>
#include <vector>

namespace crypto_square
{

class cipher
{
public:
    cipher(std::string const& text);

    std::string normalize_plain_text() const;

    std::size_t size() const;

    std::vector<std::string> plain_text_segments() const;

    std::string cipher_text() const;

    std::string normalized_cipher_text() const;

private:
    std::string const text_;
};

}

#endif
