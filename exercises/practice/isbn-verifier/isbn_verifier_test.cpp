#include "isbn_verifier.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


TEST_CASE("valid_isbn")
{
    REQUIRE(isbn_verifier::is_valid("3-598-21508-8"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("invalid_isbn_check_digit")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("3-598-21508-9"));
}

TEST_CASE("valid_isbn_with_a_check_digit_of_10")
{
    REQUIRE(isbn_verifier::is_valid("3-598-21507-X"));
}

TEST_CASE("check_digit_is_a_character_other_than_x")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("3-598-21507-A"));
}

TEST_CASE("invalid_check_digit_in_isbn_is_not_treated_as_zero")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("4-598-21507-B"));
}

TEST_CASE("invalid_character_in_isbn_is_not_treated_as_zero")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("3-598-P1581-X"));
}

TEST_CASE("x_is_only_valid_as_a_check_digit")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("3-598-2X507-9"));
}

TEST_CASE("valid_isbn_without_separating_dashes")
{
    REQUIRE(isbn_verifier::is_valid("3598215088"));
}

TEST_CASE("isbn_without_separating_dashes_and_x_as_check_digit")
{
    REQUIRE(isbn_verifier::is_valid("359821507X"));
}

TEST_CASE("isbn_without_check_digit_and_dashes")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("359821507"));
}

TEST_CASE("too_long_isbn_and_no_dashes")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("3598215078X"));
}

TEST_CASE("too_short_isbn")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("00"));
}

TEST_CASE("isbn_without_check_digit")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("3-598-21507"));
}

TEST_CASE("check_digit_of_x_should_not_be_used_for_0")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("3-598-21515-X"));
}

TEST_CASE("empty_isbn")
{
    REQUIRE_FALSE(isbn_verifier::is_valid(""));
}

TEST_CASE("input_is_9_characters")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("134456729"));
}

TEST_CASE("invalid_characters_are_not_ignored_after_checking_length")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("3132P34035"));
}

TEST_CASE("invalid_characters_are_not_ignored_before_checking_length")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("3598P215088"));
}

TEST_CASE("input_is_too_long_but_contains_a_valid_isbn")
{
    REQUIRE_FALSE(isbn_verifier::is_valid("98245726788"));
}
#endif
