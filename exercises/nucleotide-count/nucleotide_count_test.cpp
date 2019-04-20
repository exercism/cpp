#include "nucleotide_count.h"
#include "test/catch.hpp"
#include <map>
#include <stdexcept>

TEST_CASE("has_no_nucleotides")
{
    const dna::counter dna("");
    const std::map<char, int> expected{ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} };

    const auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("has_no_adenosine")
{
    const dna::counter dna("");

    REQUIRE(0 == dna.count('A'));
}

TEST_CASE("repetitive_cytidine_gets_counts")
{
    const dna::counter dna("CCCCC");

    REQUIRE(5 == dna.count('C'));
}

TEST_CASE("repetitive_sequence_has_only_guanosine")
{
    const dna::counter dna("GGGGGGGG");
    const std::map<char, int> expected{ {'A', 0}, {'T', 0}, {'C', 0}, {'G', 8} };

    const auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}

TEST_CASE("counts_only_thymidine")
{
    const dna::counter dna("GGGGTAACCCGG");

    REQUIRE(1 == dna.count('T'));
}

TEST_CASE("counts_a_nucleotide_only_once")
{
    const dna::counter dna("GGTTGG");

    dna.count('T');

    REQUIRE(2 == dna.count('T'));
}

TEST_CASE("validates_nucleotides")
{
    const dna::counter dna("GGTTGG");

    REQUIRE_THROWS_AS(dna.count('X'), std::invalid_argument);
}

TEST_CASE("validates_nucleotides_on_construction")
{
    REQUIRE_THROWS_AS(dna::counter("GGTTGGX"), std::invalid_argument);
}

TEST_CASE("counts_all_nucleotides")
{
    const dna::counter dna("AGCTTTTCATTCTGACTGCAACGGGCAATATGTCTCTGTGTGGATTAAAAAAAGAGTGTCTGATAGCAGC");
    std::map<char, int> expected{ {'A', 20}, {'T', 21}, {'G', 17}, {'C', 12} };

    auto actual = dna.nucleotide_counts();

    REQUIRE(expected == actual);
}
#endif
