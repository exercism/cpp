#include "point_mutations.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(no_difference_between_empty_strands)
{
    const auto dna = mutations::dna_sequence("");

    BOOST_REQUIRE_EQUAL(0, dna.hamming_distance(""));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(no_difference_between_identical_strands)
{
    const auto dna = mutations::dna_sequence("GGACTGA");

    BOOST_REQUIRE_EQUAL(0, dna.hamming_distance("GGACTGA"));
}

BOOST_AUTO_TEST_CASE(complete_hamming_distance_in_small_strand)
{
    const auto dna = mutations::dna_sequence("ACT");

    BOOST_REQUIRE_EQUAL(3, dna.hamming_distance("GGA"));
}

BOOST_AUTO_TEST_CASE(hamming_distance_in_off_by_one_strand)
{
    const auto dna = mutations::dna_sequence("GGACGGATTCTGACCTGGACTAATTTTGGGG");

    BOOST_REQUIRE_EQUAL(19, dna.hamming_distance("AGGACGGATTCTGACCTGGACTAATTTTGGGG"));
}

BOOST_AUTO_TEST_CASE(small_hamming_distance_in_middle_somewhere)
{
    const auto dna = mutations::dna_sequence("GGACG");

    BOOST_REQUIRE_EQUAL(1, dna.hamming_distance("GGTCG"));
}

BOOST_AUTO_TEST_CASE(larger_distance)
{
    const auto dna = mutations::dna_sequence("ACCAGGG");

    BOOST_REQUIRE_EQUAL(2, dna.hamming_distance("ACTATGG"));
}

BOOST_AUTO_TEST_CASE(shortens_other_strand_when_longer)
{
    const auto dna = mutations::dna_sequence("AAACTAGGGG");

    BOOST_REQUIRE_EQUAL(3, dna.hamming_distance("AGGCTAGCGGTAGGAC"));
}

BOOST_AUTO_TEST_CASE(shortens_original_strand_when_longer)
{
    const auto dna = mutations::dna_sequence("GACTACGGACAGGGTAGGGAAT");

    BOOST_REQUIRE_EQUAL(5, dna.hamming_distance("GACATCGCACACC"));
}
#endif
