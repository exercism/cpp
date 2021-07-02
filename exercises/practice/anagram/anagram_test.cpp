#include "anagram.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

// Anagram exercise test case data version 1.5.0

TEST_CASE("no_matches")
{
    // 'anagram::anagram' defines a class
    anagram::anagram subject = anagram::anagram("diaper");
    auto matches = subject.matches({"hello", "world", "zombies", "pants"});
    vector<string> expected;

    REQUIRE(expected == matches);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("detects_two_anagrams")
{
    auto subject = anagram::anagram("master");
    auto matches = subject.matches({"stream", "pigeon", "maters"});
    vector<string> expected{"stream", "maters"};

    REQUIRE(expected == matches);
}

TEST_CASE("does_not_detect_anagram_subsets")
{
    auto subject = anagram::anagram("good");
    auto matches = subject.matches({"dog", "goody"});
    vector<string> expected;

    REQUIRE(expected == matches);
}

TEST_CASE("detects_anagram")
{
    auto subject = anagram::anagram("listen");
    auto matches = subject.matches({"enlists", "google", "inlets", "banana"});
    vector<string> expected{"inlets"};

    REQUIRE(expected == matches);
}

TEST_CASE("detects_three_anagrams")
{
    auto subject = anagram::anagram("allergy");
    auto matches = subject.matches({
        "gallery",
        "ballerina",
        "regally",
        "clergy",
        "largely",
        "leading"
    });
    vector<string> expected{"gallery", "regally", "largely"};

    REQUIRE(expected == matches);
}

TEST_CASE("detects_multiple_anagrams_with_different_case")
{
    auto subject = anagram::anagram("nose");
    auto matches = subject.matches({"Eons", "ONES"});
    vector<string> expected{"Eons", "ONES"};

    REQUIRE(expected == matches);
}

TEST_CASE("does_not_detect_non_anagrams_with_identical_checksum")
{
    auto subject = anagram::anagram("mass");
    auto matches = subject.matches({"last"});
    vector<string> expected;

    REQUIRE(expected == matches);
}

TEST_CASE("detects_anagrams_case_insensitively")
{
    auto subject = anagram::anagram("Orchestra");
    auto matches = subject.matches({"cashregister", "Carthorse", "radishes"});
    vector<string> expected{"Carthorse"};

    REQUIRE(expected == matches);
}

TEST_CASE("detects_anagrams_using_case_insensitive_subject")
{
    auto subject = anagram::anagram("Orchestra");
    auto matches = subject.matches({"cashregister", "carthorse", "radishes"});
    vector<string> expected{"carthorse"};

    REQUIRE(expected == matches);
}

TEST_CASE("detects_anagrams_using_case_insensitive_possible_matches")
{
    auto subject = anagram::anagram("orchestra");
    auto matches = subject.matches({"cashregister", "Carthorse", "radishes"});
    vector<string> expected{"Carthorse"};

    REQUIRE(expected == matches);
}

TEST_CASE("does_not_detect_a_anagram_if_the_original_word_is_repeated")
{
    auto subject = anagram::anagram("go");
    auto matches = subject.matches({"go Go GO"});
    vector<string> expected;

    REQUIRE(expected == matches);
}

TEST_CASE("anagrams_must_use_all_letters_exactly_once")
{
    auto subject = anagram::anagram("tapper");
    auto matches = subject.matches({"patter"});
    vector<string> expected;

    REQUIRE(expected == matches);
}

TEST_CASE("words_are_not_anagrams_of_themselves_case_insensitive")
{
    auto subject = anagram::anagram("BANANA");
    auto matches = subject.matches({"BANANA", "Banana", "banana"});
    vector<string> expected;

    REQUIRE(expected == matches);
}

TEST_CASE("words_other_than_themselves_can_be_anagrams")
{
    auto subject = anagram::anagram("LISTEN");
    auto matches = subject.matches({"Listen", "Silent", "LISTEN"});
    vector<string> expected{"Silent"};

    REQUIRE(expected == matches);
}
#endif
