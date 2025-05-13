#include "affine_cipher.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("encode_yes", "[2ee1d9af-1c43-416c-b41b-cefd7d4d2b2a]") {
    REQUIRE(affine_cipher::encode("yes", 5, 7) == "xbt");
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("encode_no", "[785bade9-e98b-4d4f-a5b0-087ba3d7de4b]") {
    REQUIRE(affine_cipher::encode("no", 15, 18) == "fu");
}

TEST_CASE("encode_OMG", "[2854851c-48fb-40d8-9bf6-8f192ed25054]") {
    REQUIRE(affine_cipher::encode("OMG", 21, 3) == "lvz");
}

TEST_CASE("encode_O_M_G", "[bc0c1244-b544-49dd-9777-13a770be1bad]") {
    REQUIRE(affine_cipher::encode("O M G", 25, 47) == "hjp");
}

TEST_CASE("encode_mindblowingly", "[381a1a20-b74a-46ce-9277-3778625c9e27]") {
    REQUIRE(affine_cipher::encode("mindblowingly", 11, 15) ==
            "rzcwa gnxzc dgt");
}

TEST_CASE("encode_numbers", "[6686f4e2-753b-47d4-9715-876fdc59029d]") {
    REQUIRE(affine_cipher::encode("Testing,1 2 3, testing.", 3, 4) ==
            "jqgjc rw123 jqgjc rw");
}

TEST_CASE("encode_deep_thought", "[ae23d5bd-30a8-44b6-afbe-23c8c0c7faa3]") {
    REQUIRE(affine_cipher::encode("Truth is fiction.", 5, 17) ==
            "iynia fdqfb ifje");
}

TEST_CASE("encode_all_the_letters", "[c93a8a4d-426c-42ef-9610-76ded6f7ef57]") {
    REQUIRE(affine_cipher::encode(
                "The quick brown fox jumps over the lazy dog.", 17, 33) ==
            "swxtj npvyk lruol iejdc blaxk swxmh qzglf");
}

TEST_CASE("encode_with_a_not_coprime_to_m",
          "[0673638a-4375-40bd-871c-fb6a2c28effb]") {
    REQUIRE_THROWS_AS(affine_cipher::encode("This is a test.", 6, 17),
                      std::invalid_argument);
}

TEST_CASE("decode_exercism", "[3f0ac7e2-ec0e-4a79-949e-95e414953438]") {
    REQUIRE(affine_cipher::decode("tytgn fjr", 3, 7) == "exercism");
}

TEST_CASE("decode_a_sentence", "[241ee64d-5a47-4092-a5d7-7939d259e077]") {
    REQUIRE(affine_cipher::decode("qdwju nqcro muwhn odqun oppmd aunwd o", 19,
                                  16) == "anobstacleisoftenasteppingstone");
}

TEST_CASE("decode_numbers", "[33fb16a1-765a-496f-907f-12e644837f5e]") {
    REQUIRE(affine_cipher::decode("odpoz ub123 odpoz ub", 25, 7) ==
            "testing123testing");
}

TEST_CASE("decode_all_the_letters", "[20bc9dce-c5ec-4db6-a3f1-845c776bcbf7]") {
    REQUIRE(affine_cipher::decode("swxtj npvyk lruol iejdc blaxk swxmh qzglf",
                                  17,
                                  33) == "thequickbrownfoxjumpsoverthelazydog");
}

TEST_CASE("decode_with_no_spaces_in_input",
          "[623e78c0-922d-49c5-8702-227a3e8eaf81]") {
    REQUIRE(affine_cipher::decode("swxtjnpvyklruoliejdcblaxkswxmhqzglf", 17,
                                  33) == "thequickbrownfoxjumpsoverthelazydog");
}

TEST_CASE("decode_with_too_many_spaces",
          "[58fd5c2a-1fd9-4563-a80a-71cff200f26f]") {
    REQUIRE(affine_cipher::decode("vszzm    cly   yd cg    qdp", 15, 16) ==
            "jollygreengiant");
}

TEST_CASE("decode_with_a_not_coprime_to_m",
          "[b004626f-c186-4af9-a3f4-58f74cdb86d5]") {
    REQUIRE_THROWS_AS(affine_cipher::decode("Test", 13, 5),
                      std::invalid_argument);
}

#endif