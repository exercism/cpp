#include "bottle_song.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace bottle_song;

TEST_CASE("first_generic_verse", "[d4ccf8fc-01dc-48c0-a201-4fbeb30f2d03]") {
    auto verses = recite(10, 1);
    REQUIRE(verses == std::vector<std::string>{
        "Ten green bottles hanging on the wall,",
        "Ten green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be nine green bottles hanging on the wall."
    });
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("last_generic_verse", "[0f0aded3-472a-4c64-b842-18d4f1f5f030]") {
    auto verses = recite(3, 1);
    REQUIRE(verses == std::vector<std::string>{
        "Three green bottles hanging on the wall,",
        "Three green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be two green bottles hanging on the wall."
    });
}

TEST_CASE("verse_with_2_bottles", "[f61f3c97-131f-459e-b40a-7428f3ed99d9]") {
    auto verses = recite(2, 1);
    REQUIRE(verses == std::vector<std::string>{
        "Two green bottles hanging on the wall,",
        "Two green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be one green bottle hanging on the wall."
    });
}

TEST_CASE("verse_with_1_bottle", "[05eadba9-5dbd-401e-a7e8-d17cc9baa8e0]") {
    auto verses = recite(1, 1);
    REQUIRE(verses == std::vector<std::string>{
        "One green bottle hanging on the wall,",
        "One green bottle hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be no green bottles hanging on the wall."
    });
}

TEST_CASE("first_two_verses", "[a4a28170-83d6-4dc1-bd8b-319b6abb6a80]") {
    auto verses = recite(10, 2);
    REQUIRE(verses == std::vector<std::string>{
        "Ten green bottles hanging on the wall,",
        "Ten green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be nine green bottles hanging on the wall.",
        "",
        "Nine green bottles hanging on the wall,",
        "Nine green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be eight green bottles hanging on the wall."
    });
}

TEST_CASE("last_three_verses", "[3185d438-c5ac-4ce6-bcd3-02c9ff1ed8db]") {
    auto verses = recite(3, 3);
    REQUIRE(verses == std::vector<std::string>{
        "Three green bottles hanging on the wall,",
        "Three green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be two green bottles hanging on the wall.",
        "",
        "Two green bottles hanging on the wall,",
        "Two green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be one green bottle hanging on the wall.",
        "",
        "One green bottle hanging on the wall,",
        "One green bottle hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be no green bottles hanging on the wall."
    });
}

TEST_CASE("all_verses", "[28c1584a-0e51-4b65-9ae2-fbc0bf4bbb28]") {
    auto verses = recite(10, 10);
    REQUIRE(verses == std::vector<std::string>{
        "Ten green bottles hanging on the wall,",
        "Ten green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be nine green bottles hanging on the wall.",
        "",
        "Nine green bottles hanging on the wall,",
        "Nine green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be eight green bottles hanging on the wall.",
        "",
        "Eight green bottles hanging on the wall,",
        "Eight green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be seven green bottles hanging on the wall.",
        "",
        "Seven green bottles hanging on the wall,",
        "Seven green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be six green bottles hanging on the wall.",
        "",
        "Six green bottles hanging on the wall,",
        "Six green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be five green bottles hanging on the wall.",
        "",
        "Five green bottles hanging on the wall,",
        "Five green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be four green bottles hanging on the wall.",
        "",
        "Four green bottles hanging on the wall,",
        "Four green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be three green bottles hanging on the wall.",
        "",
        "Three green bottles hanging on the wall,",
        "Three green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be two green bottles hanging on the wall.",
        "",
        "Two green bottles hanging on the wall,",
        "Two green bottles hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be one green bottle hanging on the wall.",
        "",
        "One green bottle hanging on the wall,",
        "One green bottle hanging on the wall,",
        "And if one green bottle should accidentally fall,",
        "There'll be no green bottles hanging on the wall."
    });
}

#endif