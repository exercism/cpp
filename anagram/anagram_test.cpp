#include "anagram.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(no_matches)
{
    auto subject = anagram::anagram("diaper");
    auto matches = subject.matches({"hello", "world", "zombies", "pants"});
    vector<string> expected;

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(detects_simple_anagram)
{
    auto subject = anagram::anagram("ant");
    auto matches = subject.matches({"tan", "stand", "at"});
    vector<string> expected{"tan"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(does_not_detect_false_positives)
{
    auto subject = anagram::anagram("galea");
    auto matches = subject.matches({"eagle"});
    vector<string> expected;

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(detects_multiple_anagrams)
{
    auto subject = anagram::anagram("master");
    auto matches = subject.matches({"stream", "pigeon", "maters"});
    vector<string> expected{"stream", "maters"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(does_not_detect_anagram_subsets)
{
    auto subject = anagram::anagram("good");
    auto matches = subject.matches({"dog", "goody"});
    vector<string> expected;

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(detects_anagram)
{
    auto subject = anagram::anagram("listen");
    auto matches = subject.matches({"enlists", "google", "inlets", "banana"});
    vector<string> expected{"inlets"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(detects_multiple_anagrams2)
{
    auto subject = anagram::anagram("allergy");
    auto matches = subject.matches({"gallery", "ballerina", "regally", "clergy", "largely", "leading"});
    vector<string> expected{"gallery", "regally", "largely"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(detects_anagrams_case_insensitively)
{
    auto subject = anagram::anagram("Orchestra");
    auto matches = subject.matches({"cashregister", "Carthorse", "radishes"});
    vector<string> expected{"Carthorse"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(does_not_detect_a_word_as_its_own_anagram)
{
    auto subject = anagram::anagram("banana");
    auto matches = subject.matches({"Banana"});
    vector<string> expected;

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(matches_accepts_string_arguments)
{
    auto subject = anagram::anagram("ant");
    auto matches = subject.matches({"stand", "tan", "at"});
    vector<string> expected{"tan"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}
#endif
