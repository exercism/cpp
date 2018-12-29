#include "crypto_square.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(normalize_capitals)
{
    BOOST_REQUIRE_EQUAL("hello", crypto_square::cipher("Hello").normalize_plain_text());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(normalize_spaces)
{
    BOOST_REQUIRE_EQUAL("hithere", crypto_square::cipher("Hi there").normalize_plain_text());
}

BOOST_AUTO_TEST_CASE(normalize_numbers)
{
    BOOST_REQUIRE_EQUAL("123go", crypto_square::cipher("1, 2, 3 GO!").normalize_plain_text());
}

BOOST_AUTO_TEST_CASE(plain_text_empty)
{
    const std::vector<std::string> expected{};

    const auto actual = crypto_square::cipher("").plain_text_segments();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(plain_text_4_characters)
{
    const std::vector<std::string> expected{"ab", "cd"};

    const auto actual = crypto_square::cipher("Ab Cd").plain_text_segments();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(plain_text_9_characters)
{
    const std::vector<std::string> expected{"thi", "sis", "fun"};

    const auto actual = crypto_square::cipher("This is fun!").plain_text_segments();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(plain_text_segments_from_phrase)
{
    const std::vector<std::string> expected{"ifmanwas", "meanttos", "tayonthe", "groundgo", "dwouldha", "vegivenu", "sroots"};

    const auto actual = crypto_square::cipher("If man was meant to stay on the ground, god would have given us roots.").plain_text_segments();

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), actual.begin(), actual.end());
}

BOOST_AUTO_TEST_CASE(cipher_text_empty_phrase)
{
    BOOST_REQUIRE_EQUAL("",
        crypto_square::cipher("").cipher_text());
}

BOOST_AUTO_TEST_CASE(cipher_text_long_phrase)
{
    BOOST_REQUIRE_EQUAL("imtgdvsfearwermayoogoanouuiontnnlvtwttddesaohghnsseoau",
        crypto_square::cipher("If man was meant to stay on the ground, god would have given us roots.").cipher_text());
}

BOOST_AUTO_TEST_CASE(normalized_cipher_text_empty)
{
    BOOST_REQUIRE_EQUAL("",
        crypto_square::cipher("").normalized_cipher_text());
}

BOOST_AUTO_TEST_CASE(normalized_cipher_text_fun)
{
    BOOST_REQUIRE_EQUAL("tsf hiu isn",
        crypto_square::cipher("This is fun!").normalized_cipher_text());
}

BOOST_AUTO_TEST_CASE(normalized_cipher_text_long_phrase)
{
    BOOST_REQUIRE_EQUAL("imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn  sseoau ",
        crypto_square::cipher("If man was meant to stay on the ground, god would have given us roots.").normalized_cipher_text());
}
#endif
