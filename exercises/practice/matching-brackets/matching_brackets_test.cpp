#include "matching_brackets.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("paired_square_brackets", "[81ec11da-38dd-442a-bcf9-3de7754609a5]") {
    REQUIRE(matching_brackets::check("[]"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("empty_string", "[287f0167-ac60-4b64-8452-a0aa8f4e5238]") {
    REQUIRE(matching_brackets::check(""));
}

TEST_CASE("unpaired_brackets", "[6c3615a3-df01-4130-a731-8ef5f5d78dac]") {
    REQUIRE(!matching_brackets::check("[["));
}

TEST_CASE("wrong_ordered_brackets", "[9d414171-9b98-4cac-a4e5-941039a97a77]") {
    REQUIRE(!matching_brackets::check("}{"));
}

TEST_CASE("wrong_closing_bracket", "[f0f97c94-a149-4736-bc61-f2c5148ffb85]") {
    REQUIRE(!matching_brackets::check("{]"));
}

TEST_CASE("paired_with_whitespace", "[754468e0-4696-4582-a30e-534d47d69756]") {
    REQUIRE(matching_brackets::check("{ }"));
}

TEST_CASE("partially_paired_brackets",
          "[ba84f6ee-8164-434a-9c3e-b02c7f8e8545]") {
    REQUIRE(!matching_brackets::check("{[])"));
}

TEST_CASE("simple_nested_brackets", "[3c86c897-5ff3-4a2b-ad9b-47ac3a30651d]") {
    REQUIRE(matching_brackets::check("{[]}"));
}

TEST_CASE("several_paired_brackets", "[2d137f2c-a19e-4993-9830-83967a2d4726]") {
    REQUIRE(matching_brackets::check("{}[]"));
}

TEST_CASE("paired_nested_brackets", "[2e1f7b56-c137-4c92-9781-958638885a44]") {
    REQUIRE(matching_brackets::check("([{}({}[])])"));
}

TEST_CASE("unopened_closing_brackets",
          "[84f6233b-e0f7-4077-8966-8085d295c19b]") {
    REQUIRE(!matching_brackets::check("{[)][]}"));
}

TEST_CASE("unpaired_nested_brackets",
          "[9b18c67d-7595-4982-b2c5-4cb949745d49]") {
    REQUIRE(!matching_brackets::check("([{])"));
}

TEST_CASE("paired_wrong_nested_brackets",
          "[a0205e34-c2ac-49e6-a88a-899508d7d68e]") {
    REQUIRE(!matching_brackets::check("[({]})"));
}

TEST_CASE("paired_and_wrong_nested_brackets_but_innermost_are_correct",
          "[1d5c093f-fc84-41fb-8c2a-e052f9581602]") {
    REQUIRE(!matching_brackets::check("[({}])"));
}

TEST_CASE("paired_incomplete_brackets",
          "[ef47c21b-bcfd-4998-844c-7ad5daad90a8]") {
    REQUIRE(!matching_brackets::check("{}["));
}

TEST_CASE("too_many_closing_brackets",
          "[a4675a40-a8be-4fc2-bc47-2a282ce6edbe]") {
    REQUIRE(!matching_brackets::check("[]]"));
}

TEST_CASE("early_unexpected_brackets",
          "[a345a753-d889-4b7e-99ae-34ac85910d1a]") {
    REQUIRE(!matching_brackets::check(")()"));
}

TEST_CASE("early_mismatched_brackets",
          "[21f81d61-1608-465a-b850-baa44c5def83]") {
    REQUIRE(!matching_brackets::check("{)()"));
}

TEST_CASE("math_expression", "[99255f93-261b-4435-a352-02bdecc9bdf2]") {
    REQUIRE(matching_brackets::check("(((185 + 223.85) * 15) - 543)/2"));
}

TEST_CASE("complex_latex_expression",
          "[8e357d79-f302-469a-8515-2561877256a1]") {
    REQUIRE(matching_brackets::check(
        "\\left(\\begin{array}{cc} \\frac{1}{3} & x\\\\ \\mathrm{e}^{x} &... "
        "x^2 \\end{array}\\right)"));
}
#endif
