#pragma once

#include <string>

namespace run_length_encoding {
std::string encode(const std::string& text);
std::string decode(const std::string& text);
}  // namespace run_length_encoding
