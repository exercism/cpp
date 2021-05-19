#include "all_your_base.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;

//all-your-base exercise test case data version 2.3.0

TEST_CASE("single_bit_one_to_decimal") {
    vector<unsigned int> in_digits{1};
    vector<unsigned int> expected{1};
    vector<unsigned int> out_digits = all_your_base::convert(2, in_digits, 10);

    REQUIRE(expected == out_digits);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("binary_to_single_decimal") {
    vector<unsigned int> in_digits{1, 0, 1};
    vector<unsigned int> expected{5};
    vector<unsigned int> out_digits = all_your_base::convert(2, in_digits, 10);

    REQUIRE(expected == out_digits);
}

TEST_CASE("single_decimal_to_binary") {
    vector<unsigned int> in_digits{5};
    vector<unsigned int> expected{1, 0, 1};
    vector<unsigned int> out_digits = all_your_base::convert(10, in_digits, 2);

    REQUIRE(expected == out_digits);
}

TEST_CASE("binary_to_multiple_decimal") {
    vector<unsigned int> in_digits{1, 0, 1, 0, 1, 0};
    vector<unsigned int> expected{4, 2};
    vector<unsigned int> out_digits = all_your_base::convert(2, in_digits, 10);

    REQUIRE(expected == out_digits);
}

TEST_CASE("decimal_to_binary") {
    vector<unsigned int> in_digits{4, 2};
    vector<unsigned int> expected{1, 0, 1, 0, 1, 0};
    vector<unsigned int> out_digits = all_your_base::convert(10, in_digits, 2);

    REQUIRE(expected == out_digits);
}

TEST_CASE("trinary_to_hexadecimal") {
    vector<unsigned int> in_digits{1, 1, 2, 0};
    vector<unsigned int> expected{2, 10};
    vector<unsigned int> out_digits = all_your_base::convert(3, in_digits, 16);

    REQUIRE(expected == out_digits);
}

TEST_CASE("hexadecimal_to_trinary") {
    vector<unsigned int> in_digits{2, 10};
    vector<unsigned int> expected{1, 1, 2, 0};
    vector<unsigned int> out_digits = all_your_base::convert(16, in_digits, 3);

    REQUIRE(expected == out_digits);
}

TEST_CASE("fifteen_bit_integer") {
    vector<unsigned int> in_digits{3, 46, 60};
    vector<unsigned int> expected{6, 10, 45};
    vector<unsigned int> out_digits = all_your_base::convert(97, in_digits, 73);

    REQUIRE(expected == out_digits);
}

TEST_CASE("empty_list") {
    vector<unsigned int> in_digits{};
    vector<unsigned int> expected{};
    vector<unsigned int> out_digits = all_your_base::convert(2, in_digits, 10);

    REQUIRE(expected == out_digits);
}

TEST_CASE("single_zero") {
    vector<unsigned int> in_digits{0};
    vector<unsigned int> expected{};
    vector<unsigned int> out_digits = all_your_base::convert(10, in_digits, 2);

    REQUIRE(expected == out_digits);
}

TEST_CASE("multiple_zeros") {
    vector<unsigned int> in_digits{0, 0, 0};
    vector<unsigned int> expected{};
    vector<unsigned int> out_digits = all_your_base::convert(10, in_digits, 2);

    REQUIRE(expected == out_digits);
}

TEST_CASE("leading_zeros") {
    vector<unsigned int> in_digits{0, 6, 0};
    vector<unsigned int> expected{4, 2};
    vector<unsigned int> out_digits = all_your_base::convert(7, in_digits, 10);

    REQUIRE(expected == out_digits);
}

TEST_CASE("first_base_is_one") {
    vector<unsigned int> in_digits{};

    REQUIRE_THROWS_AS(all_your_base::convert(1, in_digits, 10), std::invalid_argument);
}

TEST_CASE("first_base_is_zero") {
    vector<unsigned int> in_digits{};

    REQUIRE_THROWS_AS(all_your_base::convert(0, in_digits, 10), std::invalid_argument);
}

TEST_CASE("invalid_positive_digit") {
    vector<unsigned int> in_digits{1, 2, 1, 0, 1, 0};

    REQUIRE_THROWS_AS(all_your_base::convert(2, in_digits, 10), std::invalid_argument);
}

TEST_CASE("second_base_is_one") {
    vector<unsigned int> in_digits{1, 0, 1, 0, 1, 0};

    REQUIRE_THROWS_AS(all_your_base::convert(2, in_digits, 1), std::invalid_argument);
}

TEST_CASE("second_base_is_zero") {
    vector<unsigned int> in_digits{7};

    REQUIRE_THROWS_AS(all_your_base::convert(10, in_digits, 0), std::invalid_argument);
}

#endif
