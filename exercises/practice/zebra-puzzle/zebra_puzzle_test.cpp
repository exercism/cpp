#include "zebra_puzzle.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("drinks_water", "[16efb4e4-8ad7-4d5e-ba96-e5537b66fd42]") {
    zebra_puzzle::Solution solution = zebra_puzzle::solve();

    SECTION("Drinks water") { REQUIRE(solution.drinksWater == "Norwegian"); }
}

TEST_CASE("owns_zebra", "[084d5b8b-24e2-40e6-b008-c800da8cd257]") {
    zebra_puzzle::Solution solution = zebra_puzzle::solve();

    SECTION("Owns zebra") { REQUIRE(solution.ownsZebra == "Japanese"); }
}
