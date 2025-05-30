#pragma once

#include <string_view>
#include <unordered_map>
#include <vector>

namespace parallel_letter_frequency {

[[nodiscard]] std::unordered_map<char, size_t> frequency(
    std::vector<std::string_view> const& texts);

}
