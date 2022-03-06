#include "darts.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("Missed_target") {
    REQUIRE(darts::score(-9,9) == 0);
}
#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("On_the_outer_circle") {
    REQUIRE(darts::score(0,10) == 1);
}

TEST_CASE("On_the_middle_circle") {
    REQUIRE(darts::score(-5,0) == 5);
}

TEST_CASE("On_the_inner_circle") {
    REQUIRE(darts::score(0,-1) == 10);
}

TEST_CASE("Exactly_on_centre") {
    REQUIRE(darts::score(0,0) == 10);
}

TEST_CASE("Near_the_centre") {
    REQUIRE(darts::score(-0.1,-0.1) == 10);
}

TEST_CASE("Just_within_the_inner_circle") {
    REQUIRE(darts::score(0.7,0.7) == 10);
}

TEST_CASE("Just_outside_the_inner_circle") {
    REQUIRE(darts::score(0.8,-0.8) == 5);
}

TEST_CASE("Just_within_the_middle_circle") {
    REQUIRE(darts::score(-3.5,3.5) == 5);
}

TEST_CASE("Just_outside_the_middle_circle") {
    REQUIRE(darts::score(-3.6,-3.6) == 1);
}

TEST_CASE("Just_within_the_outer_circle") {
    REQUIRE(darts::score(-7.0,7.0) == 1);
}

TEST_CASE("Just_outside_the_outer_circle") {
    REQUIRE(darts::score(7.1,-7.1) == 0);
}

TEST_CASE("Asymmetric_position_between_the_inner_and_middle_circles") {
    REQUIRE(darts::score(0.5,-4) == 5);
}
#endif