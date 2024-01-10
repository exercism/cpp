#include "rotational_cipher.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

/*
The tests are a series of rotation tests: 
*/

TEST_CASE("rotate a by 0, same output as input", "[74e58a38-e484-43f1-9466-877a7515e10f]") {
	REQUIRE(rotational_cipher::rotate("a", 0) == "a");
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("rotate a by 1", "[7ee352c6-e6b0-4930-b903-d09943ecb8f5]") {
	REQUIRE(rotational_cipher::rotate("a", 1) == "b");
}

TEST_CASE("rotate a by 26, same output as input", "[edf0a733-4231-4594-a5ee-46a4009ad764]") {
	REQUIRE(rotational_cipher::rotate("a", 26) == "a");
}

TEST_CASE("rotate m by 13", "[e3e82cb9-2a5b-403f-9931-e43213879300]") {
	REQUIRE(rotational_cipher::rotate("m", 13) == "z");
}

TEST_CASE("rotate n by 13 with wrap around alphabet", "[19f9eb78-e2ad-4da4-8fe3-9291d47c1709]") {
	REQUIRE(rotational_cipher::rotate("n", 13) == "a");
}

TEST_CASE("rotate capital letters", "[a116aef4-225b-4da9-884f-e8023ca6408a]") {
	REQUIRE(rotational_cipher::rotate("OMG", 5) == "TRL");
}

TEST_CASE("rotate spaces", "[71b541bb-819c-4dc6-a9c3-132ef9bb737b]") {
	REQUIRE(rotational_cipher::rotate("O M G", 5) == "T R L");
}

TEST_CASE("rotate numbers", "[ef32601d-e9ef-4b29-b2b5-8971392282e6]") {
	REQUIRE(rotational_cipher::rotate("Testing 1 2 3 testing", 4) == "Xiwxmrk 1 2 3 xiwxmrk");
}

TEST_CASE("rotate punctuation", "[32dd74f6-db2b-41a6-b02c-82eb4f93e549]") {
	REQUIRE(rotational_cipher::rotate("Let's eat, Grandma!", 21) == "Gzo'n zvo, Bmviyhv!");
}

TEST_CASE("rotate all letters", "[9fb93fe6-42b0-46e6-9ec1-0bf0a062d8c9]") {
	REQUIRE(rotational_cipher::rotate("The quick brown fox jumps over the lazy dog.", 13) == "Gur dhvpx oebja sbk whzcf bire gur ynml qbt.");
}

#endif