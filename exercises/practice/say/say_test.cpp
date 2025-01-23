#include "say.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("zero", "[5d22a120-ba0c-428c-bd25-8682235d83e8]") {
    REQUIRE("zero" == say::in_english(0));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("one", "[9b5eed77-dbf6-439d-b920-3f7eb58928f6]") {
    REQUIRE("one" == say::in_english(1));
}

TEST_CASE("fourteen", "[7c499be1-612e-4096-a5e1-43b2f719406d]") {
    REQUIRE("fourteen" == say::in_english(14));
}

TEST_CASE("twenty", "[f541dd8e-f070-4329-92b4-b7ce2fcf06b4]") {
    REQUIRE("twenty" == say::in_english(20));
}

TEST_CASE("twenty-two", "[d78601eb-4a84-4bfa-bf0e-665aeb8abe94]") {
    REQUIRE("twenty-two" == say::in_english(22));
}

TEST_CASE("thirty", "[f010d4ca-12c9-44e9-803a-27789841adb1]") {
    REQUIRE("thirty" == say::in_english(30));
}

TEST_CASE("ninety-nine", "[738ce12d-ee5c-4dfb-ad26-534753a98327]") {
    REQUIRE("ninety-nine" == say::in_english(99));
}

TEST_CASE("one hundred", "[e417d452-129e-4056-bd5b-6eb1df334dce]") {
    REQUIRE("one hundred" == say::in_english(100));
}

TEST_CASE("one hundred twenty-three",
          "[d6924f30-80ba-4597-acf6-ea3f16269da8]") {
    REQUIRE("one hundred twenty-three" == say::in_english(123));
}

TEST_CASE("two hundred", "[2f061132-54bc-4fd4-b5df-0a3b778959b9]") {
    REQUIRE("two hundred" == say::in_english(200));
}

TEST_CASE("nine hundred ninety-nine",
          "[feed6627-5387-4d38-9692-87c0dbc55c33]") {
    REQUIRE("nine hundred ninety-nine" == say::in_english(999));
}

TEST_CASE("one thousand", "[3d83da89-a372-46d3-b10d-de0c792432b3]") {
    REQUIRE("one thousand" == say::in_english(1000));
}

TEST_CASE("one thousand two hundred thirty-four",
          "[865af898-1d5b-495f-8ff0-2f06d3c73709]") {
    REQUIRE("one thousand two hundred thirty-four" == say::in_english(1234));
}

TEST_CASE("one million", "[b6a3f442-266e-47a3-835d-7f8a35f6cf7f]") {
    REQUIRE("one million" == say::in_english(1000000));
}

TEST_CASE("one million two thousand three hundred forty-five",
          "[2cea9303-e77e-4212-b8ff-c39f1978fc70]") {
    REQUIRE("one million two thousand three hundred forty-five" ==
            say::in_english(1002345));
}

TEST_CASE("one billion", "[3e240eeb-f564-4b80-9421-db123f66a38f]") {
    REQUIRE("one billion" == say::in_english(1000000000));
}

TEST_CASE("a big number", "[9a43fed1-c875-4710-8286-5065d73b8a9e]") {
    REQUIRE(
        "nine hundred eighty-seven billion six hundred fifty-four million "
        "three hundred twenty-one thousand one hundred twenty-three" ==
        say::in_english(987654321123));
}

TEST_CASE("numbers below zero are out of range",
          "[49a6a17b-084e-423e-994d-a87c0ecc05ef]") {
    REQUIRE_THROWS_AS(say::in_english(-1), std::domain_error);
}

TEST_CASE("numbers above 999,999,999,999 are out of range",
          "[4d6492eb-5853-4d16-9d34-b0f61b261fd9]") {
    REQUIRE_THROWS_AS(say::in_english(1000000000000), std::domain_error);
}

#endif
