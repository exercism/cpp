#include "levenshtein_distance.h"
#include "test/catch.hpp"

using namespace std;

TEST_CASE("time_to_mine")
{
    REQUIRE(2 == levenshtein::distance("time", "mine"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("_to_abcd")
{
	REQUIRE(4 == levenshtein::distance("", "abcd"));
}

TEST_CASE("12345_to_")
{
	REQUIRE(5 == levenshtein::distance("12345", ""));
}

TEST_CASE("lifo_to_fifo")
{
	REQUIRE(1 == levenshtein::distance("lifo", "fifo"));
}

TEST_CASE("Hello-World!_to_hello-world")
{
	REQUIRE(3 == levenshtein::distance("Hello World!", "hello world"));
}

TEST_CASE("oxygenO2_to_carbondioxideCO2")
{
	REQUIRE(11 == levenshtein::distance("oxygenO2", "carbondioxideCO2"));
}

#endif