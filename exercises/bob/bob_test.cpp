#include "bob.h"
#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

TEST_CASE("stating_something")
{
    REQUIRE("Whatever." == bob::hey("Tom-ay-to, tom-aaaah-to."));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("shouting")
{
    REQUIRE("Whoa, chill out!" == bob::hey("WATCH OUT!"));
}

TEST_CASE("asking_a_question")
{
    REQUIRE("Sure." == bob::hey("Does this cryogenic chamber make me look fat?"));
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
    REQUIRE("Whoa, chill out!" == bob::hey("WHAT THE HELL WERE YOU THINKING?"));
}

TEST_CASE("shouting_numbers")
{
    REQUIRE("Whoa, chill out!" == bob::hey("1, 2, 3 GO!"));
}

TEST_CASE("only_numbers")
{
    REQUIRE("Whatever." == bob::hey("1, 2, 3"));
}

TEST_CASE("question_with_only_numbers")
{
    REQUIRE("Sure." == bob::hey("4?"));
}

TEST_CASE("shouting_with_special_characters")
{
    REQUIRE("Whoa, chill out!" == bob::hey("ZOMG THE %^*@#$(*^ ZOMBIES ARE COMING!!11!!1!"));
}

TEST_CASE("shouting_with_no_exclamation_mark")
{
    REQUIRE("Whoa, chill out!" == bob::hey("I HATE YOU"));
}

TEST_CASE("statement_containing_question_mark")
{
    REQUIRE("Whatever." == bob::hey("Ending with a ? means a question."));
}

TEST_CASE("prattling_on")
{
    REQUIRE("Sure." == bob::hey("Wait! Hang on.  Are you going to be OK?"));
}

TEST_CASE("question_with_trailing_whitespace")
{
    REQUIRE("Sure." == bob::hey("Are you ok? "));
}

TEST_CASE("silence")
{
    REQUIRE("Fine. Be that way!" == bob::hey(""));
}

TEST_CASE("prolonged_silence")
{
    REQUIRE("Fine. Be that way!" == bob::hey("   "));
}

TEST_CASE("not_all_silence")
{
	REQUIRE("Whatever." == bob::hey(" A bit of silence can be nice.  "));
}
#endif
