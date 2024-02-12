#include "kindergarten_garden.h"

#include <map>

namespace kindergarten_garden {
const std::map<std::string, std::string> flower_lookup{
    {"G", "grass"}, {"C", "clover"}, {"R", "radishes"}, {"V", "violets"}};

std::array<std::string, 4> plants(std::string diagram, std::string student) {
    size_t row_length{diagram.find('\n')};
    int index = 2 * (student.at(0) - 'A');
    return {flower_lookup.at(diagram.substr(index, 1)),
            flower_lookup.at(diagram.substr(index + 1, 1)),
            flower_lookup.at(diagram.substr(row_length + index + 1, 1)),
            flower_lookup.at(diagram.substr(row_length + index + 2, 1))};
}

}  // namespace kindergarten_garden
