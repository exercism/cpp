#include "series.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <stdexcept>
using namespace std;

TEST_CASE("slices_of_one_from_one")
{
    const vector<string> expected{ "1" };

    const vector<string> actual{series::slice("1", 1)};

    REQUIRE(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("slices_of_one_from_two")
{
    const vector<string> expected{ "1", "2" };

    const vector<string> actual{series::slice("12", 1)};

    REQUIRE(expected == actual);
}

TEST_CASE("slices_of_two")
{
    const vector<string> expected{ "35" };

    const vector<string> actual{series::slice("35", 2)};

    REQUIRE(expected == actual);
}

TEST_CASE("slices_of_two_overlap")
{
    const vector<string> expected{ "91", "14", "42" };

    const vector<string> actual{series::slice("9142", 2)};

    REQUIRE(expected == actual);
}

TEST_CASE("slices_can_include_duplicates")
{
    const vector<string> expected{ "777", "777", "777", "777" };

    const vector<string> actual{series::slice("777777", 3)};

    REQUIRE(expected == actual);
}

TEST_CASE("slices_of_a_long_series")
{
    const vector<string> expected{ "91849", "18493", "84939", "49390", "93904", "39042", "90424", "04243" };

    const vector<string> actual{series::slice("918493904243", 5)};

    REQUIRE(expected == actual);
}

TEST_CASE("slice_length_is_too_large")
{
    REQUIRE_THROWS_AS(series::slice("12345", 6), domain_error);
}

TEST_CASE("slice_length_cannot_be_zero")
{
    REQUIRE_THROWS_AS(series::slice("12345", 0), domain_error);
}

TEST_CASE("slice_length_cannot_be_negative")
{
    REQUIRE_THROWS_AS(series::slice("123", -1), domain_error);
}

TEST_CASE("empty_series_is_invalid")
{
    REQUIRE_THROWS_AS(series::slice("", 1), domain_error);
}
#endif
