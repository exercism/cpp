#include "phone_number.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("cleans_the_number", "[79666dce-e0f1-46de-95a1-563802913c35]") {
    REQUIRE("2234567890" ==
            phone_number::phone_number("(223) 456-7890").number());
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("cleans_numbers_with_dots",
          "[c360451f-549f-43e4-8aba-fdf6cb0bf83f]") {
    REQUIRE("2234567890" ==
            phone_number::phone_number("223.456.7890").number());
}

TEST_CASE("cleans_numbers_with_multiple_spaces",
          "[08f94c34-9a37-46a2-a123-2a8e9727395d]") {
    REQUIRE("2234567890" ==
            phone_number::phone_number("223 456   7890   ").number());
}

TEST_CASE("invalid_when_9_digits", "[2de74156-f646-42b5-8638-0ef1d8b58bc2]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("123456789"),
                      std::domain_error);
}

TEST_CASE("invalid_when_11_digits_does_not_start_with_a_1",
          "[57061c72-07b5-431f-9766-d97da7c4399d]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("22234567890"),
                      std::domain_error);
}

TEST_CASE("valid_when_11_digits_and_starting_with_1",
          "[9962cbf3-97bb-4118-ba9b-38ff49c64430]") {
    REQUIRE("2234567890" == phone_number::phone_number("12234567890").number());
}

TEST_CASE("valid_when_11_digits_and_starting_with_1_even_with_punctuation",
          "[fa724fbf-054c-4d91-95da-f65ab5b6dbca]") {
    REQUIRE("2234567890" ==
            phone_number::phone_number("+1 (223) 456-7890").number());
}

TEST_CASE("invalid_when_more_than_11_digits",
          "[4a1509b7-8953-4eec-981b-c483358ff531]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("321234567890"),
                      std::domain_error);
}

TEST_CASE("invalid_with_letters", "[eb8a1fc0-64e5-46d3-b0c6-33184208e28a]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("123-abc-7890"),
                      std::domain_error);
}

TEST_CASE("invalid_with_punctuation",
          "[065f6363-8394-4759-b080-e6c8c351dd1f]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("123-@:!-7890"),
                      std::domain_error);
}

TEST_CASE("invalid_if_area_code_starts_with_0",
          "[d77d07f8-873c-4b17-8978-5f66139bf7d7]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("(023) 456-7890"),
                      std::domain_error);
}

TEST_CASE("invalid_if_area_code_starts_with_1",
          "[c7485cfb-1e7b-4081-8e96-8cdb3b77f15e]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("(123) 456-7890"),
                      std::domain_error);
}

TEST_CASE("invalid_if_exchange_code_starts_with_0",
          "[4d622293-6976-413d-b8bf-dd8a94d4e2ac]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("(223) 056-7890"),
                      std::domain_error);
}

TEST_CASE("invalid_if_exchange_code_starts_with_1",
          "[4cef57b4-7d8e-43aa-8328-1e1b89001262]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("(223) 156-7890"),
                      std::domain_error);
}

TEST_CASE("invalid_if_area_code_starts_with_0_on_valid_11_digit_number",
          "[9925b09c-1a0d-4960-a197-5d163cbe308c]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("1 (023) 456-7890"),
                      std::domain_error);
}

TEST_CASE("invalid_if_area_code_starts_with_1_on_valid_11_digit_number",
          "[3f809d37-40f3-44b5-ad90-535838b1a816]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("1 (123) 456-7890"),
                      std::domain_error);
}

TEST_CASE("invalid_if_exchange_code_starts_with_0_on_valid_11_digit_number",
          "[e08e5532-d621-40d4-b0cc-96c159276b65]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("1 (223) 056-7890"),
                      std::domain_error);
}

TEST_CASE("invalid_if_exchange_code_starts_with_1_on_valid_11_digit_number",
          "[57b32f3d-696a-455c-8bf1-137b6d171cdf]") {
    REQUIRE_THROWS_AS(phone_number::phone_number("1 (223) 156-7890"),
                      std::domain_error);
}

#endif