#include "roman_numerals.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("1_is_i")
{
    REQUIRE("I" == roman_numerals::convert(1));
}
#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("2_is_ii")
{
    REQUIRE("II" == roman_numerals::convert(2));
}
TEST_CASE("3_is_iii")
{
    REQUIRE("III" == roman_numerals::convert(3));
}
TEST_CASE("4_is_iv")
{
    REQUIRE("IV" == roman_numerals::convert(4));
}
TEST_CASE("5_is_v")
{
    REQUIRE("V" == roman_numerals::convert(5));
}
TEST_CASE("6_is_vi")
{
    REQUIRE("VI" == roman_numerals::convert(6));
}
TEST_CASE("9_is_ix")
{
    REQUIRE("IX" == roman_numerals::convert(9));
}
TEST_CASE("27_is_xxvii")
{
    REQUIRE("XXVII" == roman_numerals::convert(27));
}
TEST_CASE("48_is_xlviii")
{
    REQUIRE("XLVIII" == roman_numerals::convert(48));
}
TEST_CASE("49_is_xlix")
{
    REQUIRE("XLIX" == roman_numerals::convert(49));
}
TEST_CASE("59_is_lix")
{
    REQUIRE("LIX" == roman_numerals::convert(59));
}
TEST_CASE("93_is_xciii")
{
    REQUIRE("XCIII" == roman_numerals::convert(93));
}
TEST_CASE("141_is_cxli")
{
    REQUIRE("CXLI" == roman_numerals::convert(141));
}
TEST_CASE("163_is_clxiii")
{
    REQUIRE("CLXIII" == roman_numerals::convert(163));
}
TEST_CASE("402_is_cdii")
{
    REQUIRE("CDII" == roman_numerals::convert(402));
}
TEST_CASE("575_is_dlxxv")
{
    REQUIRE("DLXXV" == roman_numerals::convert(575));
}
TEST_CASE("911_is_cmxi")
{
    REQUIRE("CMXI" == roman_numerals::convert(911));
}
TEST_CASE("1024_is_mxxiv")
{
    REQUIRE("MXXIV" == roman_numerals::convert(1024));
}
TEST_CASE("3000_is_mmm")
{
    REQUIRE("MMM" == roman_numerals::convert(3000));
}
TEST_CASE("16_is_xvi")
{
    REQUIRE("XVI" == roman_numerals::convert(16));
}
TEST_CASE("66_is_lxvi")
{
    REQUIRE("LXVI" == roman_numerals::convert(66));
}
TEST_CASE("166_is_clxvi")
{
    REQUIRE("CLXVI" == roman_numerals::convert(166));
}
TEST_CASE("666_is_dclxvi")
{
    REQUIRE("DCLXVI" == roman_numerals::convert(666));
}
TEST_CASE("1666_is_mdclxvi")
{
    REQUIRE("MDCLXVI" == roman_numerals::convert(1666));
}
TEST_CASE("3001_is_mmmi")
{
    REQUIRE("MMMI" == roman_numerals::convert(3001));
}
TEST_CASE("3999_is_mmmcmxcix")
{
    REQUIRE("MMMCMXCIX" == roman_numerals::convert(3999));
}
#endif
