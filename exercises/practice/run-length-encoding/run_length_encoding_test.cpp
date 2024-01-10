#include "run_length_encoding.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("encode empty string", "[encode]") {
  REQUIRE(run_length_encoding::encode("") == "");
}
#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("encode single characters only are encoded without count", "[encode]") {
  REQUIRE(run_length_encoding::encode("XYZ") == "XYZ");
}

TEST_CASE("encode string with no single characters", "[encode]") {
  REQUIRE(run_length_encoding::encode("AABBBCCCC") == "2A3B4C");
}

TEST_CASE("encode single characters mixed with repeated characters", "[encode]") {
  REQUIRE(run_length_encoding::encode("WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB") == "12WB12W3B24WB");
}

TEST_CASE("encode multiple whitespace mixed in string", "[encode]") {
  REQUIRE(run_length_encoding::encode("  hsqq qww  ") == "2 hs2q q2w2 ");
}

TEST_CASE("encode lowercase characters", "[encode]") {
  REQUIRE(run_length_encoding::encode("aabbbcccc") == "2a3b4c");
}

TEST_CASE("decode run-length decode a string", "[decode]") {
  REQUIRE(run_length_encoding::decode("") == "");
}

TEST_CASE("decode single characters only", "[decode]") {
  REQUIRE(run_length_encoding::decode("XYZ") == "XYZ");
}

TEST_CASE("decode string with no single characters", "[decode]") {
  REQUIRE(run_length_encoding::decode("2A3B4C") == "AABBBCCCC");
}

TEST_CASE("decode single characters with repeated characters", "[decode]") {
  REQUIRE(run_length_encoding::decode("12WB12W3B24WB") == "WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB");
}

TEST_CASE("decode multiple whitespace mixed in string", "[decode]") {
  REQUIRE(run_length_encoding::decode("2 hs2q q2w2 ") == "  hsqq qww  ");
}

TEST_CASE("decode lowercase string", "[decode]") {
  REQUIRE(run_length_encoding::decode("2a3b4c") == "aabbbcccc");
}

TEST_CASE("encode and then decode", "[consistency]") {
  REQUIRE(run_length_encoding::decode(run_length_encoding::encode("zzz ZZ  zZ")) == "zzz ZZ  zZ");
}
#endif
