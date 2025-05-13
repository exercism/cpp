#pragma once

#include <string>

namespace affine_cipher {

std::string encode(const std::string& input, int a, int b);
std::string decode(const std::string& input, int a, int b);

}  // namespace affine_cipher