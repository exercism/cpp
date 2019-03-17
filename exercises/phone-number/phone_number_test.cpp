#include "phone_number.h"

#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <exception>

BOOST_AUTO_TEST_CASE(cleans_the_number) {
  BOOST_REQUIRE_EQUAL("2234567890", phone_number("(223) 456-7890").number());
}

#if defined(EXERCISM_RUN_ALL_TESTS)

BOOST_AUTO_TEST_CASE(cleans_numbers_with_dots) {
  BOOST_REQUIRE_EQUAL("2234567890", phone_number("223.456.7890").number());
}

BOOST_AUTO_TEST_CASE(cleans_numbers_with_spaces) {
  BOOST_REQUIRE_EQUAL("2234567890", phone_number("223 456   7890   ").number());
}

BOOST_AUTO_TEST_CASE(has_an_area_code) {
  BOOST_REQUIRE_EQUAL("223", phone_number("+1 (223) 456-7890").area_code());
}

BOOST_AUTO_TEST_CASE(formats_a_number) {
  const phone_number phone("+1 (223) 456-7890");
  BOOST_REQUIRE_EQUAL("(223) 456-7890", std::string(phone));
}

BOOST_AUTO_TEST_CASE(invalid_when_9_digits) {
  BOOST_REQUIRE_THROW(phone_number("123456789"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(invalid_when_11_digits_does_not_start_with_a_1) {
  BOOST_REQUIRE_THROW(phone_number("22234567890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(valid_when_11_digits_and_starting_with_1) {
  BOOST_REQUIRE_EQUAL("2234567890", phone_number("12234567890").number());
}

BOOST_AUTO_TEST_CASE(
    valid_when_11_digits_and_starting_with_1_even_with_punctuation) {
  BOOST_REQUIRE_EQUAL("2234567890", phone_number("+1 (223) 456-7890").number());
}

BOOST_AUTO_TEST_CASE(invalid_when_more_than_11_digits) {
  BOOST_REQUIRE_THROW(phone_number("321234567890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(invalid_with_letters) {
  BOOST_REQUIRE_THROW(phone_number("123-abc-7890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(invalid_with_punctuation) {
  BOOST_REQUIRE_THROW(phone_number("123-@:!-7890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(invalid_if_area_code_starts_with_0) {
  BOOST_REQUIRE_THROW(phone_number("(023) 456-7890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(invalid_if_area_code_starts_with_1) {
  BOOST_REQUIRE_THROW(phone_number("(123) 456-7890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(invalid_if_exchange_code_starts_with_0) {
  BOOST_REQUIRE_THROW(phone_number("(223) 056-7890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(invalid_if_exchange_code_starts_with_1) {
  BOOST_REQUIRE_THROW(phone_number("(223) 156-7890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(
    invalid_if_area_code_starts_with_0_on_valid_11_digit_number) {
  BOOST_REQUIRE_THROW(phone_number("1 (023) 456-7890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(
    invalid_if_area_code_starts_with_1_on_valid_11_digit_number) {
  BOOST_REQUIRE_THROW(phone_number("1 (123) 456-7890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(
    invalid_if_exchange_code_starts_with_0_on_valid_11_digit_number) {
  BOOST_REQUIRE_THROW(phone_number("1 (223) 056-7890"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(
    invalid_if_exchange_code_starts_with_1_on_valid_11_digit_number) {
  BOOST_REQUIRE_THROW(phone_number("1 (223) 156-7890"), std::domain_error);
}

#endif