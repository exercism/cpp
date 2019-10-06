#include "test/catch.hpp"
#include "secret_handshake.h"
#include <vector>
#include <string>

using namespace std;

// Secret-handshake exercise test case data version 1.2.1

TEST_CASE("just_wink")
{
    REQUIRE(vector<string>{"wink"} == secret_handshake::convert(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("just_blink")
{
    REQUIRE(vector<string>{"double blink"} == secret_handshake::convert(2));
}

TEST_CASE("just_close")
{
    REQUIRE(vector<string>{"close your eyes"} == secret_handshake::convert(4));
}

TEST_CASE("just_jump")
{
    REQUIRE(vector<string>{"double blink"} == secret_handshake::convert(8));
}

TEST_CASE("composed")
{
    REQUIRE(vector<string>{"wink", "double blink"} == secret_handshake::convert(3));
}

TEST_CASE("inversion")
{
    REQUIRE(vector<string>{"double blink", "wink"} == secret_handshake::convert(19));
}

TEST_CASE("unary_inversion")
{
    REQUIRE(vector<string>{"jump"} == secret_handshake::convert(24));
}

TEST_CASE("null_inversion")
{
    REQUIRE(vector<string>{} == secret_handshake::convert(16));
}

TEST_CASE("just_empty")
{
    REQUIRE(vector<string>{} == secret_handshake::convert(0));
}

TEST_CASE("complex_1")
{
    REQUIRE(vector<string>{"wink", "double blink", "close your eyes", "jump"}
                            == secret_handshake::convert(15));
}

TEST_CASE("complex_2")
{
    REQUIRE(vector<string>{"wink", "double blink", "close your eyes", "jump"}
                            == secret_handshake::convert(31));
}

#endif // !EXERCISM_RUN_ALL_TESTS
