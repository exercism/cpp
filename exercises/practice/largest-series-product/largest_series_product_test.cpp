#include "largest_series_product.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("finds_the_largest_product_if_span_equals_length",
          "[7c82f8b7-e347-48ee-8a22-f672323324d4]") {
    REQUIRE(largest_series_product::largest_product("29", 2) == 18);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("can_find_the_largest_product_of_2_with_numbers_in_order",
          "[88523f65-21ba-4458-a76a-b4aaf6e4cb5e]") {
    REQUIRE(largest_series_product::largest_product("0123456789", 2) == 72);
}

TEST_CASE("can_find_the_largest_product_of_2",
          "[f1376b48-1157-419d-92c2-1d7e36a70b8a]") {
    REQUIRE(largest_series_product::largest_product("576802143", 2) == 48);
}

TEST_CASE("can_find_the_largest_product_of_3_with_numbers_in_order",
          "[46356a67-7e02-489e-8fea-321c2fa7b4a4]") {
    REQUIRE(largest_series_product::largest_product("0123456789", 3) == 504);
}

TEST_CASE("can_find_the_largest_product_of_3",
          "[a2dcb54b-2b8f-4993-92dd-5ce56dece64a]") {
    REQUIRE(largest_series_product::largest_product("1027839564", 3) == 270);
}

TEST_CASE("can_find_the_largest_product_of_5_with_numbers_in_order",
          "[673210a3-33cd-4708-940b-c482d7a88f9d]") {
    REQUIRE(largest_series_product::largest_product("0123456789", 5) == 15120);
}

TEST_CASE("can_get_the_largest_product_of_a_big_number",
          "[02acd5a6-3bbf-46df-8282-8b313a80a7c9]") {
    REQUIRE(largest_series_product::largest_product(
                "73167176531330624919225119674426574742355349194934", 6) ==
            23520);
}

TEST_CASE("reports_zero_if_the_only_digits_are_zero",
          "[76dcc407-21e9-424c-a98e-609f269622b5]") {
    REQUIRE(largest_series_product::largest_product("0000", 2) == 0);
}

TEST_CASE("reports_zero_if_all_spans_include_zero",
          "[6ef0df9f-52d4-4a5d-b210-f6fae5f20e19]") {
    REQUIRE(largest_series_product::largest_product("99099", 3) == 0);
}

TEST_CASE("rejects_span_longer_than_string_length",
          "[0ae1ce53-d9ba-41bb-827f-2fceb64f058b]") {
    REQUIRE_THROWS_AS(largest_series_product::largest_product("123", 4),
                      std::domain_error);
}

TEST_CASE("rejects_empty_string_and_nonzero_span",
          "[6cf66098-a6af-4223-aab1-26aeeefc7402]") {
    REQUIRE_THROWS_AS(largest_series_product::largest_product("", 1),
                      std::domain_error);
}

TEST_CASE("rejects_invalid_character_in_digits",
          "[7a38f2d6-3c35-45f6-8d6f-12e6e32d4d74]") {
    REQUIRE_THROWS_AS(largest_series_product::largest_product("1234a5", 2),
                      std::domain_error);
}

TEST_CASE("rejects_negative_span", "[c859f34a-9bfe-4897-9c2f-6d7f8598e7f0]") {
    REQUIRE_THROWS_AS(largest_series_product::largest_product("12345", -1),
                      std::domain_error);
}
#endif
