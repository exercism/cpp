#include "bob.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif
#include <string>

// Bob exercise test case data version 1.4.0
static const std::string WHATEVER("Whatever.");

TEST_CASE("stating_something")
{
    REQUIRE(WHATEVER == bob::hey("Tom-ay-to, tom-aaaah-to."));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

static const std::string CHILL_OUT("Whoa, chill out!"); static const std::string SURE("Sure.");
static const std::string CALM_DOWN("Calm down, I know what I'm doing!");
static const std::string FINE("Fine. Be that way!");

TEST_CASE("shouting")
{
    REQUIRE(CHILL_OUT == bob::hey("WATCH OUT!"));
}

TEST_CASE("shouting_gibberish")
{
    REQUIRE(CHILL_OUT == bob::hey("FCECDFCAAB"));
}

TEST_CASE("asking_a_question")
{
    REQUIRE(SURE == bob::hey("Does this cryogenic chamber make me look fat?"));
}

TEST_CASE("asking_a_numeric_question")
{
    REQUIRE(SURE == bob::hey("You are, what, like 15?"));
}

TEST_CASE("asking_gibberish")
{
    REQUIRE(SURE == bob::hey("fffbbcbeab?"));
}

TEST_CASE("talking_forcefully")
{
    REQUIRE(WHATEVER == bob::hey("Let's go make out behind the gym!"));
}

TEST_CASE("using_acronyms_in_regular_speech")
{
    REQUIRE(WHATEVER == bob::hey("It's OK if you don't want to go to the DMV."));
}

TEST_CASE("forceful_questions")
{
    REQUIRE(CALM_DOWN == bob::hey("WHAT THE HELL WERE YOU THINKING?"));
}

TEST_CASE("shouting_numbers")
{
    REQUIRE(CHILL_OUT == bob::hey("1, 2, 3 GO!"));
}

TEST_CASE("no_letters")
{
    REQUIRE(WHATEVER == bob::hey("1, 2, 3"));
}

TEST_CASE("question_with_no_letters")
{
    REQUIRE(SURE == bob::hey("4?"));
}

TEST_CASE("shouting_with_special_characters")
{
    REQUIRE(CHILL_OUT == bob::hey("ZOMG THE %^*@#$(*^ ZOMBIES ARE COMING!!11!!1!"));
}

TEST_CASE("shouting_with_no_exclamation_mark")
{
    REQUIRE(CHILL_OUT == bob::hey("I HATE THE DMV"));
}

TEST_CASE("statement_containing_question_mark")
{
    REQUIRE(WHATEVER == bob::hey("Ending with ? means a question."));
}

TEST_CASE("non_letters_with_question")
{
    REQUIRE(SURE.compare(bob::hey(":) ?")) == 0);
}

TEST_CASE("prattling_on")
{
    REQUIRE(SURE == bob::hey("Wait! Hang on. Are you going to be OK?"));
}

TEST_CASE("silence")
{
    REQUIRE(FINE == bob::hey(""));
}

TEST_CASE("prolonged_silence")
{
    REQUIRE(FINE == bob::hey("          "));
}

TEST_CASE("alternate_silence")
{
    REQUIRE(FINE == bob::hey("\t\t\t\t\t\t\t\t\t\t"));
}

TEST_CASE("multiple_line_question")
{
	REQUIRE(WHATEVER == bob::hey("\nDoes this cryogenic chamber make me look fat?\nNo."));
}

TEST_CASE("starting_with_whitespace")
{
	REQUIRE(WHATEVER == bob::hey("         hmmmmmmm..."));
}

TEST_CASE("ending_with_whitespace")
{
	REQUIRE(SURE == bob::hey("Okay if like my  spacebar  quite a bit?   "));
}

TEST_CASE("other_whitespace")
{
	REQUIRE(FINE == bob::hey("\n\r \t"));
}

TEST_CASE("non_question_ending_with_whitespace")
{
	REQUIRE(WHATEVER == bob::hey("This is a statement ending with whitespace      "));
}
#endif
