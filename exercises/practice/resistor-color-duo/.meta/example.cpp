#include "resistor_color_duo.h"

namespace resistor_color_duo {
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

int value(const std::vector<std::string>& colors) {
    return color_code(colors.at(0)) * 10 + color_code(colors.at(1));
}
}  // namespace resistor_color_duo
