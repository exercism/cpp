#include "acronym.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(basic)
{
    const string expected{"PNG"};

    const string actual = acronym::acronym("Portable Network Graphics");

    BOOST_TEST(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(lowercase_words)
{
    const string expected{"ROR"};

    const string actual = acronym::acronym("Ruby on Rails");

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(punctuation)
{
    const string expected{"FIFO"};

    const string actual = acronym::acronym("First In, First Out");

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(all_caps_words)
{
    const string expected{"PHP"};

    const string actual = acronym::acronym("PHP: Hypertext Preprocessor");

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(non_acronym_all_caps_word)
{
    const string expected{"GIMP"};

    const string actual = acronym::acronym("GNU Image Manipulation Program");

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(hyphenated)
{
    const string expected{"CMOS"};

    const string actual = acronym::acronym("Complementary metal-oxide semiconductor");

    BOOST_TEST(expected == actual);
}
#endif
