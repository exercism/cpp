#include "troll_the_trolls.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace std;
using namespace hellmath;

TEST_CASE("Troll posts are visible to trolls", "[task_2]") {
    AccountStatus poster{AccountStatus::troll};
    AccountStatus viewer{AccountStatus::troll};

    REQUIRE(display_post(poster, viewer));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Troll posts are not visible to non-trolls", "[task_2]") {
    AccountStatus poster{AccountStatus::troll};

    AccountStatus viewer{AccountStatus::guest};
    REQUIRE_FALSE(display_post(poster, viewer));

    viewer = AccountStatus::user;
    REQUIRE_FALSE(display_post(poster, viewer));

    viewer = AccountStatus::mod;
    REQUIRE_FALSE(display_post(poster, viewer));
}

TEST_CASE("Non-troll posts are visible to guests", "[task_2]") {
    AccountStatus viewer{AccountStatus::guest};

    AccountStatus poster{AccountStatus::user};
    REQUIRE(display_post(poster, viewer));

    poster = AccountStatus::mod;
    REQUIRE(display_post(poster, viewer));
}

TEST_CASE("Non-troll posts are visible to trolls", "[task_2]") {
    AccountStatus viewer{AccountStatus::troll};

    AccountStatus poster{AccountStatus::user};
    REQUIRE(display_post(poster, viewer));

    poster = AccountStatus::mod;
    REQUIRE(display_post(poster, viewer));
}

TEST_CASE("Non-troll posts are visible to users", "[task_2]") {
    AccountStatus viewer{AccountStatus::user};

    AccountStatus poster{AccountStatus::user};
    REQUIRE(display_post(poster, viewer));

    poster = AccountStatus::mod;
    REQUIRE(display_post(poster, viewer));
}

TEST_CASE("Non-troll posts are visible to mods", "[task_2]") {
    AccountStatus viewer{AccountStatus::mod};

    AccountStatus poster{AccountStatus::user};
    REQUIRE(display_post(poster, viewer));

    poster = AccountStatus::mod;
    REQUIRE(display_post(poster, viewer));
}

TEST_CASE("Guests have correct permissions", "[task_3]") {
    AccountStatus status{AccountStatus::guest};

    Action action{Action::read};
    REQUIRE(permission_check(action, status));

    action = Action::write;
    REQUIRE_FALSE(permission_check(action, status));

    action = Action::remove;
    REQUIRE_FALSE(permission_check(action, status));
}

TEST_CASE("Trolls have correct permissions", "[task_3]") {
    AccountStatus status{AccountStatus::troll};

    Action action{Action::read};
    REQUIRE(permission_check(action, status));

    action = Action::write;
    REQUIRE(permission_check(action, status));

    action = Action::remove;
    REQUIRE_FALSE(permission_check(action, status));
}

TEST_CASE("Users have correct permissions", "[task_3]") {
    AccountStatus status{AccountStatus::user};

    Action action{Action::read};
    REQUIRE(permission_check(action, status));

    action = Action::write;
    REQUIRE(permission_check(action, status));

    action = Action::remove;
    REQUIRE_FALSE(permission_check(action, status));
}

TEST_CASE("Moderators have correct permissions", "[task_3]") {
    AccountStatus status{AccountStatus::mod};

    Action action{Action::read};
    REQUIRE(permission_check(action, status));

    action = Action::write;
    REQUIRE(permission_check(action, status));

    action = Action::remove;
    REQUIRE(permission_check(action, status));
}

TEST_CASE("Guests cannot start games", "[task_4]") {
    // First player is a guest
    AccountStatus player1{AccountStatus::guest};

    AccountStatus player2{AccountStatus::guest};
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player2 = AccountStatus::troll;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player2 = AccountStatus::user;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player2 = AccountStatus::mod;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    // Second player is a guest
    player2 = AccountStatus::guest;

    player1 = AccountStatus::troll;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player1 = AccountStatus::user;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player1 = AccountStatus::mod;
    REQUIRE_FALSE(valid_player_combination(player1, player2));
}

TEST_CASE("Trolls can only play with other trolls", "[task_4]") {
    // First player is a troll
    AccountStatus player1{AccountStatus::troll};

    AccountStatus player2{AccountStatus::guest};
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player2 = AccountStatus::troll;
    REQUIRE(valid_player_combination(player1, player2));

    player2 = AccountStatus::user;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player2 = AccountStatus::mod;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    // Second player is a troll
    player2 = AccountStatus::troll;

    player1 = AccountStatus::guest;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player1 = AccountStatus::user;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player1 = AccountStatus::mod;
    REQUIRE_FALSE(valid_player_combination(player1, player2));
}

