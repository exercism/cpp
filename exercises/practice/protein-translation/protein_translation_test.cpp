#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <string>
#include <vector>

#include "protein_translation.h"

using namespace std;

// Secret-handshake exercise test case data version 1.2.1

TEST_CASE("Methionine RNA sequence", "[96d3d44f-34a2-4db4-84cd-fff523e069be]") {
    REQUIRE(vector<string>{"Methionine"} ==
            protein_translation::proteins("AUG"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Phenylalanine RNA sequence 1",
          "[1b4c56d8-d69f-44eb-be0e-7b17546143d9]") {
    REQUIRE(vector<string>{"Phenylalanine"} ==
            protein_translation::proteins("UUU"));
}

TEST_CASE("Phenylalanine RNA sequence 2",
          "[81b53646-bd57-4732-b2cb-6b1880e36d11]") {
    REQUIRE(vector<string>{"Phenylalanine"} ==
            protein_translation::proteins("UUC"));
}

TEST_CASE("Leucine RNA sequence 1", "[42f69d4f-19d2-4d2c-a8b0-f0ae9ee1b6b4]") {
    REQUIRE(vector<string>{"Leucine"} == protein_translation::proteins("UUA"));
}

TEST_CASE("Leucine RNA sequence 2", "[ac5edadd-08ed-40a3-b2b9-d82bb50424c4]") {
    REQUIRE(vector<string>{"Leucine"} == protein_translation::proteins("UUG"));
}

TEST_CASE("Serine RNA sequence 1", "[8bc36e22-f984-44c3-9f6b-ee5d4e73f120]") {
    REQUIRE(vector<string>{"Serine"} == protein_translation::proteins("UCU"));
}

TEST_CASE("Serine RNA sequence 2", "[5c3fa5da-4268-44e5-9f4b-f016ccf90131]") {
    REQUIRE(vector<string>{"Serine"} == protein_translation::proteins("UCC"));
}

TEST_CASE("Serine RNA sequence 3", "[00579891-b594-42b4-96dc-7ff8bf519606]") {
    REQUIRE(vector<string>{"Serine"} == protein_translation::proteins("UCA"));
}

TEST_CASE("Serine RNA sequence 4", "[08c61c3b-fa34-4950-8c4a-133945570ef6]") {
    REQUIRE(vector<string>{"Serine"} == protein_translation::proteins("UCG"));
}

TEST_CASE("Tyrosine RNA sequence 1", "[54e1e7d8-63c0-456d-91d2-062c72f8eef5]") {
    REQUIRE(vector<string>{"Tyrosine"} == protein_translation::proteins("UAU"));
}

TEST_CASE("Tyrosine RNA sequence 2", "[47bcfba2-9d72-46ad-bbce-22f7666b7eb1]") {
    REQUIRE(vector<string>{"Tyrosine"} == protein_translation::proteins("UAC"));
}

TEST_CASE("Cysteine RNA sequence 1", "[3a691829-fe72-43a7-8c8e-1bd083163f72]") {
    REQUIRE(vector<string>{"Cysteine"} == protein_translation::proteins("UGU"));
}

TEST_CASE("Cysteine RNA sequence 2", "[1b6f8a26-ca2f-43b8-8262-3ee446021767]") {
    REQUIRE(vector<string>{"Cysteine"} == protein_translation::proteins("UGC"));
}

TEST_CASE("Tryptophan RNA sequence", "[1e91c1eb-02c0-48a0-9e35-168ad0cb5f39]") {
    REQUIRE(vector<string>{"Tryptophan"} ==
            protein_translation::proteins("UGG"));
}

TEST_CASE("STOP codon RNA sequence 1",
          "[e547af0b-aeab-49c7-9f13-801773a73557]") {
    REQUIRE(vector<string>{} == protein_translation::proteins("UAA"));
}

TEST_CASE("STOP codon RNA sequence 2",
          "[67640947-ff02-4f23-a2ef-816f8a2ba72e]") {
    REQUIRE(vector<string>{} == protein_translation::proteins("UAG"));
}

TEST_CASE("STOP codon RNA sequence 3",
          "[9c2ad527-ebc9-4ace-808b-2b6447cb54cb]") {
    REQUIRE(vector<string>{} == protein_translation::proteins("UGA"));
}

TEST_CASE("Translate RNA strand into correct protein list",
          "[d0f295df-fb70-425c-946c-ec2ec185388e]") {
    REQUIRE(vector<string>{"Methionine", "Phenylalanine", "Tryptophan"} ==
            protein_translation::proteins("AUGUUUUGG"));
}

TEST_CASE("Sequence of two protein codons translates into proteins",
          "[f4d9d8ee-00a8-47bf-a1e3-1641d4428e54]") {
    REQUIRE(vector<string>{"Phenylalanine", "Phenylalanine"} ==
            protein_translation::proteins("UUUUUU"));
}

TEST_CASE("Sequence of two different protein codons translates into proteins",
          "[dd22eef3-b4f1-4ad6-bb0b-27093c090a9d]") {
    REQUIRE(vector<string>{"Leucine", "Leucine"} ==
            protein_translation::proteins("UUAUUG"));
}

TEST_CASE("Empty RNA sequence results in no proteins",
          "[2c44f7bf-ba20-43f7-a3bf-f2219c0c3f98]") {
    REQUIRE(vector<string>{} == protein_translation::proteins(""));
}

TEST_CASE("Translation stops if STOP codon at beginning of sequence",
          "[e30e8505-97ec-4e5f-a73e-5726a1faa1f4]") {
    REQUIRE(vector<string>{} == protein_translation::proteins("UAGUGG"));
}

TEST_CASE("Translation stops if STOP codon at end of two-codon sequence",
          "[5358a20b-6f4c-4893-bce4-f929001710f3]") {
    REQUIRE(vector<string>{"Tryptophan"} ==
            protein_translation::proteins("UGGUAG"));
}

TEST_CASE("Translation stops if STOP codon at end of three-codon sequence",
          "[ba16703a-1a55-482f-bb07-b21eef5093a3]") {
    REQUIRE(vector<string>{"Methionine", "Phenylalanine"} ==
            protein_translation::proteins("AUGUUUUAA"));
}

TEST_CASE("Translation stops if STOP codon in middle of three-codon sequence",
          "[4089bb5a-d5b4-4e71-b79e-b8d1f14a2911]") {
    REQUIRE(vector<string>{"Tryptophan"} ==
            protein_translation::proteins("UGGUAGUGG"));
}

TEST_CASE("Translation stops if STOP codon in middle of six-codon sequence",
          "[2c2a2a60-401f-4a80-b977-e0715b23b93d]") {
    REQUIRE(vector<string>{"Tryptophan", "Cysteine", "Tyrosine"} ==
            protein_translation::proteins("UGGUGUUAUUAAUGGUUU"));
}

TEST_CASE("Sequence of two non-STOP codons does not translate to a STOP codon",
          "[f6f92714-769f-4187-9524-e353e8a41a80]") {
    REQUIRE(vector<string>{"Methionine", "Methionine"} ==
            protein_translation::proteins("AUGAUG"));
}

#endif  // !EXERCISM_RUN_ALL_TESTS
