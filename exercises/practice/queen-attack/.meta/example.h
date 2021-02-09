#if !defined(QUEEN_ATTACK_H)
#define QUEEN_ATTACK_H

#include <string>
#include <utility>

namespace queen_attack
{

class chess_board
{
public:
    chess_board(const std::pair<int, int>& white, const std::pair<int, int>& black);

    chess_board()
    {}

    std::pair<int, int> white() const
    {
        return white_;
    }
    std::pair<int, int> black() const
    {
        return black_;
    }

    operator std::string() const;

    bool can_attack() const;

private:
    const std::pair<int, int> white_ = std::make_pair(0, 3);
    const std::pair<int, int> black_ = std::make_pair(7, 3);
};

}

#endif
