#include "change.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("change_for_1_cent", "[d0ebd0e1-9d27-4609-a654-df5c0ba1d83a]") {
    REQUIRE(change::find_fewest_coins({1, 5, 10, 25}, 1) ==
            std::vector<int>{1});
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("single_coin_change", "[36887bea-7f92-4a9c-b0cc-c0e886b3ecc8]") {
    REQUIRE(change::find_fewest_coins({1, 5, 10, 25, 100}, 25) ==
            std::vector<int>{25});
}

TEST_CASE("multiple_coin_change", "[cef21ccc-0811-4e6e-af44-f011e7eab6c6]") {
    REQUIRE(change::find_fewest_coins({1, 5, 10, 25, 100}, 15) ==
            std::vector<int>{5, 10});
}

TEST_CASE("change_with_Lilliputian_Coins",
          "[d60952bc-0c1a-4571-bf0c-41be72690cb3]") {
    REQUIRE(change::find_fewest_coins({1, 4, 15, 20, 50}, 23) ==
            std::vector<int>{4, 4, 15});
}

TEST_CASE("change_with_Lower_Elbonia_Coins",
          "[408390b9-fafa-4bb9-b608-ffe6036edb6c]") {
    REQUIRE(change::find_fewest_coins({1, 5, 10, 21, 25}, 63) ==
            std::vector<int>{21, 21, 21});
}

TEST_CASE("large_target_values", "[7421a4cb-1c48-4bf9-99c7-7f049689132f]") {
    REQUIRE(change::find_fewest_coins({1, 2, 5, 10, 20, 50, 100}, 999) ==
            std::vector<int>{2, 2, 5, 20, 20, 50, 100, 100, 100, 100, 100, 100,
                             100, 100, 100});
}

TEST_CASE("possible_change_without_unit_coins",
          "[f79d2e9b-0ae3-4d6a-bb58-dc978b0dba28]") {
    REQUIRE(change::find_fewest_coins({2, 5, 10, 20, 50}, 21) ==
            std::vector<int>{2, 2, 2, 5, 10});
}

TEST_CASE("another_possible_change_without_unit_coins",
          "[9a166411-d35d-4f7f-a007-6724ac266178]") {
    REQUIRE(change::find_fewest_coins({4, 5}, 27) ==
            std::vector<int>{4, 4, 4, 5, 5, 5});
}

TEST_CASE("a_greedy_approach_is_not_optimal",
          "[ce0f80d5-51c3-469d-818c-3e69dbd25f75]") {
    REQUIRE(change::find_fewest_coins({1, 10, 11}, 20) ==
            std::vector<int>{10, 10});
}

TEST_CASE("no_coins_make_0_change", "[bbbcc154-e9e9-4209-a4db-dd6d81ec26bb]") {
    REQUIRE(change::find_fewest_coins({1, 5, 10, 21, 25}, 0) ==
            std::vector<int>{});
}

TEST_CASE("change_smaller_than_smallest_coin",
          "[c8b81d5a-49bd-4b61-af73-8ee5383a2ce1]") {
    REQUIRE_THROWS_AS(change::find_fewest_coins({5, 10}, 3), std::domain_error);
}

TEST_CASE("no_combination_can_make_target",
          "[3c43e3e4-63f9-46ac-9476-a67516e98f68]") {
    REQUIRE_THROWS_AS(change::find_fewest_coins({5, 10}, 94),
                      std::domain_error);
}

TEST_CASE("cannot_find_negative_change",
          "[8fe1f076-9b2d-4f44-89fe-8a6ccd63c8f3]") {
    REQUIRE_THROWS_AS(change::find_fewest_coins({1, 2, 5}, -5),
                      std::domain_error);
}

#endif
