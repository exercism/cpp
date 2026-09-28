#include "alphametics.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("puzzle_with_three_letters",
          "[e0c08b07-9028-4d5f-91e1-d178fead8e1a]") {
    auto result = alphametics::solve("I + BB == ILL");
    REQUIRE(result.has_value());
    auto m = *result;
    REQUIRE(m.at('I') == 1);
    REQUIRE(m.at('B') == 9);
    REQUIRE(m.at('L') == 0);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("solution_must_have_unique_value_for_each_letter",
          "[a504ee41-cb92-4ec2-9f11-c37e95ab3f25]") {
    auto result = alphametics::solve("A == B");
    REQUIRE_FALSE(result.has_value());
}

TEST_CASE("leading_zero_solution_is_invalid",
          "[4e3b81d2-be7b-4c5c-9a80-cd72bc6d465a]") {
    auto result = alphametics::solve("ACA + DD == BD");
    REQUIRE_FALSE(result.has_value());
}

TEST_CASE("puzzle_with_two_digits_final_carry",
          "[8a3e3168-d1ee-4df7-94c7-b9c54845ac3a]") {
    auto result = alphametics::solve(
        "A + A + A + A + A + A + A + A + A + A + A + B == BCC");
    REQUIRE(result.has_value());
    auto m = *result;
    REQUIRE(m.at('A') == 9);
    REQUIRE(m.at('B') == 1);
    REQUIRE(m.at('C') == 0);
}

TEST_CASE("puzzle_with_four_letters",
          "[a9630645-15bd-48b6-a61e-d85c4021cc09]") {
    auto result = alphametics::solve("AS + A == MOM");
    REQUIRE(result.has_value());
    auto m = *result;
    REQUIRE(m.at('A') == 9);
    REQUIRE(m.at('S') == 2);
    REQUIRE(m.at('M') == 1);
    REQUIRE(m.at('O') == 0);
}

TEST_CASE("puzzle_with_six_letters", "[3d905a86-5a52-4e4e-bf80-8951535791bd]") {
    auto result = alphametics::solve("NO + NO + TOO == LATE");
    REQUIRE(result.has_value());
    auto m = *result;
    REQUIRE(m.at('N') == 7);
    REQUIRE(m.at('O') == 4);
    REQUIRE(m.at('T') == 9);
    REQUIRE(m.at('L') == 1);
    REQUIRE(m.at('A') == 0);
    REQUIRE(m.at('E') == 2);
}

TEST_CASE("puzzle_with_seven_letters",
          "[4febca56-e7b7-4789-97b9-530d09ba95f0]") {
    auto result = alphametics::solve("HE + SEES + THE == LIGHT");
    REQUIRE(result.has_value());
    auto m = *result;
    REQUIRE(m.at('E') == 4);
    REQUIRE(m.at('G') == 2);
    REQUIRE(m.at('H') == 5);
    REQUIRE(m.at('I') == 0);
    REQUIRE(m.at('L') == 1);
    REQUIRE(m.at('S') == 9);
    REQUIRE(m.at('T') == 7);
}

TEST_CASE("puzzle_with_eight_letters",
          "[12125a75-7284-4f9a-a5fa-191471e0d44f]") {
    auto result = alphametics::solve("SEND + MORE == MONEY");
    REQUIRE(result.has_value());
    auto m = *result;
    REQUIRE(m.at('S') == 9);
    REQUIRE(m.at('E') == 5);
    REQUIRE(m.at('N') == 6);
    REQUIRE(m.at('D') == 7);
    REQUIRE(m.at('M') == 1);
    REQUIRE(m.at('O') == 0);
    REQUIRE(m.at('R') == 8);
    REQUIRE(m.at('Y') == 2);
}

TEST_CASE("puzzle_with_ten_letters", "[fb05955f-38dc-477a-a0b6-5ef78969fffa]") {
    auto result = alphametics::solve(
        "AND + A + STRONG + OFFENSE + AS + A + GOOD == DEFENSE");
    REQUIRE(result.has_value());
    auto m = *result;
    REQUIRE(m.at('A') == 5);
    REQUIRE(m.at('D') == 3);
    REQUIRE(m.at('E') == 4);
    REQUIRE(m.at('F') == 7);
    REQUIRE(m.at('G') == 8);
    REQUIRE(m.at('N') == 0);
    REQUIRE(m.at('O') == 2);
    REQUIRE(m.at('R') == 1);
    REQUIRE(m.at('S') == 6);
    REQUIRE(m.at('T') == 9);
}

TEST_CASE("puzzle_with_ten_letters_and_199_addends",
          "[9a101e81-9216-472b-b458-b513a7adacf7]") {
    auto result = alphametics::solve(
        "THIS + A + FIRE + THEREFORE + FOR + ALL + HISTORIES + I + TELL + A + "
        "TALE + "
        "THAT + FALSIFIES + ITS + TITLE + TIS + A + LIE + THE + TALE + OF + "
        "THE + LAST + "
        "FIRE + HORSES + LATE + AFTER + THE + FIRST + FATHERS + FORESEE + THE "
        "+ HORRORS + "
        "THE + LAST + FREE + TROLL + TERRIFIES + THE + HORSES + OF + FIRE + "
        "THE + TROLL + "
        "RESTS + AT + THE + HOLE + OF + LOSSES + IT + IS + THERE + THAT + SHE "
        "+ STORES + "
        "ROLES + OF + LEATHERS + AFTER + SHE + SATISFIES + HER + HATE + OFF + "
        "THOSE + FEARS + "
        "A + TASTE + RISES + AS + SHE + HEARS + THE + LEAST + FAR + HORSE + "
        "THOSE + FAST + "
        "HORSES + THAT + FIRST + HEAR + THE + TROLL + FLEE + OFF + TO + THE + "
        "FOREST + THE + "
        "HORSES + THAT + ALERTS + RAISE + THE + STARES + OF + THE + OTHERS + "
        "AS + THE + TROLL + "
        "ASSAILS + AT + THE + TOTAL + SHIFT + HER + TEETH + TEAR + HOOF + OFF "
        "+ TORSO + AS + THE + "
        "LAST + HORSE + FORFEITS + ITS + LIFE + THE + FIRST + FATHERS + HEAR + "
        "OF + THE + HORRORS + "
        "THEIR + FEARS + THAT + THE + FIRES + FOR + THEIR + FEASTS + ARREST + "
        "AS + THE + FIRST + "
        "FATHERS + RESETTLE + THE + LAST + OF + THE + FIRE + HORSES + THE + "
        "LAST + TROLL + HARASSES + "
        "THE + FOREST + HEART + FREE + AT + LAST + OF + THE + LAST + TROLL + "
        "ALL + OFFER + THEIR + "
        "FIRE + HEAT + TO + THE + ASSISTERS + FAR + OFF + THE + TROLL + FASTS "
        "+ ITS + LIFE + SHORTER + "
        "AS + STARS + RISE + THE + HORSES + REST + SAFE + AFTER + ALL + SHARE "
        "+ HOT + FISH + AS + "
        "THEIR + AFFILIATES + TAILOR + A + ROOFS + FOR + THEIR + SAFE == "
        "FORTRESSES");
    REQUIRE(result.has_value());
    auto m = *result;
    REQUIRE(m.at('A') == 1);
    REQUIRE(m.at('E') == 0);
    REQUIRE(m.at('F') == 5);
    REQUIRE(m.at('H') == 8);
    REQUIRE(m.at('I') == 7);
    REQUIRE(m.at('L') == 2);
    REQUIRE(m.at('O') == 6);
    REQUIRE(m.at('R') == 3);
    REQUIRE(m.at('S') == 4);
    REQUIRE(m.at('T') == 9);
}

#endif
