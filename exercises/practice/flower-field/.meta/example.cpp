#include "flower_field.h"

namespace flower_field {
int score(const std::vector<std::string>& garden, size_t row, size_t column) {
    int flowers{};
    // north
    if (row > 0 && garden.at(row - 1).at(column) == '*') ++flowers;
    // north-east
    if (row > 0 && column < garden.at(0).size() - 1 &&
        garden.at(row - 1).at(column + 1) == '*')
        ++flowers;
    // north-west
    if (row > 0 && column > 0 && garden.at(row - 1).at(column - 1) == '*')
        ++flowers;
    // east
    if (column < garden.at(0).size() - 1 &&
        garden.at(row).at(column + 1) == '*')
        ++flowers;
    // west
    if (column > 0 && garden.at(row).at(column - 1) == '*') ++flowers;
    // south
    if (row < garden.size() - 1 && garden.at(row + 1).at(column) == '*')
        ++flowers;
    // south-east
    if (row < garden.size() - 1 && column < garden.at(0).size() - 1 &&
        garden.at(row + 1).at(column + 1) == '*')
        ++flowers;
    // south-west
    if (row < garden.size() - 1 && column > 0 &&
        garden.at(row + 1).at(column - 1) == '*')
        ++flowers;
    return flowers;
}

std::vector<std::string> annotate(const std::vector<std::string>& garden) {
    std::vector<std::string> annotation{};
    for (size_t row{}; row < garden.size(); ++row) {
        std::string annotated{};
        for (size_t column{}; column < garden.at(0).size(); ++column) {
            if (garden.at(row).at(column) == '*') {
                annotated += '*';
            } else {
                int score_number = score(garden, row, column);
                char score_char = (score_number == 0)
                                      ? ' '
                                      : static_cast<char>(score_number) + '0';
                annotated += score_char;
            }
        }
        annotation.push_back(std::move(annotated));
    }
    return annotation;
}
}  // namespace flower_field
