#include "rail_fence_cipher.h"

#include <algorithm>
#include <vector>

namespace rail_fence_cipher {

std::vector<std::pair<int, int>> fence_pattern(int rails, int size) {
    std::vector<int> pattern;
    pattern.reserve(rails + rails  - 2);
    for (int i = 0; i < rails; ++i)
        pattern.push_back(i);
    for (int i = rails - 2; i > 0; --i)
        pattern.push_back(i);

    std::vector<std::pair<int, int>> fence(size);
    for (int i = 0, pos = 0; i < size; ++i)
        fence[i] = {pattern[pos++ % pattern.size()], i};
    std::sort(fence.begin(), fence.end());
    return fence;
}

std::string encode(const std::string& msg, int rails) {
    auto fence = fence_pattern(rails, msg.size());

    std::string encoded;
    for (const auto& f : fence)
        encoded += msg[f.second];
    return encoded;
}

std::string decode(const std::string& msg, int rails) {
    auto fence = fence_pattern(rails, msg.size());

    std::vector<std::pair<int, char>> fence_msg(msg.size());
    for (size_t i = 0; i < msg.size(); ++i)
        fence_msg[i] = {fence[i].second, msg[i]};
    std::sort(fence_msg.begin(), fence_msg.end());

    std::string decoded;
    for (const auto& pair : fence_msg)
        decoded += pair.second;
    return decoded;
}

}  // namespace rail_fence_cipher
