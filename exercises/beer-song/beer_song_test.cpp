#include "beer_song.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(prints_an_arbitrary_verse)
{
    string expected = "8 bottles of beer on the wall, 8 bottles of beer.\n"
        "Take one down and pass it around, 7 bottles of beer on the wall.\n";

    BOOST_REQUIRE_EQUAL(expected, beer::verse(8));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(handles_1_bottle)
{
    string expected = "1 bottle of beer on the wall, 1 bottle of beer.\n"
        "Take it down and pass it around, no more bottles of beer on the wall.\n";

    BOOST_REQUIRE_EQUAL(expected, beer::verse(1));
}

BOOST_AUTO_TEST_CASE(handles_0_bottles)
{
    string expected = "No more bottles of beer on the wall, no more bottles of beer.\n"
        "Go to the store and buy some more, 99 bottles of beer on the wall.\n";

    BOOST_REQUIRE_EQUAL(expected, beer::verse(0));
}

BOOST_AUTO_TEST_CASE(sings_several_verses)
{
    string expected = "8 bottles of beer on the wall, 8 bottles of beer.\n"
        "Take one down and pass it around, 7 bottles of beer on the wall.\n"
        "\n"
        "7 bottles of beer on the wall, 7 bottles of beer.\n"
        "Take one down and pass it around, 6 bottles of beer on the wall.\n"
        "\n"
        "6 bottles of beer on the wall, 6 bottles of beer.\n"
        "Take one down and pass it around, 5 bottles of beer on the wall.\n";

    BOOST_REQUIRE_EQUAL(expected, beer::sing(8, 6));
}

BOOST_AUTO_TEST_CASE(sings_the_rest_of_the_verses)
{
    string expected = "3 bottles of beer on the wall, 3 bottles of beer.\n"
        "Take one down and pass it around, 2 bottles of beer on the wall.\n"
        "\n"
        "2 bottles of beer on the wall, 2 bottles of beer.\n"
        "Take one down and pass it around, 1 bottle of beer on the wall.\n"
        "\n"
        "1 bottle of beer on the wall, 1 bottle of beer.\n"
        "Take it down and pass it around, no more bottles of beer on the wall.\n"
        "\n"
        "No more bottles of beer on the wall, no more bottles of beer.\n"
        "Go to the store and buy some more, 99 bottles of beer on the wall.\n";

    BOOST_REQUIRE_EQUAL(expected, beer::sing(3));
}
#endif
