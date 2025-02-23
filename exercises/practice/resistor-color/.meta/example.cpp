#include "resistor_color.h"

namespace resistor_color {
const std::vector<std::string> resistor_colors{
    "black", "brown", "red",    "orange", "yellow",
    "green", "blue",  "violet", "grey",   "white"};

int color_code(const std::string& color) {
    for (size_t i{}; i <= resistor_colors.size(); ++i) {
        if (resistor_colors.at(i) == color) {
            return i;
        }
    }
    return -1;
}

std::vector<std::string> colors() { return resistor_colors; }
}  // namespace resistor_color
