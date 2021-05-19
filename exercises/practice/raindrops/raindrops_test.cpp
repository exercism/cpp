#include "raindrops.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("one_yields_itself")
{
    REQUIRE("1" == raindrops::convert(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("three_yields_pling")
{
    REQUIRE("Pling" == raindrops::convert(3));
}

TEST_CASE("five_yields_plang")
{
    REQUIRE("Plang" == raindrops::convert(5));
}

TEST_CASE("seven_yields_plong")
{
    REQUIRE("Plong" == raindrops::convert(7));
}

TEST_CASE("six_yields_pling")
{
    REQUIRE("Pling" == raindrops::convert(6));
}

TEST_CASE("nine_yields_pling")
{
    REQUIRE("Pling" == raindrops::convert(9));
}

TEST_CASE("ten_yields_plang")
{
    REQUIRE("Plang" == raindrops::convert(10));
}

TEST_CASE("fourteen_yields_plong")
{
    REQUIRE("Plong" == raindrops::convert(14));
}

TEST_CASE("fifteen_yields_plingplang")
{
    REQUIRE("PlingPlang" == raindrops::convert(15));
}

TEST_CASE("twenty_one_yields_plingplong")
{
    REQUIRE("PlingPlong" == raindrops::convert(21));
}

TEST_CASE("twenty_five_yields_plang")
{
    REQUIRE("Plang" == raindrops::convert(25));
}

TEST_CASE("thirty_five_yields_plangplong")
{
    REQUIRE("PlangPlong" == raindrops::convert(35));
}

TEST_CASE("forty_nine_yields_plong")
{
    REQUIRE("Plong" == raindrops::convert(49));
}

TEST_CASE("fifty_two_yields_itself")
{
    REQUIRE("52" == raindrops::convert(52));
}

TEST_CASE("one_hundred_five_yields_plingplangplong")
{
    REQUIRE("PlingPlangPlong" == raindrops::convert(105));
}

TEST_CASE("big_prime_yields_itself")
{
    REQUIRE("12121" == raindrops::convert(12121));
}
#endif
