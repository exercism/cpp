#include "largest_series_product.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


TEST_CASE("finds_the_largest_product_if_span_equals_length")
{
    REQUIRE(largest_series_product::largest_product("29", 2) == 18);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("can_find_the_largest_product_of_2_with_numbers_in_order")
{
    REQUIRE(largest_series_product::largest_product("0123456789", 2) == 72);
}

TEST_CASE("can_find_the_largest_product_of_2")
{
    REQUIRE(largest_series_product::largest_product("576802143", 2) == 48);
}

TEST_CASE("can_find_the_largest_product_of_3_with_numbers_in_order")
{
    REQUIRE(largest_series_product::largest_product("0123456789", 3) == 504);
}

TEST_CASE("can_find_the_largest_product_of_3")
{
    REQUIRE(largest_series_product::largest_product("1027839564", 3) == 270);
}

TEST_CASE("can_find_the_largest_product_of_5_with_numbers_in_order")
{
    REQUIRE(largest_series_product::largest_product("0123456789", 5) == 15120);
}

TEST_CASE("can_get_the_largest_product_of_a_big_number")
{
    REQUIRE(largest_series_product::largest_product("73167176531330624919225119674426574742355349194934", 6) == 23520);
}

TEST_CASE("reports_zero_if_the_only_digits_are_zero")
{
    REQUIRE(largest_series_product::largest_product("0000", 2) == 0);
}

TEST_CASE("reports_zero_if_all_spans_include_zero")
{
    REQUIRE(largest_series_product::largest_product("99099", 3) == 0);
}

TEST_CASE("rejects_span_longer_than_string_length")
{
    REQUIRE_THROWS_AS(largest_series_product::largest_product("123", 4), std::domain_error);
}

TEST_CASE("reports_1_for_empty_string_and_empty_product_0_span")
{
    REQUIRE(largest_series_product::largest_product("", 0) == 1);
}

TEST_CASE("reports_1_for_nonempty_string_and_empty_product_0_span")
{
    REQUIRE(largest_series_product::largest_product("123", 0) == 1);
}

TEST_CASE("rejects_empty_string_and_nonzero_span")
{
    REQUIRE_THROWS_AS(largest_series_product::largest_product("", 1), std::domain_error);
}

TEST_CASE("rejects_invalid_character_in_digits")
{
    REQUIRE_THROWS_AS(largest_series_product::largest_product("1234a5", 2), std::domain_error);
}

TEST_CASE("rejects_negative_span")
{
    REQUIRE_THROWS_AS(largest_series_product::largest_product("12345", -1), std::domain_error);
}
#endif
