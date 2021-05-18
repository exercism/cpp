#include "matching_brackets.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("paired_square_brackets")
{
    REQUIRE(matching_brackets::check("[]"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("empty_string")
{
    REQUIRE(matching_brackets::check(""));
}

TEST_CASE("unpaired_brackets")
{
    REQUIRE(!matching_brackets::check("[["));
}

TEST_CASE("wrong_ordered_brackets")
{
    REQUIRE(!matching_brackets::check("}{"));
}

TEST_CASE("wrong_closing_bracket")
{
    REQUIRE(!matching_brackets::check("{]"));
}

TEST_CASE("paired_with_whitespace")
{
    REQUIRE(matching_brackets::check("{ }"));
}

TEST_CASE("simple_nested_brackets")
{
    REQUIRE(matching_brackets::check("{[]}"));
}

TEST_CASE("several_paired_brackets")
{
    REQUIRE(matching_brackets::check("{}[]"));
}

TEST_CASE("paired_nested_brackets")
{
    REQUIRE(matching_brackets::check("([{}({}[])])"));
}

TEST_CASE("unopened_closing_brackets")
{
    REQUIRE(!matching_brackets::check("{[)][]}"));
}

TEST_CASE("unpaired_nested_brackets")
{
    REQUIRE(!matching_brackets::check("([{])"));
}

TEST_CASE("paired_wrong_nested_brackets")
{
    REQUIRE(!matching_brackets::check("[({]})"));
}

TEST_CASE("math_expression")
{
    REQUIRE(matching_brackets::check("(((185 + 223.85) * 15) - 543)/2"));
}

TEST_CASE("complex_latex_expression")
{
    REQUIRE(matching_brackets::check("\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ \\mathrm{e}^{x} &... x^2 \\end{array}\\right)"));
}
#endif
