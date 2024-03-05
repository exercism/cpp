#pragma once

#include <array>
#include <string_view>

namespace kindergarten_garden {

enum class Plants : char { grass = 'G', clover = 'C', radishes = 'R', violets = 'V' };

std::array<Plants, 4> plants(std::string_view diagram,
                             std::string_view student);
}  // namespace kindergarten_garden
