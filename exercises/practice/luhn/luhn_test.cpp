#include "luhn.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


TEST_CASE("single digit strings can not be valid", "[792a7082-feb7-48c7-b88b-bbfec160865e]") {
	REQUIRE(false == luhn::valid("1"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("a single zero is invalid", "[698a7924-64d4-4d89-8daa-32e1aadc271e]") {
	REQUIRE(false == luhn::valid("0"));
}

TEST_CASE("a simple valid SIN that remains valid if reversed", "[73c2f62b-9b10-4c9f-9a04-83cee7367965]") {
	REQUIRE(true == luhn::valid("059"));
}

TEST_CASE("a simple valid SIN that becomes invalid if reversed", "[9369092e-b095-439f-948d-498bd076be11]") {
	REQUIRE(true == luhn::valid("59"));
}

TEST_CASE("a valid Canadian SIN", "[8f9f2350-1faf-4008-ba84-85cbb93ffeca]") {
	REQUIRE(true == luhn::valid("055 444 285"));
}

TEST_CASE("invalid Canadian SIN", "[1cdcf269-6560-44fc-91f6-5819a7548737]") {
	REQUIRE(false == luhn::valid("055 444 286"));
}

TEST_CASE("invalid credit card", "[656c48c1-34e8-4e60-9a5a-aad8a367810a]") {
	REQUIRE(false == luhn::valid("8273 1232 7352 0569"));
}

TEST_CASE("invalid long number with an even remainder", "[20e67fad-2121-43ed-99a8-14b5b856adb9]") {
	REQUIRE(false == luhn::valid("1 2345 6789 1234 5678 9012"));
}

TEST_CASE("invalid long number with a remainder divisible by 5", "[7e7c9fc1-d994-457c-811e-d390d52fba5e]") {
	REQUIRE(false == luhn::valid("1 2345 6789 1234 5678 9013"));
}

TEST_CASE("valid number with an even number of digits", "[ad2a0c5f-84ed-4e5b-95da-6011d6f4f0aa]") {
	REQUIRE(true == luhn::valid("095 245 88"));
}

TEST_CASE("valid number with an odd number of spaces", "[ef081c06-a41f-4761-8492-385e13c8202d]") {
	REQUIRE(true == luhn::valid("234 567 891 234"));
}

TEST_CASE("valid strings with a non-digit added at the end become invalid", "[bef66f64-6100-4cbb-8f94-4c9713c5e5b2]") {
	REQUIRE(false == luhn::valid("059a"));
}

TEST_CASE("valid strings with punctuation included become invalid", "[2177e225-9ce7-40f6-b55d-fa420e62938e]") {
	REQUIRE(false == luhn::valid("055-444-285"));
}

TEST_CASE("valid strings with symbols included become invalid", "[ebf04f27-9698-45e1-9afe-7e0851d0fe8d]") {
	REQUIRE(false == luhn::valid("055# 444$ 285"));
}

TEST_CASE("single zero with space is invalid", "[08195c5e-ce7f-422c-a5eb-3e45fece68ba]") {
	REQUIRE(false == luhn::valid(" 0"));
}

TEST_CASE("more than a single zero is valid", "[12e63a3c-f866-4a79-8c14-b359fc386091]") {
	REQUIRE(true == luhn::valid("0000 0"));
}

TEST_CASE("input digit 9 is correctly converted to output digit 9", "[ab56fa80-5de8-4735-8a4a-14dae588663e]") {
	REQUIRE(true == luhn::valid("091"));
}

TEST_CASE("very long input is valid", "[b9887ee8-8337-46c5-bc45-3bcab51bc36f]") {
	REQUIRE(true == luhn::valid("9999999999 9999999999 9999999999 9999999999"));
}

TEST_CASE("valid luhn with an odd number of digits and non zero first digit", "[8a7c0e24-85ea-4154-9cf1-c2db90eabc08]") {
	REQUIRE(true == luhn::valid("109"));
}

TEST_CASE("using ascii value for non-doubled non-digit isn't allowed", "[39a06a5a-5bad-4e0f-b215-b042d46209b1]") {
	REQUIRE(false == luhn::valid("055b 444 285"));
}

TEST_CASE("using ascii value for doubled non-digit isn't allowed", "[f94cf191-a62f-4868-bc72-7253114aa157]") {
	REQUIRE(false == luhn::valid(":9"));
}

TEST_CASE("non-numeric, non-space char in the middle with a sum that's divisible by 10 isn't allowed", "[8b72ad26-c8be-49a2-b99c-bcc3bf631b33]") {
	REQUIRE(false == luhn::valid("59%59"));
}

#endif
