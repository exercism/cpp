#include "rna_transcription.h"
#include "test/catch.hpp"

TEST_CASE("transcribes_cytidine_to_guanosine")
{
    REQUIRE('G' == transcription::to_rna('C'));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("transcribes_guanosine_to_cytidine")
{
    REQUIRE('C' == transcription::to_rna('G'));
}

TEST_CASE("transcribes_adenosine_to_uracil")
{
    REQUIRE('U' == transcription::to_rna('A'));
}

TEST_CASE("transcribes_thymidine_to_adenosine")
{
    REQUIRE('A' == transcription::to_rna('T'));
}

TEST_CASE("transcribes_all_dna_nucleotides_to_their_rna_complements")
{
    REQUIRE("UGCACCAGAAUU" == transcription::to_rna("ACGTGGTCTTAA"));
}
#endif
