#include "hello_world.h"
#include "test/catch.hpp"

TEST_CASE("test_hello")
{
    REQUIRE("Hello, World!" == hello_world::hello());
}
