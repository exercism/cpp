#include "hello_world.h"
#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

TEST_CASE("test_hello")
{
    REQUIRE("Hello, World!" == hello_world::hello());
}
