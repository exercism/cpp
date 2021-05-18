#include "hamming.h"
#include <stdexcept>
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("no_difference_between_identical_strands")
{
    REQUIRE(0 == hamming::compute("A", "A"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("complete_hamming_distance_for_single_nucleotide_strand")
{
    REQUIRE(1 == hamming::compute("A", "G"));
}

TEST_CASE("complete_hamming_distance_for_small_strand")
{
    REQUIRE(2 == hamming::compute("AG", "CT"));
}

TEST_CASE("small_hamming_distance")
{
    REQUIRE(1 == hamming::compute("AT", "CT"));
}

TEST_CASE("small_hamming_distance_in_longer_strand")
{
    REQUIRE(1 == hamming::compute("GGACG", "GGTCG"));
}

TEST_CASE("domain_error_when_first_string_is_longer")
{
    REQUIRE_THROWS_AS(hamming::compute("AAAG", "AAA"), std::domain_error);
}

TEST_CASE("domain_error_when_second_string_is_longer")
{
    REQUIRE_THROWS_AS(hamming::compute("AAA", "AAAG"), std::domain_error);
}

TEST_CASE("large_hamming_distance")
{
    REQUIRE(4 == hamming::compute("GATACA", "GCATAA"));
}

TEST_CASE("hamming_distance_in_very_long_strand")
{
    REQUIRE(9 == hamming::compute("GGACGGATTCTG", "AGGACGGATTCT"));
}
#endif
