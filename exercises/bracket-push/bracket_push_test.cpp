#include "bracket_push.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(paired_square_brackets)
{
    BOOST_REQUIRE(bracket_push::check("[]"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(empty_string)
{
    BOOST_REQUIRE(bracket_push::check(""));
}

BOOST_AUTO_TEST_CASE(unpaired_brackets)
{
    BOOST_REQUIRE(!bracket_push::check("[["));
}

BOOST_AUTO_TEST_CASE(wrong_ordered_brackets)
{
    BOOST_REQUIRE(!bracket_push::check("}{"));
}

BOOST_AUTO_TEST_CASE(wrong_closing_bracket)
{
    BOOST_REQUIRE(!bracket_push::check("{]"));
}

BOOST_AUTO_TEST_CASE(paired_with_whitespace)
{
    BOOST_REQUIRE(bracket_push::check("{ }"));
}

BOOST_AUTO_TEST_CASE(simple_nested_brackets)
{
    BOOST_REQUIRE(bracket_push::check("{[]}"));
}

BOOST_AUTO_TEST_CASE(several_paired_brackets)
{
    BOOST_REQUIRE(bracket_push::check("{}[]"));
}

BOOST_AUTO_TEST_CASE(paired_nested_brackets)
{
    BOOST_REQUIRE(bracket_push::check("([{}({}[])])"));
}

BOOST_AUTO_TEST_CASE(unopened_closing_brackets)
{
    BOOST_REQUIRE(!bracket_push::check("{[)][]}"));
}

BOOST_AUTO_TEST_CASE(unpaired_nested_brackets)
{
    BOOST_REQUIRE(!bracket_push::check("([{])"));
}

BOOST_AUTO_TEST_CASE(paired_wrong_nested_brackets)
{
    BOOST_REQUIRE(!bracket_push::check("[({]})"));
}

BOOST_AUTO_TEST_CASE(math_expression)
{
    BOOST_REQUIRE(bracket_push::check("(((185 + 223.85) * 15) - 543)/2"));
}

BOOST_AUTO_TEST_CASE(complex_latex_expression)
{
    BOOST_REQUIRE(bracket_push::check("\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ \\mathrm{e}^{x} &... x^2 \\end{array}\\right)"));
}
#endif
