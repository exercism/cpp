#include "hamming.h"
#include <stdexcept>
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(no_difference_between_identical_strands)
{
    BOOST_REQUIRE_EQUAL(0, hamming::compute("A", "A"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
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

BOOST_AUTO_TEST_CASE(domain_error_when_first_string_is_longer)
{
    BOOST_REQUIRE_THROW(hamming::compute("AAAG", "AAA"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(domain_error_when_second_string_is_longer)
{
    BOOST_REQUIRE_THROW(hamming::compute("AAA", "AAAG"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(large_hamming_distance)
{
    BOOST_REQUIRE_EQUAL(4, hamming::compute("GATACA", "GCATAA"));
}

BOOST_AUTO_TEST_CASE(hamming_distance_in_very_long_strand)
{
    BOOST_REQUIRE_EQUAL(9, hamming::compute("GGACGGATTCTG", "AGGACGGATTCT"));
}
#endif
