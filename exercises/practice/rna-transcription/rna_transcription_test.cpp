#include "rna_transcription.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("transcribes_cytidine_to_guanosine")
{
    REQUIRE('G' == rna_transcription::to_rna('C'));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("transcribes_guanosine_to_cytidine")
{
    REQUIRE('C' == rna_transcription::to_rna('G'));
}

TEST_CASE("transcribes_adenosine_to_uracil")
{
    REQUIRE('U' == rna_transcription::to_rna('A'));
}

TEST_CASE("transcribes_thymidine_to_adenosine")
{
    REQUIRE('A' == rna_transcription::to_rna('T'));
}

TEST_CASE("transcribes_all_dna_nucleotides_to_their_rna_complements")
{
    REQUIRE("UGCACCAGAAUU" == rna_transcription::to_rna("ACGTGGTCTTAA"));
}
#endif
