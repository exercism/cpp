#include "hexadecimal.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("hex_1_is_decimal_1")
{
    REQUIRE(0x1 == hexadecimal::convert("1"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("hex_c_is_decimal_12")
{
    REQUIRE(0xc == hexadecimal::convert("c"));
}

TEST_CASE("hex_10_is_decimal_16")
{
    REQUIRE(0x10 == hexadecimal::convert("10"));
}

TEST_CASE("hex_af_is_decimal_175")
{
    REQUIRE(0xaf == hexadecimal::convert("af"));
}

TEST_CASE("hex_100_is_decimal_256")
{
    REQUIRE(0x100 == hexadecimal::convert("100"));
}

TEST_CASE("hex_19ace_is_decimal_105166")
{
    REQUIRE(0x19ace == hexadecimal::convert("19ace"));
}

TEST_CASE("invalid_hex_is_decimal_0")
{
    REQUIRE(0 == hexadecimal::convert("carrot"));
}

TEST_CASE("black")
{
    REQUIRE(0x000000 == hexadecimal::convert("000000"));
}

TEST_CASE("white")
{
    REQUIRE(0xffffff == hexadecimal::convert("ffffff"));
}

TEST_CASE("yellow")
{
    REQUIRE(0xffff00 == hexadecimal::convert("ffff00"));
}
#endif
