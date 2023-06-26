#include "making_the_grade.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("Check correct mark conversion") {
    std::vector<double> input{90.33, 40.5, 55.44, 70.05, 30.55, 25.45, 80.45, 95.3, 38.7, 40.3};
    std::vector<int> expected{90, 40, 55, 70, 31, 25, 80, 95, 39, 40};
    std::vector<int>  actual = round_down_scores(input);
    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("Count failed students, none on threshold") {
    std::vector<int> input{90, 42, 55, 70, 31, 25, 80, 95, 39, 48};
    int expected{3};
    int  actual = count_failed_students(input);
    REQUIRE(expected == actual);
}

TEST_CASE("Count failed students, 2 on threshold") {
    std::vector<int> input{90, 40, 55, 70, 31, 25, 80, 95, 39, 40};
    int expected{5};
    int  actual = count_failed_students(input);
    REQUIRE(expected == actual);
}

TEST_CASE("Check above threshold") {
    std::vector<int> grades{90, 40, 55, 70, 31, 25, 80, 95, 39, 40};
    int threshold {80};
    int expected{5};
    int  actual = count_failed_students(input);
    REQUIRE(expected == actual);
}

TEST_CASE("Halfway done") {
    int timeSpendInOven = 20;
    int neededBakeTime = 40;
    int actual = remainingOvenTime(timeSpendInOven);
    int expected{neededBakeTime - timeSpendInOven};

    REQUIRE(expected == actual);
}

TEST_CASE("Fresh in the oven, 12 layers!") {
    int timeSpendInOven = 0;
    int timePerLayer = 2;
    int layers = 11;
    int actual = elapsedTime(layers, timeSpendInOven);
    int expected{timePerLayer * layers + timeSpendInOven};

    REQUIRE(expected == actual);
}

TEST_CASE("One minute left, 5 layers!") {
    int timeSpendInOven = 39;
    int timePerLayer = 2;
    int layers = 5;
    int actual = elapsedTime(layers, timeSpendInOven);
    int expected{timePerLayer * layers + timeSpendInOven};

    REQUIRE(expected == actual);
}

#endif
