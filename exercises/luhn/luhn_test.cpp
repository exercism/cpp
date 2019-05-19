#include "luhn.h"
#include "test/catch.hpp"

//Luhn exercise test case data version 1.6.0

TEST_CASE("single_digit_strings_can_not_be_valid")
{
    const bool actual = luhn::valid("1");

    const bool expected {false};

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("a_single_zero_is_invalid")
{
    const bool actual = luhn::valid("0");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("a_simple_valid_SIN_that_remains_valid_if_reversed")
{
    const bool actual = luhn::valid("059");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("a_simple_valid_SIN_that_becomes_invalid_if_reversed")
{
    const bool actual = luhn::valid("59");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("a_valid_Canadian_SIN")
{
    const bool actual = luhn::valid("055 444 285");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("invalid_Canadian_SIN")
{
    const bool actual = luhn::valid("055 444 286");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("invalid_credit_card")
{
    const bool actual = luhn::valid("8273 1232 7352 0569");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("valid_number_with_an_even_number_of_digits")
{
    const bool actual = luhn::valid("095 245 88");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("valid_number_with_an_odd_number_of_spaces")
{
    const bool actual = luhn::valid("234 567 891 234");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("valid_strings_with_a_non_digit_added_at_the_end_become_invalid")
{
    const bool actual = luhn::valid("059a");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("valid_strings_with_punctuation_included_become_invalid")
{
    const bool actual = luhn::valid("055-444-285");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("valid_strings_with_symbols_included_become_invalid")
{
    const bool actual = luhn::valid("055£ 444$ 285");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("single_zero_with_spaces_invalid")
{
    const bool actual = luhn::valid(" 0");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("more_than_a_single_zero_is_valid")
{
    const bool actual = luhn::valid("0000 0");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("input_digit_9_is_correctly_converted_to_output_digit_9")
{
    const bool actual = luhn::valid("091");

    const bool expected {true};

    REQUIRE(expected == actual);
}

TEST_CASE("using_ascii_value_for_non_doubled_non_digit_is_not_allowed")
{
    const bool actual = luhn::valid("055b 444 285");

    const bool expected {false};

    REQUIRE(expected == actual);
}

TEST_CASE("strings_with_non_digits_is_invalid")
{
    const bool actual = luhn::valid(":9");

    const bool expected {false};

    REQUIRE(expected == actual);
}
#endif
