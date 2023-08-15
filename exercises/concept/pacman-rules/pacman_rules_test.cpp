#include "pacman_rules.cpp"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


TEST_CASE( "ghost gets eaten", "[task_1]") {
  REQUIRE( can_eat_ghost(true, true));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE( "ghost does not get eaten because no power pellet active", "[task_1]") {
  REQUIRE_FALSE( can_eat_ghost(false, true));
}

TEST_CASE( "ghost does not get eaten because not touching ghost", "[task_1]") {
  REQUIRE_FALSE( can_eat_ghost(true, false));
}

TEST_CASE( "ghost does not get eaten because no power pellet is active, even if not touching ghost", "[task_1]") {
  REQUIRE_FALSE( can_eat_ghost(false, false));
}
    
TEST_CASE("score when eating dot", "[task_2]") {
  REQUIRE( scored(false, true));
}

TEST_CASE("score when eating power pellet", "[task_2]") {
  REQUIRE( scored(true, false));
}

TEST_CASE("no score when nothing eaten", "[task_2]") {
  REQUIRE_FALSE( scored(false, false));
}
    
TEST_CASE("lose if touching a ghost without a power pellet active", "[task_3]") {
  REQUIRE( lost(false, true));
}

TEST_CASE("don't lose if touching a ghost with a power pellet active", "[task_3]") {
  REQUIRE_FALSE( lost(true, true));
}

TEST_CASE("don't lose if not touching a ghost", "[task_3]") {
  REQUIRE_FALSE( lost(true, false));
}

TEST_CASE( "win if all dots eaten", "[task_4]") {
      REQUIRE( won(true, false, false));
}

TEST_CASE( "don't win if all dots eaten, but touching a ghost", "[task_4]") {
      REQUIRE_FALSE( won(true, false, true));
}

TEST_CASE( "win if all dots eaten and touching a ghost with a power pellet active", "[task_4]") {
      REQUIRE( won(true, true, true));
}

#endif
