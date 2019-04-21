#include "anagram.h"
#include "test/catch.hpp"

using namespace std;

TEST_CASE("no_matches")
{
    // 'anagram::anagram' defines a class
    anagram::anagram subject = anagram::anagram("diaper");
    auto matches = subject.matches({"hello", "world", "zombies", "pants"});
    vector<string> expected;

    REQUIRE(expected == matches);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("detects_simple_anagram")
{
    auto subject = anagram::anagram("ant");
    auto matches = subject.matches({"tan", "stand", "at"});
    vector<string> expected{"tan"};

    REQUIRE(expected == matches);
}

TEST_CASE("does_not_detect_false_positives")
{
    auto subject = anagram::anagram("galea");
    auto matches = subject.matches({"eagle"});
    vector<string> expected;

    REQUIRE(expected == matches);
}

TEST_CASE("detects_multiple_anagrams")
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

TEST_CASE("detects_multiple_anagrams2")
{
    auto subject = anagram::anagram("allergy");
    auto matches = subject.matches({"gallery", "ballerina", "regally", "clergy", "largely", "leading"});
    vector<string> expected{"gallery", "regally", "largely"};

    REQUIRE(expected == matches);
}

TEST_CASE("detects_anagrams_case_insensitively")
{
    auto subject = anagram::anagram("Orchestra");
    auto matches = subject.matches({"cashregister", "Carthorse", "radishes"});
    vector<string> expected{"Carthorse"};

    REQUIRE(expected == matches);
}

TEST_CASE("does_not_detect_a_word_as_its_own_anagram")
{
    auto subject = anagram::anagram("banana");
    auto matches = subject.matches({"Banana"});
    vector<string> expected;

    REQUIRE(expected == matches);
}

TEST_CASE("matches_accepts_string_arguments")
{
    auto subject = anagram::anagram("ant");
    auto matches = subject.matches({"stand", "tan", "at"});
    vector<string> expected{"tan"};

    REQUIRE(expected == matches);
}
#endif
