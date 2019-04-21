#include "queen_attack.h"
#include "test/catch.hpp"

TEST_CASE("queens_in_default_positions")
{
    const queen_attack::chess_board board;

    REQUIRE(std::make_pair(0, 3).first == board.white().first);
    REQUIRE(std::make_pair(0, 3).second == board.white().second);
    REQUIRE(std::make_pair(7, 3).first == board.black().first);
    REQUIRE(std::make_pair(7, 3).second == board.black().second);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("initialized_with_specific_positions")
{
    const auto white = std::make_pair(3, 7);
    const auto black = std::make_pair(6, 1);
    const queen_attack::chess_board board{white, black};

    REQUIRE(white.first == board.white().first);
    REQUIRE(white.second == board.white().second);
    REQUIRE(black.first == board.black().first);
    REQUIRE(black.second == board.black().second);
}

TEST_CASE("queen_positions_must_be_distinct")
{
    const auto pos = std::make_pair(3, 7);
    REQUIRE_THROWS_AS((queen_attack::chess_board{pos, pos}), std::domain_error);
}

TEST_CASE("string_representation")
{
    const queen_attack::chess_board board{std::make_pair(2, 4), std::make_pair(6, 6)};

    const std::string expected{
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ W _ _ _\n"
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ _ _ _ _\n"
        "_ _ _ _ _ _ B _\n"
        "_ _ _ _ _ _ _ _\n"};
    REQUIRE(expected == static_cast<std::string>(board));
}

TEST_CASE("queens_cannot_attack")
{
    const queen_attack::chess_board board{std::make_pair(2, 3), std::make_pair(4, 7)};

    REQUIRE(!board.can_attack());
}

TEST_CASE("queens_can_attack_when_they_are_on_the_same_row")
{
    const queen_attack::chess_board board{std::make_pair(2, 4), std::make_pair(2, 7)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_when_they_are_on_the_same_column")
{
    const queen_attack::chess_board board{std::make_pair(5, 4), std::make_pair(2, 4)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_diagonally")
{
    const queen_attack::chess_board board{std::make_pair(1, 1), std::make_pair(6, 6)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_another_diagonally")
{
    const queen_attack::chess_board board{std::make_pair(0, 6), std::make_pair(1, 7)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_yet_another_diagonally")
{
    const queen_attack::chess_board board{std::make_pair(4, 1), std::make_pair(6, 3)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_on_the_nw_so_diagonal")
{
    const queen_attack::chess_board board{std::make_pair(1, 6), std::make_pair(6, 1)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_cannot_attack_if_not_on_same_row_column_or_diagonal")
{
    const queen_attack::chess_board board{std::make_pair(1, 1), std::make_pair(3, 7)};

    REQUIRE(!board.can_attack());
}
#endif
