
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <exception>
#include <string>
#include <vector>

#include "perfect_numbers.h"

using namespace std;
TEST_CASE("Smallest perfect number is classified correctly") {
    REQUIRE(perfect_numbers::classify(6) == perfect_numbers::perfect);
}
TEST_CASE("Smallest abundant number is classified correctly") {
    REQUIRE(perfect_numbers::classify(12) == perfect_numbers::abundant);
}
TEST_CASE("Smallest prime deficient number is classified correctly") {
    REQUIRE(perfect_numbers::classify(2) == perfect_numbers::deficient);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Medium perfect number is classified correctly") {
    REQUIRE(perfect_numbers::classify(28) == perfect_numbers::perfect);
}
TEST_CASE("Large perfect number is classified correctly") {
    REQUIRE(perfect_numbers::classify(33550336) == perfect_numbers::perfect);
}
TEST_CASE("Medium abundant number is classified correctly") {
    REQUIRE(perfect_numbers::classify(30) == perfect_numbers::abundant);
}
TEST_CASE("Large abundant number is classified correctly") {
    REQUIRE(perfect_numbers::classify(33550335) == perfect_numbers::abundant);
}
TEST_CASE("Smallest non-prime deficient number is classified correctly") {
    REQUIRE(perfect_numbers::classify(4) == perfect_numbers::deficient);
}
TEST_CASE("Medium deficient number is classified correctly") {
    REQUIRE(perfect_numbers::classify(32) == perfect_numbers::deficient);
}
TEST_CASE("Large deficient number is classified correctly") {
    REQUIRE(perfect_numbers::classify(33550337) == perfect_numbers::deficient);
}
TEST_CASE("Edge case (no factors other than itself) is classified correctly") {
    REQUIRE(perfect_numbers::classify(1) == perfect_numbers::deficient);
}
TEST_CASE("Zero is rejected (as it is not a positive integer)") {
    REQUIRE_THROWS_AS(perfect_numbers::classify(0), std::domain_error);
}
TEST_CASE("Negative numbers are rejected") {
    REQUIRE_THROWS_AS(perfect_numbers::classify(-1), std::domain_error);
}

#endif
