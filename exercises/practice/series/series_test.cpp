#include "series.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <stdexcept>

using namespace std;

TEST_CASE("short_digits")
{
    const vector<int> expected{0, 1, 2, 3, 4, 5};

    const vector<int> actual{series::digits("012345")};

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("long_digits")
{
    const vector<int> expected{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    const vector<int> actual{series::digits("0123456789")};

    REQUIRE(expected == actual);
}

TEST_CASE("keeps_the_digit_order_if_reversed")
{
    const vector<int> expected{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    const vector<int> actual{series::digits("9876543210")};

    REQUIRE(expected == actual);
}

TEST_CASE("keeps_arbitrary_digit_order")
{
    const vector<int> expected{9, 3, 6, 9, 2, 3, 4, 6, 8};

    const vector<int> actual{series::digits("936923468")};

    REQUIRE(expected == actual);
}

TEST_CASE("can_slice_by_1")
{
    const vector<vector<int>> expected{{0}, {1}, {2}, {3}, {4}};

    const vector<vector<int>> actual{series::slice("01234", 1)};

    REQUIRE(expected == actual);
}

TEST_CASE("can_slice_by_2")
{
    const vector<vector<int>> expected{{9, 8}, {8, 2}, {2, 7}, {7, 3}, {3, 4}, {4, 6}, {6, 3}};

    const vector<vector<int>> actual{series::slice("98273463", 2)};

    REQUIRE(expected == actual);
}

TEST_CASE("can_slice_by_3")
{
    const vector<vector<int>> expected{{0, 1, 2}, {1, 2, 3}, {2, 3, 4}};

    const vector<vector<int>> actual{series::slice("01234", 3)};

    REQUIRE(expected == actual);
}

TEST_CASE("can_slice_by_3_with_duplicate_digits")
{
    const vector<vector<int>> expected{{3, 1, 0}, {1, 0, 0}, {0, 0, 1}};

    const vector<vector<int>> actual{series::slice("31001", 3)};

    REQUIRE(expected == actual);
}

TEST_CASE("can_slice_by_4")
{
    const vector<vector<int>> expected{{3, 1, 0}, {1, 0, 0}, {0, 0, 1}};

    const vector<vector<int>> actual{series::slice("31001", 3)};

    REQUIRE(expected == actual);
}

TEST_CASE("can_slice_by_5")
{
    const vector<vector<int>> expected{{8, 1, 2, 2, 8}};

    const vector<vector<int>> actual{series::slice("81228", 5)};

    REQUIRE(expected == actual);
}

TEST_CASE("domain_error_if_not_enough_digits_to_slice")
{
    REQUIRE_THROWS_AS(series::slice("01032987583", 12), domain_error);
}
#endif
