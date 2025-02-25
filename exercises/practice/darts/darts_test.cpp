#include "darts.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("missed_target") { REQUIRE(darts::score(-9, 9) == 0); }

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("on_the_outer_circle") { REQUIRE(darts::score(0, 10) == 1); }

TEST_CASE("on_the_middle_circle") { REQUIRE(darts::score(-5, 0) == 5); }

TEST_CASE("on_the_inner_circle") { REQUIRE(darts::score(0, -1) == 10); }

TEST_CASE("exactly_on_centre") { REQUIRE(darts::score(0, 0) == 10); }

TEST_CASE("near_the_centre") { REQUIRE(darts::score(-0.1f, -0.1f) == 10); }

TEST_CASE("just_within_the_inner_circle") {
    REQUIRE(darts::score(0.7f, 0.7f) == 10);
}

TEST_CASE("just_outside_the_inner_circle") {
    REQUIRE(darts::score(0.8f, -0.8f) == 5);
}

TEST_CASE("just_within_the_middle_circle") {
    REQUIRE(darts::score(-3.5f, 3.5f) == 5);
}

TEST_CASE("just_outside_the_middle_circle") {
    REQUIRE(darts::score(-3.6f, -3.6f) == 1);
}

TEST_CASE("just_within_the_outer_circle") {
    REQUIRE(darts::score(-7.0f, 7.0f) == 1);
}

TEST_CASE("just_outside_the_outer_circle") {
    REQUIRE(darts::score(7.1f, -7.1f) == 0);
}

TEST_CASE("asymmetric_position_between_the_inner_and_middle_circles") {
    REQUIRE(darts::score(0.5f, -4) == 5);
}
#endif
