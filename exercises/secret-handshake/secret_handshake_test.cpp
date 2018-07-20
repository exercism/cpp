#include "secret_handshake.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <vector>
#include <string>

BOOST_AUTO_TEST_CASE(wink_for_1)
{
	std::vector<std::string> your_val = handshake::commands(1);
	std::vector<std::string> expected_val{ "wink" };
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}
#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(double_blink_for_10)
{
	std::vector<std::string> your_val = handshake::commands(2);
	std::vector<std::string> expected_val{ "double blink" };
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}

BOOST_AUTO_TEST_CASE(close_your_eyes_for_100)
{
	std::vector<std::string> your_val = handshake::commands(4);
	std::vector<std::string> expected_val{ "close your eyes" };
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}

BOOST_AUTO_TEST_CASE(jump_for_1000)
{
	std::vector<std::string> your_val = handshake::commands(8);
	std::vector<std::string> expected_val{ "jump" };
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}

BOOST_AUTO_TEST_CASE(combine_two_actions)
{
	std::vector<std::string> your_val = handshake::commands(3);
	std::vector<std::string> expected_val{ "wink", "double blink" };
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}

BOOST_AUTO_TEST_CASE(reverse_two_actions)
{
	std::vector<std::string> your_val = handshake::commands(19);
	std::vector<std::string> expected_val{ "double blink", "wink" };
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}


BOOST_AUTO_TEST_CASE(reverse_one_action)
{
	std::vector<std::string> your_val = handshake::commands(24);
	std::vector<std::string> expected_val{ "jump" };
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}

BOOST_AUTO_TEST_CASE(reverse_no_action)
{
	std::vector<std::string> your_val = handshake::commands(16);
	std::vector<std::string> expected_val;
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}

BOOST_AUTO_TEST_CASE(all_possible_actions)
{
	std::vector<std::string> your_val = handshake::commands(15);
	std::vector<std::string> expected_val{ "wink", "double blink", "close your eyes", "jump" };
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}

BOOST_AUTO_TEST_CASE(reverse_all_possible_actions)
{
	std::vector<std::string> your_val = handshake::commands(31);
	std::vector<std::string> expected_val{ "jump", "close your eyes", "double blink", "wink" };
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}

BOOST_AUTO_TEST_CASE(do_nothing_for_zero)
{
	std::vector<std::string> your_val = handshake::commands(0);
	std::vector<std::string> expected_val;
	BOOST_REQUIRE_EQUAL_COLLECTIONS(your_val.begin(), your_val.end(), expected_val.begin(), expected_val.end());
}
#endif