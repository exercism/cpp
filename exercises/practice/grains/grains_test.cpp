#include "grains.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("square_1")
{
    REQUIRE(1ULL == grains::square(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("square_2")
{
    REQUIRE(2ULL == grains::square(2));
}

TEST_CASE("square_3")
{
    REQUIRE(4ULL == grains::square(3));
}

TEST_CASE("square_4")
{
    REQUIRE(8ULL == grains::square(4));
}

TEST_CASE("square_16")
{
    REQUIRE(32768ULL == grains::square(16));
}

TEST_CASE("square_32")
{
    REQUIRE(2147483648ULL == grains::square(32));
}

TEST_CASE("square_64")
{
    REQUIRE(9223372036854775808ULL == grains::square(64));
}

TEST_CASE("total")
{
    REQUIRE(18446744073709551615ULL == grains::total());
}
#endif
