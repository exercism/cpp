#include "reverse_string.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


/*
If property based testing tools are available, a good property to test is reversing a string twice: reverse(reverse(string)) == string
*/

TEST_CASE("an empty string", "[c3b7d806-dced-49ee-8543-933fd1719b1c]") {
	REQUIRE("" == reverse_string::reverse_string(""));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("a word", "[01ebf55b-bebb-414e-9dec-06f7bb0bee3c]") {
	REQUIRE("tobor" == reverse_string::reverse_string("robot"));
}

TEST_CASE("a capitalized word", "[0f7c07e4-efd1-4aaa-a07a-90b49ce0b746]") {
	REQUIRE("nemaR" == reverse_string::reverse_string("Ramen"));
}

TEST_CASE("a sentence with punctuation", "[71854b9c-f200-4469-9f5c-1e8e5eff5614]") {
	REQUIRE("!yrgnuh m'I" == reverse_string::reverse_string("I'm hungry!"));
}

TEST_CASE("a palindrome", "[1f8ed2f3-56f3-459b-8f3e-6d8d654a1f6c]") {
	REQUIRE("racecar" == reverse_string::reverse_string("racecar"));
}

TEST_CASE("an even-sized word", "[b9e7dec1-c6df-40bd-9fa3-cd7ded010c4c]") {
	REQUIRE("reward" == reverse_string::reverse_string("drawer"));
}

TEST_CASE("wide characters", "[1bed0f8a-13b0-4bd3-9d59-3d0593326fa2]") {
	REQUIRE("猫子" == reverse_string::reverse_string("子猫"));
}

TEST_CASE("grapheme cluster with pre-combined form", "[93d7e1b8-f60f-4f3c-9559-4056e10d2ead]") {
	REQUIRE("dnatsnehctsrüW" == reverse_string::reverse_string("Würstchenstand"));
}

TEST_CASE("grapheme clusters", "[1028b2c1-6763-4459-8540-2da47ca512d9]") {
	REQUIRE("มรกแรปโนยขีเผู้" == reverse_string::reverse_string("ผู้เขียนโปรแกรม"));
}

#endif
