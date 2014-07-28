#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

#include "hamming.h"

BOOST_AUTO_TEST_CASE(no_difference_between_identical_strands)
{
    BOOST_REQUIRE_EQUAL(0, hamming::compute("A", "A"));
}

BOOST_AUTO_TEST_CASE(complete_hamming_distance_for_single_nucleotide_strand)
{
    BOOST_REQUIRE_EQUAL(1, hamming::compute("A", "G"));
}

BOOST_AUTO_TEST_CASE(complete_hamming_distance_for_small_strand)
{
    BOOST_REQUIRE_EQUAL(2, hamming::compute("AG", "CT"));
}

BOOST_AUTO_TEST_CASE(small_hamming_distance)
{
    BOOST_REQUIRE_EQUAL(1, hamming::compute("AT", "CT"));
}

BOOST_AUTO_TEST_CASE(small_hamming_distance_in_longer_strand)
{
    BOOST_REQUIRE_EQUAL(1, hamming::compute("GGACG", "GGTCG"));
}

BOOST_AUTO_TEST_CASE(ignores_extra_length_on_first_strand_when_longer)
{
    BOOST_REQUIRE_EQUAL(0, hamming::compute("AAAG", "AAA"));
}

BOOST_AUTO_TEST_CASE(ignores_extra_length_on_other_strand_when_longer)
{
    BOOST_REQUIRE_EQUAL(0, hamming::compute("AAA", "AAAG"));
}

BOOST_AUTO_TEST_CASE(large_hamming_distance)
{
    BOOST_REQUIRE_EQUAL(4, hamming::compute("GATACA", "GCATAA"));
}

BOOST_AUTO_TEST_CASE(hamming_distance_in_very_long_strand)
{
    BOOST_REQUIRE_EQUAL(9, hamming::compute("GGACGGATTCTG", "AGGACGGATTCT"));
}
