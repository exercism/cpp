#include "crypto_square.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("normalize_capitals")
{
    REQUIRE("hello" == crypto_square::cipher("Hello").normalize_plain_text());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("normalize_spaces")
{
    REQUIRE("hithere" == crypto_square::cipher("Hi there").normalize_plain_text());
}

TEST_CASE("normalize_numbers")
{
    REQUIRE("123go" == crypto_square::cipher("1, 2, 3 GO!").normalize_plain_text());
}

TEST_CASE("plain_text_empty")
{
    const std::vector<std::string> expected{};

    const auto actual = crypto_square::cipher("").plain_text_segments();

    REQUIRE(expected == actual);
}

TEST_CASE("plain_text_4_characters")
{
    const std::vector<std::string> expected{"ab", "cd"};

    const auto actual = crypto_square::cipher("Ab Cd").plain_text_segments();

    REQUIRE(expected == actual);
}

TEST_CASE("plain_text_9_characters")
{
    const std::vector<std::string> expected{"thi", "sis", "fun"};

    const auto actual = crypto_square::cipher("This is fun!").plain_text_segments();

    REQUIRE(expected == actual);
}

TEST_CASE("plain_text_segments_from_phrase")
{
    const std::vector<std::string> expected{"ifmanwas", "meanttos", "tayonthe", "groundgo", "dwouldha", "vegivenu", "sroots"};

    const auto actual = crypto_square::cipher("If man was meant to stay on the ground, god would have given us roots.").plain_text_segments();

    REQUIRE(expected == actual);
}

TEST_CASE("cipher_text_empty_phrase")
{
    REQUIRE("" == crypto_square::cipher("").cipher_text());
}

TEST_CASE("cipher_text_long_phrase")
{
    REQUIRE("imtgdvsfearwermayoogoanouuiontnnlvtwttddesaohghnsseoau" ==
        crypto_square::cipher("If man was meant to stay on the ground, god would have given us roots.").cipher_text());
}

TEST_CASE("normalized_cipher_text_empty")
{
    REQUIRE("" == crypto_square::cipher("").normalized_cipher_text());
}

TEST_CASE("normalized_cipher_text_fun")
{
    REQUIRE("tsf hiu isn" == crypto_square::cipher("This is fun!").normalized_cipher_text());
}

TEST_CASE("normalized_cipher_text_long_phrase")
{
    REQUIRE("imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn  sseoau " ==
        crypto_square::cipher("If man was meant to stay on the ground, god would have given us roots.").normalized_cipher_text());
}
#endif
