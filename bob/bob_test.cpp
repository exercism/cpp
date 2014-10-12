#include "bob.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(stating_something)
{
    BOOST_REQUIRE_EQUAL("Whatever.", bob::hey("Tom-ay-to, tom-aaaah-to."));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(shouting)
{
    BOOST_REQUIRE_EQUAL("Whoa, chill out!", bob::hey("WATCH OUT!"));
}

BOOST_AUTO_TEST_CASE(asking_a_question)
{
    BOOST_REQUIRE_EQUAL("Sure.", bob::hey("Does this cryogenic chamber make me look fat?"));
}

BOOST_AUTO_TEST_CASE(talking_forcefully)
{
    BOOST_REQUIRE_EQUAL("Whatever.", bob::hey("Let's go make out behind the gym!"));
}

BOOST_AUTO_TEST_CASE(using_acronyms_in_regular_speech)
{
    BOOST_REQUIRE_EQUAL("Whatever.", bob::hey("It's OK if you don't want to go to the DMV."));
}

BOOST_AUTO_TEST_CASE(forceful_questions)
{
    BOOST_REQUIRE_EQUAL("Whoa, chill out!", bob::hey("WHAT THE HELL WERE YOU THINKING?"));
}

BOOST_AUTO_TEST_CASE(shouting_numbers)
{
    BOOST_REQUIRE_EQUAL("Whoa, chill out!", bob::hey("1, 2, 3 GO!"));
}

BOOST_AUTO_TEST_CASE(only_numbers)
{
    BOOST_REQUIRE_EQUAL("Whatever.", bob::hey("1, 2, 3"));
}

BOOST_AUTO_TEST_CASE(question_with_only_numbers)
{
    BOOST_REQUIRE_EQUAL("Sure.", bob::hey("4?"));
}

BOOST_AUTO_TEST_CASE(shouting_with_special_characters)
{
    BOOST_REQUIRE_EQUAL("Whoa, chill out!", bob::hey("ZOMG THE %^*@#$(*^ ZOMBIES ARE COMING!!11!!1!"));
}

BOOST_AUTO_TEST_CASE(shouting_with_no_exclamation_mark)
{
    BOOST_REQUIRE_EQUAL("Whoa, chill out!", bob::hey("I HATE YOU"));
}

BOOST_AUTO_TEST_CASE(statement_containing_question_mark)
{
    BOOST_REQUIRE_EQUAL("Whatever.", bob::hey("Ending with a ? means a question."));
}

BOOST_AUTO_TEST_CASE(prattling_on)
{
    BOOST_REQUIRE_EQUAL("Sure.", bob::hey("Wait! Hang on.  Are you going to be OK?"));
}

BOOST_AUTO_TEST_CASE(question_with_trailing_whitespace)
{
    BOOST_REQUIRE_EQUAL("Sure.", bob::hey("Are you ok? "));
}

BOOST_AUTO_TEST_CASE(silence)
{
    BOOST_REQUIRE_EQUAL("Fine. Be that way!", bob::hey(""));
}

BOOST_AUTO_TEST_CASE(prolonged_silence)
{
    BOOST_REQUIRE_EQUAL("Fine. Be that way!", bob::hey("   "));
}
#endif
