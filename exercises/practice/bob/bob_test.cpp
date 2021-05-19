#include "bob.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// Bob exercise test case data version 1.4.0

TEST_CASE("stating_something")
{
    REQUIRE("Whatever." == bob::hey("Tom-ay-to, tom-aaaah-to."));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("shouting")
{
    REQUIRE("Whoa, chill out!" == bob::hey("WATCH OUT!"));
}

TEST_CASE("shouting_gibberish")
{
    REQUIRE("Whoa, chill out!" == bob::hey("FCECDFCAAB"));
}

TEST_CASE("asking_a_question")
{
    REQUIRE("Sure." == bob::hey("Does this cryogenic chamber make me look fat?"));
}

TEST_CASE("asking_a_numeric_question")
{
    REQUIRE("Sure." == bob::hey("You are, what, like 15?"));
}

TEST_CASE("asking_gibberish")
{
    REQUIRE("Sure." == bob::hey("fffbbcbeab?"));
}

TEST_CASE("talking_forcefully")
{
    REQUIRE("Whatever." == bob::hey("Let's go make out behind the gym!"));
}

TEST_CASE("using_acronyms_in_regular_speech")
{
    REQUIRE("Whatever." == bob::hey("It's OK if you don't want to go to the DMV."));
}

TEST_CASE("forceful_questions")
{
    REQUIRE("Calm down, I know what I'm doing!" == bob::hey("WHAT THE HELL WERE YOU THINKING?"));
}

TEST_CASE("shouting_numbers")
{
    REQUIRE("Whoa, chill out!" == bob::hey("1, 2, 3 GO!"));
}

TEST_CASE("no_letters")
{
    REQUIRE("Whatever." == bob::hey("1, 2, 3"));
}

TEST_CASE("question_with_no_letters")
{
    REQUIRE("Sure." == bob::hey("4?"));
}

TEST_CASE("shouting_with_special_characters")
{
    REQUIRE("Whoa, chill out!" == bob::hey("ZOMG THE %^*@#$(*^ ZOMBIES ARE COMING!!11!!1!"));
}

TEST_CASE("shouting_with_no_exclamation_mark")
{
    REQUIRE("Whoa, chill out!" == bob::hey("I HATE THE DMV"));
}

TEST_CASE("statement_containing_question_mark")
{
    REQUIRE("Whatever." == bob::hey("Ending with ? means a question."));
}

TEST_CASE("non_letters_with_question")
{
    REQUIRE("Sure." == bob::hey(":) ?"));
}

TEST_CASE("prattling_on")
{
    REQUIRE("Sure." == bob::hey("Wait! Hang on. Are you going to be OK?"));
}

TEST_CASE("silence")
{
    REQUIRE("Fine. Be that way!" == bob::hey(""));
}

TEST_CASE("prolonged_silence")
{
    REQUIRE("Fine. Be that way!" == bob::hey("          "));
}

TEST_CASE("alternate_silence")
{
    REQUIRE("Fine. Be that way!" == bob::hey("\t\t\t\t\t\t\t\t\t\t"));
}

TEST_CASE("multiple_line_question")
{
	REQUIRE("Whatever." == bob::hey("\nDoes this cryogenic chamber make me look fat?\nNo."));
}

TEST_CASE("starting_with_whitespace")
{
	REQUIRE("Whatever." == bob::hey("         hmmmmmmm..."));
}

TEST_CASE("ending_with_whitespace")
{
	REQUIRE("Sure." == bob::hey("Okay if like my  spacebar  quite a bit?   "));
}

TEST_CASE("other_whitespace")
{
	REQUIRE("Fine. Be that way!" == bob::hey("\n\r \t"));
}

TEST_CASE("non_question_ending_with_whitespace")
{
	REQUIRE("Whatever." == bob::hey("This is a statement ending with whitespace      "));
}
#endif
