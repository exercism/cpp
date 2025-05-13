#include "bob.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// Bob exercise test case data version 1.4.0

TEST_CASE("stating_something", "[e162fead-606f-437a-a166-d051915cea8e]") {
    REQUIRE("Whatever." == bob::hey("Tom-ay-to, tom-aaaah-to."));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("shouting", "[73a966dc-8017-47d6-bb32-cf07d1a5fcd9]") {
    REQUIRE("Whoa, chill out!" == bob::hey("WATCH OUT!"));
}

TEST_CASE("shouting_gibberish", "[d6c98afd-df35-4806-b55e-2c457c3ab748]") {
    REQUIRE("Whoa, chill out!" == bob::hey("FCECDFCAAB"));
}

TEST_CASE("asking_a_question", "[8a2e771d-d6f1-4e3f-b6c6-b41495556e37]") {
    REQUIRE("Sure." ==
            bob::hey("Does this cryogenic chamber make me look fat?"));
}

TEST_CASE("asking_a_numeric_question",
          "[81080c62-4e4d-4066-b30a-48d8d76920d9]") {
    REQUIRE("Sure." == bob::hey("You are, what, like 15?"));
}

TEST_CASE("asking_gibberish", "[2a02716d-685b-4e2e-a804-2adaf281c01e]") {
    REQUIRE("Sure." == bob::hey("fffbbcbeab?"));
}

TEST_CASE("talking_forcefully", "[c02f9179-ab16-4aa7-a8dc-940145c385f7]") {
    REQUIRE("Whatever." == bob::hey("Let's go make out behind the gym!"));
}

TEST_CASE("using_acronyms_in_regular_speech",
          "[153c0e25-9bb5-4ec5-966e-598463658bcd]") {
    REQUIRE("Whatever." ==
            bob::hey("It's OK if you don't want to go to the DMV."));
}

TEST_CASE("forceful_questions", "[a5193c61-4a92-4f68-93e2-f554eb385ec6]") {
    REQUIRE("Calm down, I know what I'm doing!" ==
            bob::hey("WHAT THE HELL WERE YOU THINKING?"));
}

TEST_CASE("shouting_numbers", "[a20e0c54-2224-4dde-8b10-bd2cdd4f61bc]") {
    REQUIRE("Whoa, chill out!" == bob::hey("1, 2, 3 GO!"));
}

TEST_CASE("no_letters", "[f7bc4b92-bdff-421e-a238-ae97f230ccac]") {
    REQUIRE("Whatever." == bob::hey("1, 2, 3"));
}

TEST_CASE("question_with_no_letters",
          "[bb0011c5-cd52-4a5b-8bfb-a87b6283b0e2]") {
    REQUIRE("Sure." == bob::hey("4?"));
}

TEST_CASE("shouting_with_special_characters",
          "[496143c8-1c31-4c01-8a08-88427af85c66]") {
    REQUIRE("Whoa, chill out!" ==
            bob::hey("ZOMG THE %^*@#$(*^ ZOMBIES ARE COMING!!11!!1!"));
}

TEST_CASE("shouting_with_no_exclamation_mark",
          "[e6793c1c-43bd-4b8d-bc11-499aea73925f]") {
    REQUIRE("Whoa, chill out!" == bob::hey("I HATE THE DMV"));
}

TEST_CASE("statement_containing_question_mark",
          "[aa8097cc-c548-4951-8856-14a404dd236a]") {
    REQUIRE("Whatever." == bob::hey("Ending with ? means a question."));
}

TEST_CASE("non_letters_with_question",
          "[9bfc677d-ea3a-45f2-be44-35bc8fa3753e]") {
    REQUIRE("Sure." == bob::hey(":) ?"));
}

TEST_CASE("prattling_on", "[8608c508-f7de-4b17-985b-811878b3cf45]") {
    REQUIRE("Sure." == bob::hey("Wait! Hang on. Are you going to be OK?"));
}

TEST_CASE("silence", "[bc39f7c6-f543-41be-9a43-fd1c2f753fc0]") {
    REQUIRE("Fine. Be that way!" == bob::hey(""));
}

TEST_CASE("prolonged_silence", "[d6c47565-372b-4b09-b1dd-c40552b8378b]") {
    REQUIRE("Fine. Be that way!" == bob::hey("          "));
}

TEST_CASE("alternate_silence", "[4428f28d-4100-4d85-a902-e5a78cb0ecd3]") {
    REQUIRE("Fine. Be that way!" == bob::hey("\t\t\t\t\t\t\t\t\t\t"));
}

TEST_CASE("multiple_line_question", "[2c7278ac-f955-4eb4-bf8f-e33eb4116a15]") {
    REQUIRE("Sure." ==
            bob::hey("\nDoes this cryogenic chamber make\n me look fat?"));
}

TEST_CASE("starting_with_whitespace",
          "[5371ef75-d9ea-4103-bcfa-2da973ddec1b]") {
    REQUIRE("Whatever." == bob::hey("         hmmmmmmm..."));
}

TEST_CASE("ending_with_whitespace", "[05b304d6-f83b-46e7-81e0-4cd3ca647900]") {
    REQUIRE("Sure." == bob::hey("Okay if like my  spacebar  quite a bit?   "));
}

TEST_CASE("other_whitespace", "[72bd5ad3-9b2f-4931-a988-dce1f5771de2]") {
    REQUIRE("Fine. Be that way!" == bob::hey("\n\r \t"));
}

TEST_CASE("non_question_ending_with_whitespace",
          "[12983553-8601-46a8-92fa-fcaa3bc4a2a0]") {
    REQUIRE("Whatever." ==
            bob::hey("This is a statement ending with whitespace      "));
}
#endif
