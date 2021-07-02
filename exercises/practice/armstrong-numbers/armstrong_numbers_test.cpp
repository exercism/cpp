#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include "armstrong_numbers.h"

// Armstrong-numbers exercise test case data version 1.1.0

TEST_CASE("zero_is_an_armstrong_number")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(0));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("single_digit_numbers_are_armstrong_numbers")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(5));
}

TEST_CASE("there_are_no_2_digit_armstrong_numbers")
{
    REQUIRE_FALSE(armstrong_numbers::is_armstrong_number(10));
}

TEST_CASE("three_digit_number_that_is_an_armstrong_number")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(153));
}

TEST_CASE("three_digit_number_that_is_not_an_armstrong_number")
{
    REQUIRE_FALSE(armstrong_numbers::is_armstrong_number(100));
}

TEST_CASE("four_digit_number_that_is_an_armstrong_number")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(9474));
}

TEST_CASE("four_digit_number_that_is_not_an_armstrong_number")
{
    REQUIRE_FALSE(armstrong_numbers::is_armstrong_number(9475));
}

TEST_CASE("seven_digit_number_that_is_an_armstrong_number")
{
    REQUIRE(armstrong_numbers::is_armstrong_number(9926315));
}

TEST_CASE("seven_digit_number_that_is_not_an_armstrong_number")
{
    REQUIRE_FALSE(armstrong_numbers::is_armstrong_number(9926314));
}
#endif // !EXERCISM_RUN_ALL_TESTS