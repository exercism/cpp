// Include the header file with the definitions of the functions you create.
#include "high_scores.h"

// Include the test framework.
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// Declares a single test.
TEST_CASE("List of scores", "[1035eb93-2208-4c22-bab8-fef06769a73c][scores]") {
    std::vector<int> scores{30, 50, 20, 70};
    arcade::HighScores hs{scores};
    REQUIRE(hs.list_scores() == scores);
}

#ifdef EXERCISM_RUN_ALL_TESTS

TEST_CASE("Latest score", "[6aa5dbf5-78fa-4375-b22c-ffaa989732d2][latest]") {
    std::vector<int> scores{100, 0, 90, 30};
    int expected{30};
    arcade::HighScores hs{scores};
    REQUIRE(hs.latest_score() == expected);
}

TEST_CASE("Personal best",
          "[b661a2e1-aebf-4f50-9139-0fb817dd12c6][personalBest]") {
    std::vector<int> scores{40, 100, 70};
    int expected{100};
    arcade::HighScores hs{scores};
    REQUIRE(hs.personal_best() == expected);
}

TEST_CASE("Personal top three from a list of scores",
          "[3d996a97-c81c-4642-9afc-80b80dc14015][personalTopThree]") {
    std::vector<int> scores{10, 30, 90, 30, 100, 20, 10, 0, 30, 40, 40, 70, 70};
    std::vector<int> expected{100, 90, 70};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE("Personal top highest to lowest",
          "[1084ecb5-3eb4-46fe-a816-e40331a4e83a][personalTopThree]") {
    std::vector<int> scores{20, 10, 30};
    std::vector<int> expected{30, 20, 10};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE("Personal top when there is a tie",
          "[e6465b6b-5a11-4936-bfe3-35241c4f4f16][personalTopThree]") {
    std::vector<int> scores{40, 20, 40, 30};
    std::vector<int> expected{40, 40, 30};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE("Personal top when there are less than 3",
          "[f73b02af-c8fd-41c9-91b9-c86eaa86bce2][personalTopThree]") {
    std::vector<int> scores{30, 70};
    std::vector<int> expected{70, 30};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE("Personal top when there is only one",
          "[16608eae-f60f-4a88-800e-aabce5df2865][personalTopThree]") {
    std::vector<int> scores{40};
    std::vector<int> expected{40};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE(
    "Latest score after personal top scores",
    "[2df075f9-fec9-4756-8f40-98c52a11504f][immutable, latestAfterTopThree]") {
    // Test if latest_score is still valid after calling top_three
    std::vector<int> scores{70, 50, 20, 30};
    int expected{30};
    arcade::HighScores hs{scores};
    hs.top_three();
    REQUIRE(hs.latest_score() == expected);
}

TEST_CASE(
    "Scores after personal top scores",
    "[809c4058-7eb1-4206-b01e-79238b9b71bc][immutable, scoresAfterTopThree]") {
    // Test if list_scores is unchanged after calling top_three
    std::vector<int> scores{30, 50, 20, 70};
    arcade::HighScores hs{scores};
    hs.top_three();
    REQUIRE(hs.list_scores() == scores);
}

TEST_CASE(
    "Latest score after personal best",
    "[ddb0efc0-9a86-4f82-bc30-21ae0bdc6418][immutable, latestAfterBest]") {
    // Test if latest_score is still valid after calling personal_best
    std::vector<int> scores{20, 70, 15, 25, 30};
    int expected{30};
    arcade::HighScores hs{scores};
    hs.personal_best();
    REQUIRE(hs.latest_score() == expected);
}

TEST_CASE(
    "Scores after personal best",
    "[6a0fd2d1-4cc4-46b9-a5bb-2fb667ca2364][immutable, scoresAfterBest]") {
    // Test if list_scores is unchanged after calling personal_best
    std::vector<int> scores{20, 70, 15, 25, 30};
    arcade::HighScores hs{scores};
    hs.personal_best();
    REQUIRE(hs.list_scores() == scores);
}

#endif
