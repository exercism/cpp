#include "example.h"

namespace rail_fence_cipher {

std::string encode(const std::string& plaintext, int num_rails) {
    if (num_rails <= 1) return plaintext;

    const auto stride = num_rails * 2 - 2;
    const auto length = plaintext.size();

    std::string result(length, ' ');
    auto dst = result.begin();

    for (int rail = 0; rail < num_rails; ++rail) {
        for (size_t pos = rail; pos < length; pos += stride) {
            *dst++ = plaintext[pos];
            if (0 < rail && rail < num_rails - 1) {
                size_t next_pos = pos + stride - rail * 2;
                if (next_pos < length) *dst++ = plaintext[next_pos];
            }
        }
    }

    return result;
}

std::string decode(const std::string& ciphertext, int num_rails) {
    if (num_rails <= 1) return ciphertext;

    const auto stride = num_rails * 2 - 2;
    const auto length = ciphertext.size();

    std::string result(length, ' ');
    auto src = ciphertext.cbegin();

    for (int rail = 0; rail < num_rails; ++rail) {
        for (size_t pos = rail; pos < length; pos += stride) {
            result[pos] = *src++;
            if (0 < rail && rail < num_rails - 1) {
                size_t next_pos = pos + stride - rail * 2;
                if (next_pos < length) result[next_pos] = *src++;
            }
        }
    }

    return result;
}

}  // namespace rail_fence_cipher
