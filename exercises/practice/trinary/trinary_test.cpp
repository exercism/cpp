#include "trinary.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("_1_yields_decimal_1")
{
    REQUIRE(1 == trinary::to_decimal("1"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("_2_yields_decimal_2")
{
    REQUIRE(2 == trinary::to_decimal("2"));
}

TEST_CASE("_10_yields_decimal_3")
{
    REQUIRE(3 == trinary::to_decimal("10"));
}

TEST_CASE("_11_yields_decimal_4")
{
    REQUIRE(4 == trinary::to_decimal("11"));
}

TEST_CASE("_100_yields_decimal_9")
{
    REQUIRE(9 == trinary::to_decimal("100"));
}

TEST_CASE("_112_yields_decimal_14")
{
    REQUIRE(14 == trinary::to_decimal("112"));
}

TEST_CASE("_222_yields_decimal_26")
{
    REQUIRE(26 == trinary::to_decimal("222"));
}

TEST_CASE("_1122000120_yields_decimal_32091")
{
    REQUIRE(32091 == trinary::to_decimal("1122000120"));
}

TEST_CASE("invalid_yields_decimal_0")
{
    REQUIRE(0 == trinary::to_decimal("carrot"));
}
#endif
