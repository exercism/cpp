#include "zebra_puzzle.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("drinks_water", "[16efb4e4-8ad7-4d5e-ba96-e5537b66fd42]") {
    const zebra_puzzle::zebra_puzzle puzzle;
    REQUIRE("Norwegian" == puzzle.drinks_water());
}

TEST_CASE("owns_zebra", "[084d5b8b-24e2-40e6-b008-c800da8cd257]") {
    const zebra_puzzle::zebra_puzzle puzzle;
    REQUIRE("Japanese" == puzzle.who_owns_zebra());
}

