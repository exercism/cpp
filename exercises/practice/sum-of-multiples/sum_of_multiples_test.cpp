#include "sum_of_multiples.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("sum_to_1_yields_0")
{
    REQUIRE(0 == sum_of_multiples::to({3, 5}, 0));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("sum_to_4_yields_3")
{
    REQUIRE(3 == sum_of_multiples::to({3, 5}, 4));
}

TEST_CASE("sum_to_10_yields_23")
{
    REQUIRE(23 == sum_of_multiples::to({3, 5}, 10));
}

TEST_CASE("sum_to_100")
{
    REQUIRE(2318 == sum_of_multiples::to({3, 5}, 100));
}

TEST_CASE("sum_to_1000")
{
    REQUIRE(233168 == sum_of_multiples::to({3, 5}, 1000));
}

TEST_CASE("sum_of_7_13_17_to_20_yields_51")
{
    REQUIRE(51 == sum_of_multiples::to({7, 13, 17}, 20));
}

TEST_CASE("sum_of_4_6_to_15")
{
    REQUIRE(30 == sum_of_multiples::to({4, 6}, 15));
}

TEST_CASE("sum_of_5_6_8_to_150")
{
    REQUIRE(4419 == sum_of_multiples::to({5, 6, 8}, 150));
}

TEST_CASE("sum_of_5_25_to_51")
{
    REQUIRE(275 == sum_of_multiples::to({5, 25}, 51));
}

TEST_CASE("sum_of_43_47_to_10000")
{
    REQUIRE(2203160 == sum_of_multiples::to({43, 47}, 10000));
}

TEST_CASE("sum_of_1_to_100")
{
    REQUIRE(4950 == sum_of_multiples::to({1}, 100));
}

TEST_CASE("sum_of_empty_list")
{
    REQUIRE(0 == sum_of_multiples::to({}, 10000));
}
#endif
