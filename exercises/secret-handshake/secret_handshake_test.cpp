#include "test/catch.hpp"
#include "secret_handshake.h"
#include <vector>
#include <string>

using namespace std;

// Secret-handshake exercise test case data version 1.2.1

TEST_CASE("wink_for_1")
{
    REQUIRE(vector<string>{"wink"} == secret_handshake::commands(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("double_blink_for_10")
{
    REQUIRE(vector<string>{"double blink"} == secret_handshake::commands(2));
}

TEST_CASE("close_your_eyes_for_100")
{
    REQUIRE(vector<string>{"close your eyes"} == secret_handshake::commands(4));
}

TEST_CASE("jump_for_1000")
{
    REQUIRE(vector<string>{"jump"} == secret_handshake::commands(8));
}

TEST_CASE("combine_two_actions")
{
    REQUIRE(vector<string>{"wink", "double blink"} == secret_handshake::commands(3));
}

TEST_CASE("reverse_two_actions")
{
    REQUIRE(vector<string>{"double blink", "wink"} == secret_handshake::commands(19));
}

TEST_CASE("reversing_one_action_gives_the_same_action")
{
    REQUIRE(vector<string>{"jump"} == secret_handshake::commands(24));
}

TEST_CASE("reversing_no_actions_still_gives_no_actions")
{
    REQUIRE(vector<string>{} == secret_handshake::commands(16));
}

TEST_CASE("all_possible_actions")
{
    REQUIRE(vector<string>{"wink", "double blink", "close your eyes", "jump"}
                            == secret_handshake::commands(15));
}

TEST_CASE("reverse_all_possible_actions")
{
    REQUIRE(vector<string>{"jump", "close your eyes", "double blink", "wink"}
                            == secret_handshake::commands(31));
}

TEST_CASE("do_nothing_for_zero")
{
    REQUIRE(vector<string>{} == secret_handshake::commands(0));
}

#endif // !EXERCISM_RUN_ALL_TESTS
