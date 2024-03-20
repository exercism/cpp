#include "crypto_square.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("empty plaintext results in an empty ciphertext",
          "[407c3837-9aa7-4111-ab63-ec54b58e8e9f]") {
    REQUIRE("" == crypto_square::cipher("").normalized_cipher_text());
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("normalization results in empty plaintext",
          "[aad04a25-b8bb-4304-888b-581bea8e0040]") {
    REQUIRE("" ==
            crypto_square::cipher("... --- ...").normalized_cipher_text());
}

TEST_CASE("Lowercase", "[64131d65-6fd9-4f58-bdd8-4a2370fb481d]") {
    REQUIRE("a" == crypto_square::cipher("A").normalized_cipher_text());
}

TEST_CASE("Remove spaces", "[63a4b0ed-1e3c-41ea-a999-f6f26ba447d6]") {
    REQUIRE("b" == crypto_square::cipher("  b ").normalized_cipher_text());
}

TEST_CASE("Remove punctuation", "[1b5348a1-7893-44c1-8197-42d48d18756c]") {
    REQUIRE("1" == crypto_square::cipher("@1,%!").normalized_cipher_text());
}

TEST_CASE("9 character plaintext results in 3 chunks of 3 characters",
          "[8574a1d3-4a08-4cec-a7c7-de93a164f41a]") {
    REQUIRE("tsf hiu isn" ==
            crypto_square::cipher("This is fun!").normalized_cipher_text());
}

TEST_CASE(
    // clang-format off
    "8 character plaintext results in 3 chunks, the last one with a trailing space",
    // clang-format on
    "[a65d3fa1-9e09-43f9-bcec-7a672aec3eae]") {
    REQUIRE("clu hlt io " ==
            crypto_square::cipher("Chill out.").normalized_cipher_text());
}

TEST_CASE(
    // clang-format off
    "54 character plaintext results in 7 chunks, the last two with trailing spaces",
    // clang-format on
    "[fbcb0c6d-4c39-4a31-83f6-c473baa6af80]") {
    REQUIRE("imtgdvs fearwer mayoogo anouuio ntnnlvt wttddes aohghn  sseoau " ==
            crypto_square::cipher("If man was meant to stay on the ground, god "
                                  "would have given us roots.")
                .normalized_cipher_text());
}
#endif
