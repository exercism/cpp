#include "yacht.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


/*
The dice are represented always as a list of exactly five integers
with values between 1 and 6 inclusive. The category is a string.
the categories are 'ones' to 'sixes',
Then 'full house',
     'four of a kind'
     'little straight' 1-5
     'big straight' 2-6
     'choice', sometimes called Chance
     'yacht', or five of a kind
*/

TEST_CASE("Yacht", "[3060e4a5-4063-4deb-a380-a630b43a84b6]") {
	REQUIRE(50 == yacht::score({5, 5, 5, 5, 5}, "yacht"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("Not Yacht", "[15026df2-f567-482f-b4d5-5297d57769d9]") {
	REQUIRE(0 == yacht::score({1, 3, 3, 2, 5}, "yacht"));
}

TEST_CASE("Ones", "[36b6af0c-ca06-4666-97de-5d31213957a4]") {
	REQUIRE(3 == yacht::score({1, 1, 1, 3, 5}, "ones"));
}

TEST_CASE("Ones, out of order", "[023a07c8-6c6e-44d0-bc17-efc5e1b8205a]") {
	REQUIRE(3 == yacht::score({3, 1, 1, 5, 1}, "ones"));
}

TEST_CASE("No ones", "[7189afac-cccd-4a74-8182-1cb1f374e496]") {
	REQUIRE(0 == yacht::score({4, 3, 6, 5, 5}, "ones"));
}

TEST_CASE("Twos", "[793c4292-dd14-49c4-9707-6d9c56cee725]") {
	REQUIRE(2 == yacht::score({2, 3, 4, 5, 6}, "twos"));
}

TEST_CASE("Fours", "[dc41bceb-d0c5-4634-a734-c01b4233a0c6]") {
	REQUIRE(8 == yacht::score({1, 4, 1, 4, 1}, "fours"));
}

TEST_CASE("Yacht counted as threes", "[f6125417-5c8a-4bca-bc5b-b4b76d0d28c8]") {
	REQUIRE(15 == yacht::score({3, 3, 3, 3, 3}, "threes"));
}

TEST_CASE("Yacht of 3s counted as fives", "[464fc809-96ed-46e4-acb8-d44e302e9726]") {
	REQUIRE(0 == yacht::score({3, 3, 3, 3, 3}, "fives"));
}

TEST_CASE("Fives", "[d054227f-3a71-4565-a684-5c7e621ec1e9]") {
	REQUIRE(10 == yacht::score({1, 5, 3, 5, 3}, "fives"));
}

TEST_CASE("Sixes", "[e8a036e0-9d21-443a-8b5f-e15a9e19a761]") {
	REQUIRE(6 == yacht::score({2, 3, 4, 5, 6}, "sixes"));
}

TEST_CASE("Full house two small, three big", "[51cb26db-6b24-49af-a9ff-12f53b252eea]") {
	REQUIRE(16 == yacht::score({2, 2, 4, 4, 4}, "full house"));
}

TEST_CASE("Full house three small, two big", "[1822ca9d-f235-4447-b430-2e8cfc448f0c]") {
	REQUIRE(19 == yacht::score({5, 3, 3, 5, 3}, "full house"));
}

TEST_CASE("Two pair is not a full house", "[b208a3fc-db2e-4363-a936-9e9a71e69c07]") {
	REQUIRE(0 == yacht::score({2, 2, 4, 4, 5}, "full house"));
}

TEST_CASE("Four of a kind is not a full house", "[b90209c3-5956-445b-8a0b-0ac8b906b1c2]") {
	REQUIRE(0 == yacht::score({1, 4, 4, 4, 4}, "full house"));
}

TEST_CASE("Yacht is not a full house", "[32a3f4ee-9142-4edf-ba70-6c0f96eb4b0c]") {
	REQUIRE(0 == yacht::score({2, 2, 2, 2, 2}, "full house"));
}

TEST_CASE("Four of a Kind", "[b286084d-0568-4460-844a-ba79d71d79c6]") {
	REQUIRE(24 == yacht::score({6, 6, 4, 6, 6}, "four of a kind"));
}

TEST_CASE("Yacht can be scored{s Four of a Kind", "[f25c0c90-5397}732-9779-b1e9b5f612ca]") {
	REQUIRE(12 == yacht::score({3, 3, 3, 3, 3}, "four of a kind"));
}

TEST_CASE("Full house is not Four of a Kind", "[9f8ef4f0-72bb-401a-a871-cbad39c9cb08]") {
	REQUIRE(0 == yacht::score({3, 3, 3, 5, 5}, "four of a kind"));
}

TEST_CASE("Little Straight", "[b4743c82-1eb8-4a65-98f7-33ad126905cd]") {
	REQUIRE(30 == yacht::score({3, 5, 4, 1, 2}, "little straight"));
}

TEST_CASE("Little Straight as Big Straight", "[7ac08422-41bf-459c-8187-a38a12d080bc]") {
	REQUIRE(0 == yacht::score({1, 2, 3, 4, 5}, "big straight"));
}

TEST_CASE("Four in order but not a little straight", "[97bde8f7-9058-43ea-9de7-0bc3ed6d3002]") {
	REQUIRE(0 == yacht::score({1, 1, 2, 3, 4}, "little straight"));
}

TEST_CASE("No pairs but not a little straight", "[cef35ff9-9c5e-4fd2-ae95-6e4af5e95a99]") {
	REQUIRE(0 == yacht::score({1, 2, 3, 4, 6}, "little straight"));
}

TEST_CASE("Minimum is 1, maximum is 5, but not a little straight", "[fd785ad2-c060-4e45-81c6-ea2bbb781b9d]") {
	REQUIRE(0 == yacht::score({1, 1, 3, 4, 5}, "little straight"));
}

TEST_CASE("Big Straight", "[35bd74a6-5cf6-431a-97a3-4f713663f467]") {
	REQUIRE(30 == yacht::score({4, 6, 2, 5, 3}, "big straight"));
}

TEST_CASE("Big Straight as little straight", "[87c67e1e-3e87-4f3a-a9b1-62927822b250]") {
	REQUIRE(0 == yacht::score({6, 5, 4, 3, 2}, "little straight"));
}

TEST_CASE("No pairs but not a big straight", "[c1fa0a3a-40ba-4153-a42d-32bc34d2521e]") {
	REQUIRE(0 == yacht::score({6, 5, 4, 3, 1}, "big straight"));
}

TEST_CASE("Choice", "[207e7300-5d10-43e5-afdd-213e3ac8827d]") {
	REQUIRE(23 == yacht::score({3, 3, 5, 6, 6}, "choice"));
}

TEST_CASE("Yacht as choice", "[b524c0cf-32d2-4b40-8fb3-be3500f3f135]") {
	REQUIRE(10 == yacht::score({2, 2, 2, 2, 2}, "choice"));
}

#endif
