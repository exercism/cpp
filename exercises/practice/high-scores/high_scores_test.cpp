// Include the header file with the definitions of the functions you create.
#include "high_scores.h"

// Include the test framework.
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// Declares a single test.
TEST_CASE("List of scores", "[scores]") {
    std::vector<int> scores{30, 50, 20, 70};
    arcade::HighScores hs{scores};
    REQUIRE(hs.list_scores() == scores);
}

#ifdef EXERCISM_RUN_ALL_TESTS

TEST_CASE("Latest score", "[latest]") {
    std::vector<int> scores{100, 0, 90, 30};
    int expected{30};
    arcade::HighScores hs{scores};
    REQUIRE(hs.latest_score() == expected);
}

TEST_CASE("Personal best", "[personalBest]") {
    std::vector<int> scores{40, 100, 70};
    int expected{100};
    arcade::HighScores hs{scores};
    REQUIRE(hs.personal_best() == expected);
}

TEST_CASE("Personal top three from a list of scores", "[personalTopThree]") {
    std::vector<int> scores{10, 30, 90, 30, 100, 20, 10, 0, 30, 40, 40, 70, 70};
    std::vector<int> expected{100, 90, 70};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE("Personal top highest to lowest", "[personalTopThree]") {
    std::vector<int> scores{20, 10, 30};
    std::vector<int> expected{30, 20, 10};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE("Personal top when there is a tie", "[personalTopThree]") {
    std::vector<int> scores{40, 20, 40, 30};
    std::vector<int> expected{40, 40, 30};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE("Personal top when there are less than 3", "[personalTopThree]") {
    std::vector<int> scores{30, 70};
    std::vector<int> expected{70, 30};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE("Personal top when there is only one", "[personalTopThree]") {
    std::vector<int> scores{40};
    std::vector<int> expected{40};
    arcade::HighScores hs{scores};
    REQUIRE(hs.top_three() == expected);
}

TEST_CASE("Latest score after personal top scores",
          "[immutable, latestAfterTopThree]") {
    // Test if latest_score is still valid after calling top_three
    std::vector<int> scores{70, 50, 20, 30};
    int expected{30};
    arcade::HighScores hs{scores};
    hs.top_three();
    REQUIRE(hs.latest_score() == expected);
}

TEST_CASE("Scores after personal top scores",
          "[immutable, scoresAfterTopThree]") {
    // Test if list_scores is unchanged after calling top_three
    std::vector<int> scores{30, 50, 20, 70};
    arcade::HighScores hs{scores};
    hs.top_three();
    REQUIRE(hs.list_scores() == scores);
}

TEST_CASE("Latest score after personal best", "[immutable, latestAfterBest]") {
    // Test if latest_score is still valid after calling personal_best
    std::vector<int> scores{20, 70, 15, 25, 30};
    int expected{30};
    arcade::HighScores hs{scores};
    hs.personal_best();
    REQUIRE(hs.latest_score() == expected);
}

TEST_CASE("Scores after personal best", "[immutable, scoresAfterBest]") {
    // Test if list_scores is unchanged after calling personal_best
    std::vector<int> scores{20, 70, 15, 25, 30};
    arcade::HighScores hs{scores};
    hs.personal_best();
    REQUIRE(hs.list_scores() == scores);
}

#endif