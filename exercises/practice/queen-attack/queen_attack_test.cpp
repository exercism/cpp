#include "queen_attack.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


TEST_CASE("newly_placed_queen_with_a_valid_position")
{
    const auto white = std::make_pair(2, 2);
    const auto black = std::make_pair(0, 3);

    const queen_attack::chess_board board{white, black};

    REQUIRE(white == board.white());
    REQUIRE(black == board.black());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("newly_placed_queen_must_have_positive_row")
{
    const auto white = std::make_pair(-2, 2);
    const auto black = std::make_pair(0, 3);

    REQUIRE_THROWS_AS((queen_attack::chess_board{white, black}), std::domain_error);
}

TEST_CASE("newly_placed_queen_must_have_row_on_board")
{
    const auto white = std::make_pair(8, 4);
    const auto black = std::make_pair(0, 3);

    REQUIRE_THROWS_AS((queen_attack::chess_board{white, black}), std::domain_error);
}

TEST_CASE("newly_placed_queen_must_have_positive_column")
{
    const auto white = std::make_pair(2, -2);
    const auto black = std::make_pair(0, 3);

    REQUIRE_THROWS_AS((queen_attack::chess_board{white, black}), std::domain_error);
}

TEST_CASE("newly_placed_queen_must_have_column_on_board")
{
    const auto white = std::make_pair(4, 8);
    const auto black = std::make_pair(0, 3);

    REQUIRE_THROWS_AS((queen_attack::chess_board{white, black}), std::domain_error);
}

TEST_CASE("queen_positions_must_be_distinct")
{
    const auto pos = std::make_pair(3, 7);

    REQUIRE_THROWS_AS((queen_attack::chess_board{pos, pos}), std::domain_error);
}

TEST_CASE("queens_cannot_attack")
{
    const queen_attack::chess_board board{std::make_pair(2, 4), std::make_pair(6, 6)};

    REQUIRE_FALSE(board.can_attack());
}

TEST_CASE("queens_can_attack_on_same_row")
{
    const queen_attack::chess_board board{std::make_pair(2, 4), std::make_pair(2, 6)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_on_same_column")
{
    const queen_attack::chess_board board{std::make_pair(4, 5), std::make_pair(2, 5)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_on_first_diagonal")
{
    const queen_attack::chess_board board{std::make_pair(2, 2), std::make_pair(0, 4)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_on_second_diagonal")
{
    const queen_attack::chess_board board{std::make_pair(2, 2), std::make_pair(3, 1)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_on_third_diagonal")
{
    const queen_attack::chess_board board{std::make_pair(2, 2), std::make_pair(1, 1)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_can_attack_on_fourth_diagonal")
{
    const queen_attack::chess_board board{std::make_pair(1, 7), std::make_pair(0, 6)};

    REQUIRE(board.can_attack());
}

TEST_CASE("queens_cannot_attack_if_falling_diagonals_are_only_the_same_when_reflected_across_the_longest_falling_diagonal")
{
    const queen_attack::chess_board board{std::make_pair(4, 1), std::make_pair(2, 5)};

    REQUIRE_FALSE(board.can_attack());
}
#endif
