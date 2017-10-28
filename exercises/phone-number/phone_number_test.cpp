#include "phone_number.h"
#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

TEST_CASE("cleans_parens_dashes_and_spaces_from_the_number")
{
    const phone_number phone("(123) 456-7890");

    REQUIRE("1234567890" == phone.number());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("cleans_numbers_with_dots")
{
    const phone_number phone("123.456.7890");

    REQUIRE("1234567890" == phone.number());
}

TEST_CASE("valid_when_11_digits_and_first_digit_is_1")
{
    const phone_number phone("11234567890");

    REQUIRE("1234567890" == phone.number());
}

TEST_CASE("invalid_when_11_digits")
{
    const phone_number phone("21234567890");

    REQUIRE("0000000000" == phone.number());
}

TEST_CASE("invalid_when_9_digits")
{
    const phone_number phone("123456789");

    REQUIRE("0000000000" == phone.number());
}

TEST_CASE("has_an_area_code")
{
    const phone_number phone("1234567890");

    REQUIRE("123" == phone.area_code());
}

TEST_CASE("formats_a_number")
{
    const phone_number phone("1234567890");

    REQUIRE("(123) 456-7890" == std::string(phone));
}
#endif
