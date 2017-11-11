#include "acronym.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

using namespace std;

BOOST_AUTO_TEST_CASE(basic)
{
    const string actual = acronym::acronym("Portable Network Graphics");

    const string expected{"PNG"};

    BOOST_TEST(expected == actual);
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(lowercase_words)
{
    const string actual = acronym::acronym("Ruby on Rails");
    
    const string expected{"ROR"};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(punctuation)
{
    const string actual = acronym::acronym("First In, First Out");

    const string expected{"FIFO"};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(all_caps_words)
{
    const string actual = acronym::acronym("PHP: Hypertext Preprocessor");

    const string expected{"PHP"};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(non_acronym_all_caps_word)
{
    const string actual = acronym::acronym("GNU Image Manipulation Program");

    const string expected{"GIMP"};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(hyphenated)
{
    const string actual = acronym::acronym("Complementary metal-oxide semiconductor");

    const string expected{"CMOS"};

    BOOST_TEST(expected == actual);
}

#endif
