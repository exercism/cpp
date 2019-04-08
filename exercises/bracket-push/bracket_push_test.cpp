#include "bracket_push.h"
#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

TEST_CASE("paired_square_brackets")
{
    REQUIRE(bracket_push::check("[]"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("empty_string")
{
    REQUIRE(bracket_push::check(""));
}

TEST_CASE("unpaired_brackets")
{
    REQUIRE(!bracket_push::check("[["));
}

TEST_CASE("wrong_ordered_brackets")
{
    REQUIRE(!bracket_push::check("}{"));
}

TEST_CASE("wrong_closing_bracket")
{
    REQUIRE(!bracket_push::check("{]"));
}

TEST_CASE("paired_with_whitespace")
{
    REQUIRE(bracket_push::check("{ }"));
}

TEST_CASE("simple_nested_brackets")
{
    REQUIRE(bracket_push::check("{[]}"));
}

TEST_CASE("several_paired_brackets")
{
    REQUIRE(bracket_push::check("{}[]"));
}

TEST_CASE("paired_nested_brackets")
{
    REQUIRE(bracket_push::check("([{}({}[])])"));
}

TEST_CASE("unopened_closing_brackets")
{
    REQUIRE(!bracket_push::check("{[)][]}"));
}

TEST_CASE("unpaired_nested_brackets")
{
    REQUIRE(!bracket_push::check("([{])"));
}

TEST_CASE("paired_wrong_nested_brackets")
{
    REQUIRE(!bracket_push::check("[({]})"));
}

TEST_CASE("math_expression")
{
    REQUIRE(bracket_push::check("(((185 + 223.85) * 15) - 543)/2"));
}

TEST_CASE("complex_latex_expression")
{
    REQUIRE(bracket_push::check("\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ \\mathrm{e}^{x} &... x^2 \\end{array}\\right)"));
}
#endif
