#include "nucleotide_count.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <stdexcept>

#if BOOST_VERSION < 105900
namespace boost
{

// teach Boost.Test how to print std::pair
template <typename K, typename V>
inline wrap_stringstream&
operator<<(wrap_stringstream& wrapped, std::pair<const K, V> const& item)
{
    return wrapped << '<' << item.first << ',' << item.second << '>';
}

}
#else
namespace boost { namespace test_tools { namespace tt_detail {

template <typename K, typename V>
inline std::ostream&
operator<<(std::ostream& os, std::pair<const K, V> const& item)
{
    return os << '<' << item.first << ',' << item.second << '>';
}

}}}
#endif

BOOST_AUTO_TEST_CASE(has_no_nucleotides)
{
    const dna::counter dna("");
    const std::map<char, int> expected{ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} };

    const auto actual = dna.nucleotide_counts();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(has_no_adenosine)
{
    const dna::counter dna("");

    BOOST_REQUIRE_EQUAL(0, dna.count('A'));
}

BOOST_AUTO_TEST_CASE(repetitive_cytidine_gets_counts)
{
    const dna::counter dna("CCCCC");

    BOOST_REQUIRE_EQUAL(5, dna.count('C'));
}

BOOST_AUTO_TEST_CASE(repetitive_sequence_has_only_guanosine)
{
    const dna::counter dna("GGGGGGGG");
    const std::map<char, int> expected{ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 8} };

    const auto actual = dna.nucleotide_counts();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(counts_only_thymidine)
{
    const dna::counter dna("GGGGTAACCCGG");

    BOOST_REQUIRE_EQUAL(1, dna.count('T'));
}

BOOST_AUTO_TEST_CASE(counts_a_nucleotide_only_once)
{
    const dna::counter dna("GGTTGG");

    dna.count('T');

    BOOST_REQUIRE_EQUAL(2, dna.count('T'));
}

BOOST_AUTO_TEST_CASE(validates_nucleotides)
{
    const dna::counter dna("GGTTGG");

    BOOST_REQUIRE_THROW(dna.count('X'), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(counts_all_nucleotides)
{
    const dna::counter dna("AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC");
    std::map<char, int> expected{ {'A', 20}, {'T', 21}, {'G', 17}, {'C', 12} };

    auto actual = dna.nucleotide_counts();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}
#endif
