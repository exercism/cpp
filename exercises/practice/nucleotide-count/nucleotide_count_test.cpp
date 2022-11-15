#include "nucleotide_count.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <map>
#include <stdexcept>

TEST_CASE("empty_strand")
{
    const nucleotide_count::counter dna("");
    const std::map<char, int> expected{ {'A', 0}, {'C', 0}, {'G', 0}, {'T', 0} };

    const auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("can_count_one_nucleotide_in_single_character_input")
{
    const nucleotide_count::counter dna("G");
    const std::map<char, int> expected{ {'A', 0}, {'C', 0}, {'G', 1}, {'T', 0} };

    const auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}

TEST_CASE("strand_with_repeated_nucleotide")
{
    const nucleotide_count::counter dna("GGGGGGG");
    const std::map<char, int> expected{ {'A', 0}, {'C', 0}, {'G', 7}, {'T', 0} };

    const auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}

TEST_CASE("strand_with_multiple_nucleotides")
{
    const nucleotide_count::counter dna("AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC");
    const std::map<char, int> expected{ {'A', 20}, {'C', 12}, {'G', 17}, {'T', 21} };

    const auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}

TEST_CASE("strand_with_invalid_nucleotides")
{
    REQUIRE_THROWS_AS(nucleotide_count::counter("AGXXACT"), std::invalid_argument);
}
#endif
