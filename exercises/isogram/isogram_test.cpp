#include "isogram.h"
#include "test/catch.hpp"

using namespace std;

// Isogram exercise test case data version 1.7.0

TEST_CASE("empty_string")
{
    const bool actual = isogram::is_isogram("");

    const bool expected {true};

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("isogram_with_only_lower_case_characters")
{
    const bool actual = isogram::is_isogram("isogram");
    
    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("word_with_one_duplicated_character")
{
    const bool actual = isogram::is_isogram("eleven");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("word_with_one_duplicated_character_from_the_end_of_the_alphabet")
{
    const bool actual = isogram::is_isogram("zzyzx");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("longest_reported_english_isogram")
{
    const bool actual = isogram::is_isogram("subdermatoglyphic");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("word_with_duplicated_character_in_mixed_case")
{
    const bool actual = isogram::is_isogram("Alphabet");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("word_with_duplicated_character_in_mixed_case_lowercase_first")
{
    const bool actual = isogram::is_isogram("alphAbet");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("hypothetical_isogrammic_word_with_hyphen")
{
    const bool actual = isogram::is_isogram("thumbscrew-japingly");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("hypothetical_word_with_duplicated_character_following_hyphen")
{
    const bool actual = isogram::is_isogram("thumbscrew-jappingly");
    
    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("isogram_with_duplicated_hyphen")
{
    const bool actual = isogram::is_isogram("six-year-old");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("made_up_name_that_is_an_isogram")
{
    const bool actual = isogram::is_isogram("Emily Jung Schwartzkopf");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("duplicated_character_in_the_middle")
{
    const bool actual = isogram::is_isogram("accentor");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("same_first_and_last_characters")
{
    const bool actual = isogram::is_isogram("angola");

    const bool expected {false};

    REQUIRE(expected == actual);
}

#endif
