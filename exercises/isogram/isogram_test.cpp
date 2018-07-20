#include "isogram.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(empty_string)
{
	BOOST_REQUIRE(isogram::is_isogram(""));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(only_lower_case)
{
	BOOST_REQUIRE(isogram::is_isogram("isogram"));
}

BOOST_AUTO_TEST_CASE(one_duplicated_character)
{
	BOOST_REQUIRE(!isogram::is_isogram("eleven"));
}

BOOST_AUTO_TEST_CASE(longest_reported_isogram)
{
	BOOST_REQUIRE(isogram::is_isogram("subdermatoglyphic"));
}

BOOST_AUTO_TEST_CASE(mixed_case_non_isogram)
{
	BOOST_REQUIRE(!isogram::is_isogram("Alphabet"));
}

BOOST_AUTO_TEST_CASE(isogram_with_hyphin)
{
	BOOST_REQUIRE(isogram::is_isogram("thumbscrew-japingly"));
}

BOOST_AUTO_TEST_CASE(isogram_with_duplicate_hyphin)
{
	BOOST_REQUIRE(isogram::is_isogram("six-year-old"));
}

BOOST_AUTO_TEST_CASE(fake_name_isogram)
{
	BOOST_REQUIRE(isogram::is_isogram("Emily Jung Schwartzkopf"));
}

BOOST_AUTO_TEST_CASE(duplicate_in_middle)
{
	BOOST_REQUIRE(!isogram::is_isogram("accentor"));
}
#endif
