#include "food_chain.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(fly)
{
    string expected = "I know an old lady who swallowed a fly.\n"
        "I don't know why she swallowed the fly. Perhaps she'll die.\n";

    BOOST_REQUIRE_EQUAL(expected, food_chain::verse(1));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(spider)
{
    string expected = "I know an old lady who swallowed a spider.\n"
        "It wriggled and jiggled and tickled inside her.\n"
        "She swallowed the spider to catch the fly.\n"
        "I don't know why she swallowed the fly. Perhaps she'll die.\n";

    BOOST_REQUIRE_EQUAL(expected, food_chain::verse(2));
}

BOOST_AUTO_TEST_CASE(bird)
{
    string expected = "I know an old lady who swallowed a bird.\n"
        "How absurd to swallow a bird!\n"
        "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n"
        "She swallowed the spider to catch the fly.\n"
        "I don't know why she swallowed the fly. Perhaps she'll die.\n";

    BOOST_REQUIRE_EQUAL(expected, food_chain::verse(3));
}

BOOST_AUTO_TEST_CASE(cat)
{
    string expected = "I know an old lady who swallowed a cat.\n"
        "Imagine that, to swallow a cat!\n"
        "She swallowed the cat to catch the bird.\n"
        "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n"
        "She swallowed the spider to catch the fly.\n"
        "I don't know why she swallowed the fly. "
        "Perhaps she'll die.\n";

    BOOST_REQUIRE_EQUAL(expected, food_chain::verse(4));
}

BOOST_AUTO_TEST_CASE(dog)
{
    string expected = "I know an old lady who swallowed a dog.\n"
        "What a hog, to swallow a dog!\n"
        "She swallowed the dog to catch the cat.\n"
        "She swallowed the cat to catch the bird.\n"
        "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n"
        "She swallowed the spider to catch the fly.\n"
        "I don't know why she swallowed the fly. "
        "Perhaps she'll die.\n";

    BOOST_REQUIRE_EQUAL(expected, food_chain::verse(5));
}

BOOST_AUTO_TEST_CASE(goat)
{
    string expected = "I know an old lady who swallowed a goat.\n"
        "Just opened her throat and swallowed a goat!\n"
        "She swallowed the goat to catch the dog.\n"
        "She swallowed the dog to catch the cat.\n"
        "She swallowed the cat to catch the bird.\n"
        "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n"
        "She swallowed the spider to catch the fly.\n"
        "I don't know why she swallowed the fly. "
        "Perhaps she'll die.\n";

    BOOST_REQUIRE_EQUAL(expected, food_chain::verse(6));
}

BOOST_AUTO_TEST_CASE(cow)
{
    string expected = "I know an old lady who swallowed a cow.\n"
        "I don't know how she swallowed a cow!\n"
        "She swallowed the cow to catch the goat.\n"
        "She swallowed the goat to catch the dog.\n"
        "She swallowed the dog to catch the cat.\n"
        "She swallowed the cat to catch the bird.\n"
        "She swallowed the bird to catch the spider that wriggled and jiggled and tickled inside her.\n"
        "She swallowed the spider to catch the fly.\n"
        "I don't know why she swallowed the fly. "
        "Perhaps she'll die.\n";

    BOOST_REQUIRE_EQUAL(expected, food_chain::verse(7));
}

BOOST_AUTO_TEST_CASE(horse)
{
    string expected = "I know an old lady who swallowed a horse.\n"
        "She's dead, of course!\n";

    BOOST_REQUIRE_EQUAL(expected, food_chain::verse(8));
}

BOOST_AUTO_TEST_CASE(multiple_verses)
{
    string expected = 
        "I know an old lady who swallowed a fly.\n"
        "I don't know why she swallowed the fly. Perhaps she'll die.\n"
        "\n"
        "I know an old lady who swallowed a spider.\n"
        "It wriggled and jiggled and tickled inside her.\n"
        "She swallowed the spider to catch the fly.\n"
        "I don't know why she swallowed the fly. Perhaps she'll die.\n"
        "\n";

    BOOST_REQUIRE_EQUAL(expected, food_chain::verses(1, 2));
}

BOOST_AUTO_TEST_CASE(the_whole_song)
{
    BOOST_REQUIRE_EQUAL(food_chain::verses(1, 8), food_chain::sing());
}
#endif
