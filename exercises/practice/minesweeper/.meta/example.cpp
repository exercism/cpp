#include "minesweeper.h"

namespace minesweeper {
int score(const std::vector<std::string>& minefield, size_t row,
          size_t column) {
    int mines{};
    // north
    if (row > 0 && minefield.at(row - 1).at(column) == '*') ++mines;
    // north-east
    if (row > 0 && column < minefield.at(0).size() - 1 &&
        minefield.at(row - 1).at(column + 1) == '*')
        ++mines;
    // north-west
    if (row > 0 && column > 0 && minefield.at(row - 1).at(column - 1) == '*')
        ++mines;
    // east
    if (column < minefield.at(0).size() - 1 &&
        minefield.at(row).at(column + 1) == '*')
        ++mines;
    // west
    if (column > 0 && minefield.at(row).at(column - 1) == '*') ++mines;
    // south
    if (row < minefield.size() - 1 && minefield.at(row + 1).at(column) == '*')
        ++mines;
    // south-east
    if (row < minefield.size() - 1 && column < minefield.at(0).size() - 1 &&
        minefield.at(row + 1).at(column + 1) == '*')
        ++mines;
    // south-west
    if (row < minefield.size() - 1 && column > 0 &&
        minefield.at(row + 1).at(column - 1) == '*')
        ++mines;
    return mines;
}

std::vector<std::string> annotate(const std::vector<std::string>& minefield) {
    std::vector<std::string> annotation{};
    for (size_t row{}; row < minefield.size(); ++row) {
        std::string annotaded_line{};
        for (size_t column{}; column < minefield.at(0).size(); ++column) {
            if (minefield.at(row).at(column) == '*') {
                annotaded_line += '*';
            } else {
                int score_number = score(minefield, row, column);
                char score_char =
                    (score_number == 0) ? ' ' : char(score_number) + '0';
                annotaded_line += score_char;
            }
        }
        annotation.emplace_back(annotaded_line);
    }
    return annotation;
}
}  // namespace minesweeper
