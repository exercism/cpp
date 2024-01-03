#include "lasagna.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("Preparation time correct", "[task_1]") {
    int actual = 40;
    int expected = ovenTime();

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Fresh in the oven", "[task_2]") {
    int timeSpendInOven = 0;
    int neededBakeTime = 40;
    int actual = remainingOvenTime(timeSpendInOven);
    int expected{neededBakeTime - timeSpendInOven};

    REQUIRE(expected == actual);
}

TEST_CASE("Halfway done", "[task_2]") {
    int timeSpendInOven = 20;
    int neededBakeTime = 40;
    int actual = remainingOvenTime(timeSpendInOven);
    int expected{neededBakeTime - timeSpendInOven};

    REQUIRE(expected == actual);
}

TEST_CASE("Correct for six layers", "[task_3]") {
    int timePerLayer = 2;
    int layers = 6;
    int actual = preparationTime(layers);
    int expected{timePerLayer * layers};

    REQUIRE(expected == actual);
}

TEST_CASE("Correct for 11 layers", "[task_3]") {
    int timePerLayer = 2;
    int layers = 11;
    int actual = preparationTime(layers);
    int expected{timePerLayer * layers};

    REQUIRE(expected == actual);
}

TEST_CASE("Fresh in the oven, 12 layers!", "[task_4]") {
    int timeSpendInOven = 0;
    int timePerLayer = 2;
    int layers = 12;
    int actual = elapsedTime(layers, timeSpendInOven);
    int expected{timePerLayer * layers + timeSpendInOven};

    REQUIRE(expected == actual);
}

TEST_CASE("One minute left, 5 layers!", "[task_4]") {
    int timeSpendInOven = 39;
    int timePerLayer = 2;
    int layers = 5;
    int actual = elapsedTime(layers, timeSpendInOven);
    int expected{timePerLayer * layers + timeSpendInOven};

    REQUIRE(expected == actual);
}

#endif
