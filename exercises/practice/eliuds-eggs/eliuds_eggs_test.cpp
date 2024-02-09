#include "eliuds_eggs.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("0 eggs")
{
    REQUIRE(chicken_coop::positions_to_quantity(0) == 0);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("1 egg")
{
    REQUIRE(chicken_coop::positions_to_quantity(16) == 1);
}

TEST_CASE("4 eggs")
{
    REQUIRE(chicken_coop::positions_to_quantity(89) == 4);
}

TEST_CASE("13 eggs")
{
    REQUIRE(chicken_coop::positions_to_quantity(2000000000) == 13);
}

#endif
