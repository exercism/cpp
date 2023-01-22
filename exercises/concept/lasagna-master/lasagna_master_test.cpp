#include "lasagna_master.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

TEST_CASE("Preparation time correct")
{
    const int actual = 40;
    int expected = lasagna_master::Lasagna::ovenTime();

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("Correct for six layers")
{
    const int timePerLayer = 2;
    const int layers = 36;
    const int actual = lasagna_master::Lasagna::preparationTime(layers);
    const int expected{timePerLayer*layers};

    REQUIRE(expected == actual);
}

TEST_CASE("Correct for 11 layers")
{
    const int timePerLayer = 2;
    const int layers = 11;
    const int actual = lasagna_master::Lasagna::preparationTime(layers);
    const int expected{timePerLayer*layers};

    REQUIRE(expected == actual);
}

TEST_CASE("Fresh in the oven")
{
    const int timeSpendInOven = 0;
    const int neededBakeTime = 40;
    const int actual = lasagna_master::Lasagna::remainingOvenTime(timeSpendInOven);
    const int expected{neededBakeTime-timeSpendInOven};

    REQUIRE(expected == actual);
}

TEST_CASE("Halfway done")
{
    const int timeSpendInOven = 20;
    const int neededBakeTime = 40;
    const int actual = lasagna_master::Lasagna::remainingOvenTime(timeSpendInOven);
    const int expected{neededBakeTime-timeSpendInOven};

    REQUIRE(expected == actual);
}

TEST_CASE("Fresh in the oven, 12 layers!")
{
    const int timeSpendInOven = 0;
    const int timePerLayer = 2;
    const int layers = 11;
    const int actual = lasagna_master::Lasagna::elapsedTime(layers, timeSpendInOven);
    const int expected{timePerLayer*layers + timeSpendInOven};

    REQUIRE(expected == actual);
}

TEST_CASE("One minute left, 5 layers!")
{
    const int timeSpendInOven = 39;
    const int timePerLayer = 2;
    const int layers = 5;
    const int actual = lasagna_master::Lasagna::elapsedTime(layers, timeSpendInOven);
    const int expected{timePerLayer*layers + timeSpendInOven};

    REQUIRE(expected == actual);
}

#endif
