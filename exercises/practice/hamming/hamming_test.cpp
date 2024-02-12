#include "hamming.h"
#include <stdexcept>
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("single letter identical strands", "[hamming][54681314-eee2-439a-9db0-b0636c656156]")
{
    REQUIRE(0 == hamming::compute("A", "A"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("empty strands", "[hamming][f6dcb64f-03b0-4b60-81b1-3c9dbf47e887]")
{
    REQUIRE(0 == hamming::compute("", ""));
}

TEST_CASE("single letter different strands", "[hamming][294479a3-a4c8-478f-8d63-6209815a827b]")
{
    REQUIRE(1 == hamming::compute("G", "T"));
}

TEST_CASE("long identical strands", "[hamming][9aed5f34-5693-4344-9b31-40c692fb5592]")
{
    REQUIRE(0 == hamming::compute("GGACTGAAATCTG", "GGACTGAAATCTG"));
}

TEST_CASE("long different strands", "[hamming][cd2273a5-c576-46c8-a52b-dee251c3e6e5]")
{
    REQUIRE(9 == hamming::compute("GGACGGATTCTG", "AGGACGGATTCT"));
}

TEST_CASE("disallow first strand longer", "[hamming][b9228bb1-465f-4141-b40f-1f99812de5a8]")
{
    REQUIRE_THROWS_AS(hamming::compute("AATG", "AAA"), std::domain_error);
}

TEST_CASE("disallow second strand longer", "[hamming][dab38838-26bb-4fff-acbe-3b0a9bfeba2d]")
{
    REQUIRE_THROWS_AS(hamming::compute("ATA", "AGTG"), std::domain_error);
}

TEST_CASE("disallow empty first strand", "[hamming][b764d47c-83ff-4de2-ab10-6cfe4b15c0f3]")
{
    REQUIRE_THROWS_AS(hamming::compute("", "G"), std::domain_error);
}

TEST_CASE("disallow empty second strand", "[hamming][9ab9262f-3521-4191-81f5-0ed184a5aa89]")
{
    REQUIRE_THROWS_AS(hamming::compute("G", ""), std::domain_error);
}
#endif
