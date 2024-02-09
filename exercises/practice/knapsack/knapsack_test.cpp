#include "knapsack.h"
#include <vector>
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("no items", "[maximumValue][3993a824-c20e-493d-b3c9-ee8a7753ee59]")
{
    int max_weight = 100;
    const std::vector<knapsack::Item> items{};
    REQUIRE(knapsack::maximum_value(max_weight, items) == 0);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("one item, too heavy", "[maximumValue][1d39e98c-6249-4a8b-912f-87cb12e506b0]")
{
    int max_weight = 10;
    const std::vector<knapsack::Item> items{{100, 1}};
    REQUIRE(knapsack::maximum_value(max_weight, items) == 0);
}

TEST_CASE("five items (cannot be greedy by weight)", "[maximumValue][833ea310-6323-44f2-9d27-a278740ffbd8]")
{
    int max_weight = 10;
    const std::vector<knapsack::Item> items{
            {2, 5}, {2, 5}, {2, 5}, {2, 5}, {10, 21}};
    REQUIRE(knapsack::maximum_value(max_weight, items) == 21);
}

TEST_CASE("five items (cannot be greedy by value)", "[maximumValue][277cdc52-f835-4c7d-872b-bff17bab2456]")
{
    int max_weight = 10;
    const std::vector<knapsack::Item> items{
            {2, 20}, {2, 20}, {2, 20}, {2, 20}, {10, 50}};
    REQUIRE(knapsack::maximum_value(max_weight, items) == 80);
}

TEST_CASE("example knapsack", "[maximumValue][81d8e679-442b-4f7a-8a59-7278083916c9]")
{
    int max_weight = 10;
    const std::vector<knapsack::Item> items{
            {5, 10}, {4, 40}, {6, 30}, {4, 50}};
    REQUIRE(knapsack::maximum_value(max_weight, items) == 90);
}

TEST_CASE("8 items", "[maximumValue][f23a2449-d67c-4c26-bf3e-cde020f27ecc]")
{
    int max_weight = 104;
    const std::vector<knapsack::Item> items{
            {25, 350}, {35, 400}, {45, 450}, {5, 20}, {25, 70},
            {3, 8}, {2, 5}, {2, 5}};
    REQUIRE(knapsack::maximum_value(max_weight, items) == 900);
}

TEST_CASE("15 items", "[maximumValue][7c682ae9-c385-4241-a197-d2fa02c81a11]")
{
    int max_weight = 750;
    const std::vector<knapsack::Item> items{
            {70, 135}, {73, 139}, {77, 149}, {80, 150}, {82, 156},
            {87, 163}, {90, 173}, {94, 184}, {98, 192}, {106, 201},
            {110, 210}, {113, 214}, {115, 221}, {118, 229}, {120, 240}};
    REQUIRE(knapsack::maximum_value(max_weight, items) == 1458);
}

#endif  // EXERCISM_RUN_ALL_TESTS
