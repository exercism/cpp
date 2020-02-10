// Include the header file with the definitions of the functions you create.
#include "hello_world.h"

// Include the test framework.
#include "test/catch.hpp"

// Declares a single test.
TEST_CASE("test_hello")
{
    // Check if your function returns "Hello, World!".
    REQUIRE(hello_world::hello() == "Hello, World!");
}
