#include "isogram.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

// Isogram exercise test case data version 1.2.0

BOOST_AUTO_TEST_CASE(empty_string)
{
    const bool actual = isogram::is_isogram("");

    const bool expected {true};

    BOOST_TEST(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(isogram_with_only_lower_case_characters)
{
    const bool actual = isogram::is_isogram("isogram");
    
    const bool expected {true};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(word_with_one_duplicated_character)
{
    const bool actual = isogram::is_isogram("eleven");

    const bool expected {false};

    BOOST_TEST(expected == actual);
}


BOOST_AUTO_TEST_CASE(longest_reported_english_isogram)
{
    const bool actual = isogram::is_isogram("subdermatoglyphic");

    const bool expected {true};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(word_with_duplicated_character_in_mixed_case)
{
    const bool actual = isogram::is_isogram("Alphabet");

    const bool expected {false};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(hypothetical_isogrammic_word_with_hyphen)
{
    const bool actual = isogram::is_isogram("thumbscrew-japingly");

    const bool expected {true};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(isogram_with_duplicated_hyphen)
{
    const bool actual = isogram::is_isogram("six-year-old");

    const bool expected {true};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(made_up_name_that_is_an_isogram)
{
    const bool actual = isogram::is_isogram("Emily Jung Schwartzkopf");

    const bool expected {true};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(duplicated_character_in_the_middle)
{
    const bool actual = isogram::is_isogram("accentor");

    const bool expected {false};

    BOOST_TEST(expected == actual);
}

#endif
