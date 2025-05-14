#include "bowling.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

// Helper to roll the same number of pins many times.
static void rollMany(bowling::Game& game, int n, int pins) {
    for (int i = 0; i < n; ++i) {
        game.roll(pins);
    }
}

TEST_CASE("should_be_able_to_score_a_game_with_all_zeros",
          "[656ae006-25c2-438c-a549-f338e7ec7441]") {
    bowling::Game game{};
    rollMany(game, 20, 0);
    REQUIRE(game.score() == 0);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("should_be_able_to_score_a_game_with_no_strikes_or_spares",
          "[f85dcc56-cd6b-4875-81b3-e50921e3597b]") {
    bowling::Game game{};
    for (int pins :
         {3, 6, 3, 6, 3, 6, 3, 6, 3, 6, 3, 6, 3, 6, 3, 6, 3, 6, 3, 6}) {
        game.roll(pins);
    }
    REQUIRE(game.score() == 90);
}

TEST_CASE("a_spare_followed_by_zeros_is_worth_ten_points",
          "[d1f56305-3ac2-4fe0-8645-0b37e3073e20]") {
    bowling::Game game{};
    game.roll(6);
    game.roll(4);
    rollMany(game, 18, 0);
    REQUIRE(game.score() == 10);
}

TEST_CASE("points_scored_in_the_roll_after_a_spare_are_counted_twice",
          "[0b8c8bb7-764a-4287-801a-f9e9012f8be4]") {
    bowling::Game game{};
    game.roll(6);
    game.roll(4);
    game.roll(3);
    game.roll(0);
    rollMany(game, 16, 0);
    REQUIRE(game.score() == 16);
}

TEST_CASE("consecutive_spares_each_get_a_one_roll_bonus",
          "[4d54d502-1565-4691-84cd-f29a09c65bea]") {
    bowling::Game game{};
    game.roll(5);
    game.roll(5);
    game.roll(3);
    game.roll(7);
    game.roll(4);
    game.roll(0);
    rollMany(game, 14, 0);
    REQUIRE(game.score() == 31);
}

TEST_CASE(
    "a_spare_in_the_last_frame_gets_a_one_roll_bonus_that_is_counted_once",
    "[e5c9cf3d-abbe-4b74-ad48-34051b2b08c0]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(7);
    game.roll(3);
    game.roll(7);
    REQUIRE(game.score() == 17);
}

TEST_CASE("a_strike_earns_ten_points_in_a_frame_with_a_single_roll",
          "[75269642-2b34-4b72-95a4-9be28ab16902]") {
    bowling::Game game{};
    game.roll(10);
    rollMany(game, 18, 0);
    REQUIRE(game.score() == 10);
}

TEST_CASE(
    // clang-format off
    "points_scored_in_the_two_rolls_after_a_strike_are_counted_twice_as_a_bonus",
    // clang-format on
    "[037f978c-5d01-4e49-bdeb-9e20a2e6f9a6]") {
    bowling::Game game{};
    game.roll(10);
    game.roll(5);
    game.roll(3);
    rollMany(game, 16, 0);
    REQUIRE(game.score() == 26);
}

TEST_CASE("consecutive_strikes_each_get_the_two_roll_bonus",
          "[1635e82b-14ec-4cd1-bce4-4ea14bd13a49]") {
    bowling::Game game{};
    game.roll(10);
    game.roll(10);
    game.roll(10);
    game.roll(5);
    game.roll(3);
    rollMany(game, 12, 0);
    REQUIRE(game.score() == 81);
}

TEST_CASE(
    "a_strike_in_the_last_frame_gets_a_two_roll_bonus_that_is_counted_once",
    "[e483e8b6-cb4b-4959-b310-e3982030d766]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    game.roll(7);
    game.roll(1);
    REQUIRE(game.score() == 18);
}

TEST_CASE("rolling_a_spare_with_the_two_roll_bonus_does_not_get_a_bonus_roll",
          "[9d5c87db-84bc-4e01-8e95-53350c8af1f8]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    game.roll(7);
    game.roll(3);
    REQUIRE(game.score() == 20);
}

TEST_CASE("strikes_with_the_two_roll_bonus_do_not_get_bonus_rolls",
          "[576faac1-7cff-4029-ad72-c16bcada79b5]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    game.roll(10);
    game.roll(10);
    REQUIRE(game.score() == 30);
}

TEST_CASE("last_two_strikes_followed_by_only_last_bonus_with_non_strike_points",
          "[efb426ec-7e15-42e6-9b96-b4fca3ec2359]") {
    bowling::Game game{};
    rollMany(game, 16, 0);
    game.roll(10);
    game.roll(10);
    game.roll(0);
    game.roll(1);
    REQUIRE(game.score() == 31);
}

TEST_CASE(
    // clang-format off
    "a_strike_with_the_one_roll_bonus_after_a_spare_in_the_last_frame_does_not_get_a_bonus",
    // clang-format on
    "[72e24404-b6c6-46af-b188-875514c0377b]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(7);
    game.roll(3);
    game.roll(10);
    REQUIRE(game.score() == 20);
}

TEST_CASE("all_strikes_is_a_perfect_game",
          "[62ee4c72-8ee8-4250-b794-234f1fec17b1]") {
    bowling::Game game{};
    rollMany(game, 12, 10);
    REQUIRE(game.score() == 300);
}

TEST_CASE("rolls_cannot_score_negative_points",
          "[1245216b-19c6-422c-b34b-6e4012d7459f]") {
    bowling::Game game{};
    REQUIRE_THROWS_AS(game.roll(-1), std::runtime_error);
}

TEST_CASE("a_roll_cannot_score_more_than_10_points",
          "[5fcbd206-782c-4faa-8f3a-be5c538ba841]") {
    bowling::Game game{};
    REQUIRE_THROWS_AS(game.roll(11), std::runtime_error);
}

TEST_CASE("two_rolls_in_a_frame_cannot_score_more_than_10_points",
          "[fb023c31-d842-422d-ad7e-79ce1db23c21]") {
    bowling::Game game{};
    game.roll(5);
    REQUIRE_THROWS_AS(game.roll(6), std::runtime_error);
}

TEST_CASE(
    // clang-format off
    "bonus_roll_after_a_strike_in_the_last_frame_cannot_score_more_than_10_points",
    // clang-format on
    "[6082d689-d677-4214-80d7-99940189381b]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    REQUIRE_THROWS_AS(game.roll(11), std::runtime_error);
}

TEST_CASE(
    // clang-format off
    "two_bonus_rolls_after_a_strike_in_the_last_frame_cannot_score_more_than_10_points",
    // clang-format on
    "[e9565fe6-510a-4675-ba6b-733a56767a45]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    game.roll(5);
    REQUIRE_THROWS_AS(game.roll(6), std::runtime_error);
}

TEST_CASE(
    // clang-format off
    "two_bonus_rolls_after_a_strike_in_the_last_frame_can_score_more_than_10_points_if_one_is_a_strike",
    // clang-format on
    "[2f6acf99-448e-4282-8103-0b9c7df99c3d]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    game.roll(10);
    game.roll(6);
    REQUIRE(game.score() == 26);
}

TEST_CASE(
    // clang-format off
    "the_second_bonus_rolls_after_a_strike_in_the_last_frame_cannot_be_a_strike_if_the_first_one_is_not_a_strike",
    // clang-format on
    "[6380495a-8bc4-4cdb-a59f-5f0212dbed01]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    game.roll(6);
    REQUIRE_THROWS_AS(game.roll(10), std::runtime_error);
}

TEST_CASE(
    // clang-format off
    "second_bonus_roll_after_a_strike_in_the_last_frame_cannot_score_more_than_10_points",
    // clang-format on
    "[2b2976ea-446c-47a3-9817-42777f09fe7e]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    game.roll(10);
    REQUIRE_THROWS_AS(game.roll(11), std::runtime_error);
}

TEST_CASE("an_unstarted_game_cannot_be_scored",
          "[29220245-ac8d-463d-bc19-98a94cfada8a]") {
    bowling::Game game{};
    REQUIRE_THROWS_AS(game.score(), std::runtime_error);
}

TEST_CASE("an_incomplete_game_cannot_be_scored",
          "[4473dc5d-1f86-486f-bf79-426a52ddc955]") {
    bowling::Game game{};
    game.roll(0);
    game.roll(0);
    REQUIRE_THROWS_AS(game.score(), std::runtime_error);
}

TEST_CASE("cannot_roll_if_game_already_has_ten_frames",
          "[2ccb8980-1b37-4988-b7d1-e5701c317df3]") {
    bowling::Game game{};
    rollMany(game, 20, 0);
    REQUIRE_THROWS_AS(game.roll(0), std::runtime_error);
}

TEST_CASE(
    // clang-format off
    "bonus_rolls_for_a_strike_in_the_last_frame_must_be_rolled_before_score_can_be_calculated",
    // clang-format on
    "[4864f09b-9df3-4b65-9924-c595ed236f1b]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    REQUIRE_THROWS_AS(game.score(), std::runtime_error);
}

TEST_CASE(
    // clang-format off
    "both_bonus_rolls_for_a_strike_in_the_last_frame_must_be_rolled_before_score_can_be_calculated",
    // clang-format on
    "[537f4e37-4b51-4d1c-97e2-986eb37b2ac1]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    game.roll(10);
    REQUIRE_THROWS_AS(game.score(), std::runtime_error);
}

TEST_CASE(
    // clang-format off
    "bonus_roll_for_a_spare_in_the_last_frame_must_be_rolled_before_score_can_be_calculated",
    // clang-format on
    "[8134e8c1-4201-4197-bf9f-1431afcde4b9]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(7);
    game.roll(3);
    REQUIRE_THROWS_AS(game.score(), std::runtime_error);
}

TEST_CASE("cannot_roll_after_bonus_roll_for_spare",
          "[9d4a9a55-134a-4bad-bae8-3babf84bd570]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(7);
    game.roll(3);
    game.roll(2);
    REQUIRE_THROWS_AS(game.roll(2), std::runtime_error);
}

TEST_CASE("cannot_roll_after_bonus_rolls_for_strike",
          "[d3e02652-a799-4ae3-b53b-68582cc604be]") {
    bowling::Game game{};
    rollMany(game, 18, 0);
    game.roll(10);
    game.roll(3);
    game.roll(2);
    REQUIRE_THROWS_AS(game.roll(2), std::runtime_error);
}

#endif