TEST_CASE("Users can only play with users or mods", "[task_4]") {
    // First player is a user
    AccountStatus player1{AccountStatus::user};

    AccountStatus player2{AccountStatus::guest};
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player2 = AccountStatus::troll;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player2 = AccountStatus::user;
    REQUIRE(valid_player_combination(player1, player2));

    player2 = AccountStatus::mod;
    REQUIRE(valid_player_combination(player1, player2));

    // Second player is a user
    player2 = AccountStatus::user;

    player1 = AccountStatus::guest;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player1 = AccountStatus::troll;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player1 = AccountStatus::mod;
    REQUIRE(valid_player_combination(player1, player2));
}

TEST_CASE("Moderators can only play with users or mods", "[task_4]") {
    // First player is a mod
    AccountStatus player1{AccountStatus::mod};

    AccountStatus player2{AccountStatus::guest};
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player2 = AccountStatus::troll;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player2 = AccountStatus::user;
    REQUIRE(valid_player_combination(player1, player2));

    player2 = AccountStatus::mod;
    REQUIRE(valid_player_combination(player1, player2));

    // Second player is a mod
    player2 = AccountStatus::mod;

    player1 = AccountStatus::guest;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player1 = AccountStatus::troll;
    REQUIRE_FALSE(valid_player_combination(player1, player2));

    player1 = AccountStatus::user;
    REQUIRE(valid_player_combination(player1, player2));
}

TEST_CASE("Trolls have lowest priority", "[task_5]") {
    // First player is a troll
    AccountStatus player1{AccountStatus::troll};

    AccountStatus player2{AccountStatus::guest};
    REQUIRE_FALSE(has_priority(player1, player2));

    player2 = AccountStatus::troll;
    REQUIRE_FALSE(has_priority(player1, player2));

    player2 = AccountStatus::user;
    REQUIRE_FALSE(has_priority(player1, player2));

    player2 = AccountStatus::mod;
    REQUIRE_FALSE(has_priority(player1, player2));

    // Second player is a troll
    player2 = AccountStatus::troll;

    player1 = AccountStatus::guest;
    REQUIRE(has_priority(player1, player2));

    player1 = AccountStatus::user;
    REQUIRE(has_priority(player1, player2));

    player1 = AccountStatus::mod;
    REQUIRE(has_priority(player1, player2));
}

TEST_CASE("Guests have second lowest priority", "[task_5]") {
    // First player is a guest
    AccountStatus player1{AccountStatus::guest};

    AccountStatus player2{AccountStatus::guest};
    REQUIRE_FALSE(has_priority(player1, player2));

    player2 = AccountStatus::troll;
    REQUIRE(has_priority(player1, player2));

    player2 = AccountStatus::user;
    REQUIRE_FALSE(has_priority(player1, player2));

    player2 = AccountStatus::mod;
    REQUIRE_FALSE(has_priority(player1, player2));

    // Second player is a guest
    player2 = AccountStatus::guest;

    player1 = AccountStatus::troll;
    REQUIRE_FALSE(has_priority(player1, player2));

    player1 = AccountStatus::user;
    REQUIRE(has_priority(player1, player2));

    player1 = AccountStatus::mod;
    REQUIRE(has_priority(player1, player2));
}

TEST_CASE("Users have second highest priority", "[task_5]") {
    // First player is a user
    AccountStatus player1{AccountStatus::user};

    AccountStatus player2{AccountStatus::guest};
    REQUIRE(has_priority(player1, player2));

    player2 = AccountStatus::troll;
    REQUIRE(has_priority(player1, player2));

    player2 = AccountStatus::user;
    REQUIRE_FALSE(has_priority(player1, player2));

    player2 = AccountStatus::mod;
    REQUIRE_FALSE(has_priority(player1, player2));

    // Second player is a user
    player2 = AccountStatus::user;

    player1 = AccountStatus::troll;
    REQUIRE_FALSE(has_priority(player1, player2));

    player1 = AccountStatus::guest;
    REQUIRE_FALSE(has_priority(player1, player2));

    player1 = AccountStatus::mod;
    REQUIRE(has_priority(player1, player2));
}

TEST_CASE("Moderators have highest priority", "[task_5]") {
    // First player is a mod
    AccountStatus player1{AccountStatus::mod};

    AccountStatus player2{AccountStatus::guest};
    REQUIRE(has_priority(player1, player2));

    player2 = AccountStatus::troll;
    REQUIRE(has_priority(player1, player2));

    player2 = AccountStatus::user;
    REQUIRE(has_priority(player1, player2));

    player2 = AccountStatus::mod;
    REQUIRE_FALSE(has_priority(player1, player2));

    // Second player is a mod
    player2 = AccountStatus::mod;

    player1 = AccountStatus::troll;
    REQUIRE_FALSE(has_priority(player1, player2));

    player1 = AccountStatus::guest;
    REQUIRE_FALSE(has_priority(player1, player2));

    player1 = AccountStatus::user;
    REQUIRE_FALSE(has_priority(player1, player2));
}

#endif
