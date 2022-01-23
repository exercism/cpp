#include "binary.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("b1_is_decimal_1")
{
    REQUIRE(1 == binary::convert("1"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("b10_is_decimal_2")
{
    REQUIRE(2 == binary::convert("10"));
}

TEST_CASE("b11_is_decimal_3")
{
    REQUIRE(3 == binary::convert("11"));
}

TEST_CASE("b100_is_decimal_4")
{
    REQUIRE(4 == binary::convert("100"));
}

TEST_CASE("b1001_is_decimal_9")
{
    REQUIRE(9 == binary::convert("1001"));
}

TEST_CASE("b11010_is_decimal_26")
{
    REQUIRE(26 == binary::convert("11010"));
}

TEST_CASE("b10001101000_is_decimal_1128")
{
    REQUIRE(1128 == binary::convert("10001101000"));
}

TEST_CASE("carrot_is_decimal_0")
{
    REQUIRE(0 == binary::convert("carrot"));
}

TEST_CASE("x1100101b_is_decimal_0")
{
    REQUIRE(0 == binary::convert("1100101b"));
}
#endif
