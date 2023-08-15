#include "ellens_alien_game.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

using namespace targets;

TEST_CASE("Alien has correct initial coordinates", "[task_1]") {
    Alien alien{2, -1};
    REQUIRE(alien.x_coordinate == 2);
    REQUIRE(alien.y_coordinate == -1);
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Alien has correct initial health", "[task_1]") {
    Alien alien{22, 0};
    REQUIRE(alien.get_health() == 3);
}

TEST_CASE("New alien does not share old aliens position", "[task_1]") {
    Alien alien1{22, 0};
    Alien alien2{0, 22};
    REQUIRE(alien1.x_coordinate != alien2.x_coordinate);
    REQUIRE(alien1.y_coordinate != alien2.y_coordinate);
}

TEST_CASE("Alien is always hit", "[task_1]") {
    Alien alien{6, 7};
    REQUIRE(alien.hit());
}

TEST_CASE("Alien is alive while health is greater than 0 and stays dead afterwards", "[task_3]") {
    Alien alien{2, 54};
    REQUIRE(alien.is_alive());
    alien.hit();
    REQUIRE(alien.is_alive());
    alien.hit();
    REQUIRE(alien.is_alive());
    alien.hit();
    REQUIRE(!alien.is_alive());
    alien.hit();
    REQUIRE(!alien.is_alive());
}

TEST_CASE("Alien Teleports reports succesful", "[task_4]") {
    Alien alien{22, 1};
    REQUIRE(alien.teleport(99, 8));
}

TEST_CASE("Alien Teleports where it should", "[task_4]") {
    Alien alien{2, -54};
    REQUIRE(alien.x_coordinate == 2);
    REQUIRE(alien.y_coordinate == -54);
    alien.teleport(99, 8);
    REQUIRE(alien.x_coordinate == 99);
    REQUIRE(alien.y_coordinate == 8);
}

TEST_CASE("Alien collision detection with other aliens", "[task_5]") {
    Alien alien1{22, 0};
    Alien alien2{0, 22};
    Alien alien3{22, 0};
    REQUIRE_FALSE(alien1.collision_detection(alien2));
    REQUIRE(alien1.collision_detection(alien3));
}

#endif
