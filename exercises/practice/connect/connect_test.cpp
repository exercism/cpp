#include "connect.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

#include <string>
#include <vector>

TEST_CASE("an empty board has no winner",
          "[6eff0df4-3e92-478d-9b54-d3e8b354db56]") {
    std::vector<std::string> board = {". . . . .", " . . . . .", "  . . . . .",
                                      "   . . . . .", "    . . . . ."};
    REQUIRE(connect::winner(board) == "");
}

TEST_CASE("X can win on a 1x1 board",
          "[298b94c0-b46d-45d8-b34b-0fa2ea71f0a4]") {
    std::vector<std::string> board = {"X"};
    REQUIRE(connect::winner(board) == "X");
}

TEST_CASE("O can win on a 1x1 board",
          "[763bbae0-cb8f-4f28-bc21-5be16a5722dc]") {
    std::vector<std::string> board = {"O"};
    REQUIRE(connect::winner(board) == "O");
}

TEST_CASE("only edges does not make a winner",
          "[819fde60-9ae2-485e-a024-cbb8ea68751b]") {
    std::vector<std::string> board = {"O O O X", " X . . X", "  X . . X",
                                      "   X O O O"};
    REQUIRE(connect::winner(board) == "");
}

TEST_CASE("illegal diagonal does not make a winner",
          "[2c56a0d5-9528-41e5-b92b-499dfe08506c]") {
    std::vector<std::string> board = {"X O . .", " O X X X", "  O X O .",
                                      "   . O X .", "    X X O O"};
    REQUIRE(connect::winner(board) == "");
}

TEST_CASE("nobody wins crossing adjacent angles",
          "[41cce3ef-43ca-4963-970a-c05d39aa1cc1]") {
    std::vector<std::string> board = {"X . . .", " . X O .", "  O . X O",
                                      "   . O . X", "    . . O ."};
    REQUIRE(connect::winner(board) == "");
}

TEST_CASE("X wins crossing from left to right",
          "[cd61c143-92f6-4a8d-84d9-cb2b359e226b]") {
    std::vector<std::string> board = {". O . .", " O X X X", "  O X O .",
                                      "   X X O X", "    . O X ."};
    REQUIRE(connect::winner(board) == "X");
}

TEST_CASE("O wins crossing from top to bottom",
          "[73d1eda6-16ab-4460-9904-b5f5dd401d0b]") {
    std::vector<std::string> board = {". O . .", " O X X X", "  O O O .",
                                      "   X X O X", "    . O X ."};
    REQUIRE(connect::winner(board) == "O");
}

TEST_CASE("X wins using a convoluted path",
          "[c3a2a550-944a-4637-8b3f-1e1bf1340a3d]") {
    std::vector<std::string> board = {". X X . .", " X . X . X", "  . X . X .",
                                      "   . X X . .", "    O O O O O"};
    REQUIRE(connect::winner(board) == "X");
}

TEST_CASE("X wins using a spiral path",
          "[17e76fa8-f731-4db7-92ad-ed2a285d31f3]") {
    std::vector<std::string> board = {
        "O X X X X X X X X",        " O X O O O O O O O",
        "  O X O X X X X X O",      "   O X O X O O O X O",
        "    O X O X X X O X O",    "     O X O O O X O X O",
        "      O X X X X X O X O",  "       O O O O O O O X O",
        "        X X X X X X X X O"};
    REQUIRE(connect::winner(board) == "X");
}
