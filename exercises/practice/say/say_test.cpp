#include "say.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("zero")
{
    REQUIRE("zero" == say::in_english(0ULL));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("one")
{
    REQUIRE("one" == say::in_english(1ULL));
}

TEST_CASE("fourteen")
{
    REQUIRE("fourteen" == say::in_english(14ULL));
}

TEST_CASE("twenty")
{
    REQUIRE("twenty" == say::in_english(20ULL));
}

TEST_CASE("twenty_two")
{
    REQUIRE("twenty-two" == say::in_english(22ULL));
}

TEST_CASE("sixty_nine")
{
    REQUIRE("sixty-nine" == say::in_english(69ULL));
}

TEST_CASE("one_hundred")
{
    REQUIRE("one hundred" == say::in_english(100ULL));
}

TEST_CASE("one_hundred_twenty_three")
{
    REQUIRE("one hundred twenty-three" == say::in_english(123ULL));
}

TEST_CASE("one_thousand")
{
    REQUIRE("one thousand" == say::in_english(1000ULL));
}

TEST_CASE("one_thousand_two_hundred_thirty_four")
{
    REQUIRE("one thousand two hundred thirty-four" == say::in_english(1234ULL));
}

TEST_CASE("one_million")
{
    REQUIRE("one million" == say::in_english(1000ULL*1000ULL));
}

TEST_CASE("one_million_two")
{
    REQUIRE("one million two" == say::in_english(1000ULL*1000ULL + 2ULL));
}

TEST_CASE("one_million_two_thousand_three_hundred_forty_five")
{
    REQUIRE("one million two thousand three hundred forty-five" == say::in_english(1002345ULL));
}

TEST_CASE("one_billion")
{
    REQUIRE("one billion" == say::in_english(1000ULL*1000ULL*1000ULL));
}

TEST_CASE("a_really_big_number")
{
    REQUIRE(
        "nine hundred eighty-seven billion six hundred fifty-four million "
        "three hundred twenty-one thousand one hundred twenty-three" ==
        say::in_english(987654321123ULL));
}

TEST_CASE("raises_an_error_below_zero")
{
    REQUIRE_THROWS_AS(say::in_english(-1), std::domain_error);
}

TEST_CASE("raises_an_error_for_one_trillion")
{
    REQUIRE_THROWS_AS(say::in_english(1000ULL * 1000ULL * 1000ULL * 1000ULL),
                      std::domain_error);
}
#endif
