#include "crypto_square.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(normalize_strange_characters)
{
    BOOST_REQUIRE_EQUAL("splunk", crypto_square::cipher("s#$%^&plunk").normalize_plain_text());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(normalize_numbers)
{
    BOOST_REQUIRE_EQUAL("123go", crypto_square::cipher("1, 2, 3 GO!").normalize_plain_text());
}

BOOST_AUTO_TEST_CASE(size_of_small_square)
{
    BOOST_REQUIRE_EQUAL(2U, crypto_square::cipher("1234").size());
}

BOOST_AUTO_TEST_CASE(size_of_slightly_larger_square)
{
    BOOST_REQUIRE_EQUAL(3U, crypto_square::cipher("123456789").size());
}

BOOST_AUTO_TEST_CASE(size_of_non_perfect_square)
{
    BOOST_REQUIRE_EQUAL(4U, crypto_square::cipher("123456789abc").size());
}

BOOST_AUTO_TEST_CASE(plain_text_segments_from_phrase)
{
    const std::vector<std::string> expected{"neverv", "exthin", "eheart", "withid", "lewoes"};

    const auto actual = crypto_square::cipher("Never vex thine heart with idle woes").plain_text_segments();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(plain_text_segments_from_complex_phrase)
{
    const std::vector<std::string> expected{"zomg", "zomb", "ies"};

    const auto actual = crypto_square::cipher("ZOMG! ZOMBIES!!!").plain_text_segments();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(cipher_text_short_phrase)
{
    BOOST_REQUIRE_EQUAL("tasneyinicdsmiohooelntuillibsuuml",
        crypto_square::cipher("Time is an illusion. Lunchtime doubly so.").cipher_text());
}

BOOST_AUTO_TEST_CASE(cipher_text_long_phrase)
{
    BOOST_REQUIRE_EQUAL("wneiaweoreneawssciliprerlneoidktcms",
        crypto_square::cipher("We all know interspecies romance is weird.").cipher_text());
}

BOOST_AUTO_TEST_CASE(normalized_cipher_text1)
{
    BOOST_REQUIRE_EQUAL("msemoa anindn inndla etltsh ui",
        crypto_square::cipher("Madness, and then illumination.").normalized_cipher_text());
}

BOOST_AUTO_TEST_CASE(normalized_cipher_text2)
{
    BOOST_REQUIRE_EQUAL("vrela epems etpao oirpo",
        crypto_square::cipher("Vampires are people too!").normalized_cipher_text());
}
#endif
