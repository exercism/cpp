#include "roman_numerals.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("one_yields_I")
{
    REQUIRE("I" == roman_numerals::convert(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("two_yields_II")
{
    REQUIRE("II" == roman_numerals::convert(2));
}

TEST_CASE("three_yields_III")
{
    REQUIRE("III" == roman_numerals::convert(3));
}

TEST_CASE("four_yields_IV")
{
    REQUIRE("IV" == roman_numerals::convert(4));
}

TEST_CASE("five_yields_V")
{
    REQUIRE("V" == roman_numerals::convert(5));
}

TEST_CASE("six_yields_VI")
{
    REQUIRE("VI" == roman_numerals::convert(6));
}

TEST_CASE("nine_yields_IX")
{
    REQUIRE("IX" == roman_numerals::convert(9));
}

TEST_CASE("twenty_seven_yields_XXVII")
{
    REQUIRE("XXVII" == roman_numerals::convert(27));
}

TEST_CASE("forty_eight_yields_XLVIII")
{
    REQUIRE("XLVIII" == roman_numerals::convert(48));
}

TEST_CASE("fifty_nine_yields_LIX")
{
    REQUIRE("LIX" == roman_numerals::convert(59));
}

TEST_CASE("ninety_three_yields_XCIII")
{
    REQUIRE("XCIII" == roman_numerals::convert(93));
}

TEST_CASE("one_hundred_forty_one_yields_CXLI")
{
    REQUIRE("CXLI" == roman_numerals::convert(141));
}

TEST_CASE("one_hundred_sixty_three_yields_CLXIII")
{
    REQUIRE("CLXIII" == roman_numerals::convert(163));
}

TEST_CASE("four_hundred_two_yields_CDII")
{
    REQUIRE("CDII" == roman_numerals::convert(402));
}

TEST_CASE("five_hundred_seventy_five_yields_DLXXV")
{
    REQUIRE("DLXXV" == roman_numerals::convert(575));
}

TEST_CASE("nine_hundred_eleven_yields_CMXI")
{
    REQUIRE("CMXI" == roman_numerals::convert(911));
}

TEST_CASE("one_thousand_twenty_four_yields_MXXIV")
{
    REQUIRE("MXXIV" == roman_numerals::convert(1024));
}

TEST_CASE("three_thousand_yields_MMM")
{
    REQUIRE("MMM" == roman_numerals::convert(3000));
}
#endif
