#include "phone_number.h"

#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <exception>

TEST_CASE("cleans_the_number") {
  REQUIRE("2234567890" == phone_number::phone_number("(223) 456-7890").number());
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("cleans_numbers_with_dots") {
  REQUIRE("2234567890" == phone_number::phone_number("223.456.7890").number());
}

TEST_CASE("cleans_numbers_with_spaces") {
  REQUIRE("2234567890" == phone_number::phone_number("223 456   7890   ").number());
}

TEST_CASE("has_an_area_code") {
  REQUIRE("223" == phone_number::phone_number("+1 (223) 456-7890").area_code());
}

TEST_CASE("formats_a_number") {
  const phone_number::phone_number phone("+1 (223) 456-7890");
  REQUIRE("(223) 456-7890" == std::string(phone));
}

TEST_CASE("invalid_when_9_digits") {
  REQUIRE_THROWS_AS(phone_number::phone_number("123456789"), std::domain_error);
}

TEST_CASE("invalid_when_11_digits_does_not_start_with_a_1") {
  REQUIRE_THROWS_AS(phone_number::phone_number("22234567890"), std::domain_error);
}

TEST_CASE("valid_when_11_digits_and_starting_with_1") {
  REQUIRE("2234567890" == phone_number::phone_number("12234567890").number());
}

TEST_CASE(
    "valid_when_11_digits_and_starting_with_1_even_with_punctuation") {
  REQUIRE("2234567890" == phone_number::phone_number("+1 (223) 456-7890").number());
}

TEST_CASE("invalid_when_more_than_11_digits") {
  REQUIRE_THROWS_AS(phone_number::phone_number("321234567890"), std::domain_error);
}

TEST_CASE("invalid_with_letters") {
  REQUIRE_THROWS_AS(phone_number::phone_number("123-abc-7890"), std::domain_error);
}

TEST_CASE("invalid_with_punctuation") {
  REQUIRE_THROWS_AS(phone_number::phone_number("123-@:!-7890"), std::domain_error);
}

TEST_CASE("invalid_if_area_code_starts_with_0") {
  REQUIRE_THROWS_AS(phone_number::phone_number("(023) 456-7890"), std::domain_error);
}

TEST_CASE("invalid_if_area_code_starts_with_1") {
  REQUIRE_THROWS_AS(phone_number::phone_number("(123) 456-7890"), std::domain_error);
}

TEST_CASE("invalid_if_exchange_code_starts_with_0") {
  REQUIRE_THROWS_AS(phone_number::phone_number("(223) 056-7890"), std::domain_error);
}

TEST_CASE("invalid_if_exchange_code_starts_with_1") {
  REQUIRE_THROWS_AS(phone_number::phone_number("(223) 156-7890"), std::domain_error);
}

TEST_CASE(
    "invalid_if_area_code_starts_with_0_on_valid_11_digit_number") {
  REQUIRE_THROWS_AS(phone_number::phone_number("1 (023) 456-7890"), std::domain_error);
}

TEST_CASE(
    "invalid_if_area_code_starts_with_1_on_valid_11_digit_number") {
  REQUIRE_THROWS_AS(phone_number::phone_number("1 (123) 456-7890"), std::domain_error);
}

TEST_CASE(
    "invalid_if_exchange_code_starts_with_0_on_valid_11_digit_number") {
  REQUIRE_THROWS_AS(phone_number::phone_number("1 (223) 056-7890"), std::domain_error);
}

TEST_CASE(
    "invalid_if_exchange_code_starts_with_1_on_valid_11_digit_number") {
  REQUIRE_THROWS_AS(phone_number::phone_number("1 (223) 156-7890"), std::domain_error);
}

#endif