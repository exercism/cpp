#include "queen_attack.h"

#include <sstream>
#include <stdexcept>

namespace queen_attack
{

chess_board::chess_board(const std::pair<int, int>& white, const std::pair<int, int>& black)
    : white_{white},
    black_{black}
{
    if (white == black) {
        throw std::domain_error("Both queens cannot occupy the same position.");
    }
}

chess_board::operator std::string() const
{
    std::ostringstream board;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            const auto pos = std::make_pair(row, col);
            if (pos == white_) {
                board << 'W';
            } else if (pos == black_) {
                board << 'B';
            } else {
                board << '_';
            }
            if (col != 7) {
                board << ' ';
            }
        }
        board << '\n';
    }
    return board.str();
}

bool chess_board::can_attack() const
{
    return (white_.first == black_.first)
        || (white_.second == black_.second)
        || ((white_.first - black_.first) == (white_.second - black_.second))
        || ((white_.first - black_.first) == (black_.second - white_.second));
}

}
