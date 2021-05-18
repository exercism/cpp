#include "two_fer.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <string>

// two-fer exercise test case data version 1.2.0

TEST_CASE("no_name_given")
{
    const std::string actual = two_fer::two_fer();
    const std::string expected = "One for you, one for me.";
    REQUIRE(actual == expected);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("a_name_given")
{
    const std::string name = "Alice";
    const std::string actual = two_fer::two_fer(name);
    const std::string expected = "One for Alice, one for me.";
    REQUIRE(actual == expected);
}

TEST_CASE("another_name_given")
{
    const std::string name = "Bob";
    const std::string actual = two_fer::two_fer(name);
    const std::string expected = "One for Bob, one for me.";
    REQUIRE(actual == expected);
}
#endif

