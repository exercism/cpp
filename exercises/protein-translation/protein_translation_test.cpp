#include "test/catch.hpp"
#include "protein_translation.h"
#include <vector>
#include <string>

using namespace std;

// Secret-handshake exercise test case data version 1.2.1

TEST_CASE("Methionine_RNA_sequence")
{
    REQUIRE(vector<string>{"Methionine"} == protein_translation::proteins("AUG"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Phenylalanine_RNA_sequence_1")
{
    REQUIRE(vector<string>{"Phenylalanine"} == protein_translation::proteins("UUU"));
}

TEST_CASE("Phenylalanine_RNA_sequence_2")
{
    REQUIRE(vector<string>{"Phenylalanine"} == protein_translation::proteins("UUC"));
}

TEST_CASE("Leucine_RNA_sequence_1")
{
    REQUIRE(vector<string>{"Leucine"} == protein_translation::proteins("UUA"));
}

TEST_CASE("Leucine_RNA_sequence_2")
{
    REQUIRE(vector<string>{"Leucine"} == protein_translation::proteins("UUG"));
}

TEST_CASE("Serine_RNA_sequence_1")
{
    REQUIRE(vector<string>{"Serine"} == protein_translation::proteins("UCU"));
}

TEST_CASE("Serine_RNA_sequence_2")
{
    REQUIRE(vector<string>{"Serine"} == protein_translation::proteins("UCC"));
}

TEST_CASE("Serine_RNA_sequence_3")
{
    REQUIRE(vector<string>{"Serine"} == protein_translation::proteins("UCA"));
}

TEST_CASE("Serine_RNA_sequence_4")
{
    REQUIRE(vector<string>{"Serine"} == protein_translation::proteins("UCG"));
}

TEST_CASE("Tyrosine_RNA_sequence_1")
{
    REQUIRE(vector<string>{"Tyrosine"} == protein_translation::proteins("UAU"));
}

TEST_CASE("Tyrosine_RNA_sequence_2")
{
    REQUIRE(vector<string>{"Tyrosine"} == protein_translation::proteins("UAC"));
}

TEST_CASE("Cysteine_RNA_sequence_1")
{
    REQUIRE(vector<string>{"Cysteine"} == protein_translation::proteins("UGU"));
}

TEST_CASE("Cysteine_RNA_sequence_2")
{
    REQUIRE(vector<string>{"Cysteine"} == protein_translation::proteins("UGC"));
}

TEST_CASE("Tryptophan_RNA_sequence")
{
    REQUIRE(vector<string>{"Tryptophan"} == protein_translation::proteins("UGG"));
}

TEST_CASE("STOP_codon_RNA_sequence_1")
{
    REQUIRE(vector<string>{} == protein_translation::proteins("UAA"));
}

TEST_CASE("STOP_codon_RNA_sequence_2")
{
    REQUIRE(vector<string>{} == protein_translation::proteins("UAG"));
}

TEST_CASE("STOP_codon_RNA_sequence_3")
{
    REQUIRE(vector<string>{} == protein_translation::proteins("UGA"));
}

TEST_CASE("Translate_RNA_strand_into_correct_protein_list")
{
    REQUIRE(vector<string>{"Methionine","Phenylalanine","Tryptophan"}
                == protein_translation::proteins("AUGUUUUGG"));
}

TEST_CASE("Translation_stops_if_STOP_codon_at_beginning_of_sequence")
{
    REQUIRE(vector<string>{} == protein_translation::proteins("UAGUGG"));
}

TEST_CASE("Translation_stops_if_STOP_codon_at_end_of_two-codon_sequence")
{
    REQUIRE(vector<string>{"Tryptophan"} == protein_translation::proteins("UGGUAG"));
}

TEST_CASE("Translation_stops_if_STOP_codon_at_end_of_three-codon_sequence")
{
    REQUIRE(vector<string>{"Methionine","Phenylalanine"}
                        == protein_translation::proteins("AUGUUUUAA"));
}

TEST_CASE("Translation_stops_if_STOP_codon_in_middle_of_three-codon_sequence")
{
    REQUIRE(vector<string>{"Tryptophan"} == protein_translation::proteins("UGGUAGUGG"));
}

TEST_CASE("Translation_stops_if_STOP_codon_in_middle_of_six-codon_sequence")
{
    REQUIRE(vector<string>{"Tryptophan","Cysteine","Tyrosine"}
                        == protein_translation::proteins("UGGUGUUAUUAAUGGUUU"));
}

#endif // !EXERCISM_RUN_ALL_TESTS
