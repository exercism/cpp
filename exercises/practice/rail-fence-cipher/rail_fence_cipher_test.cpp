#include "rail_fence_cipher.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("encode with one rail, same output as input", "") {
    REQUIRE(rail_fence_cipher::encode("XOXOXOXOXOXOXOXOXO", 1) ==
            "XOXOXOXOXOXOXOXOXO");
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("encode with two rails", "") {
    REQUIRE(rail_fence_cipher::encode("XOXOXOXOXOXOXOXOXO", 2) ==
            "XXXXXXXXXOOOOOOOOO");
}

TEST_CASE("encode with three rails", "") {
    REQUIRE(rail_fence_cipher::encode("WEAREDISCOVEREDFLEEATONCE", 3) ==
            "WECRLTEERDSOEEFEAOCAIVDEN");
}

TEST_CASE("encode with ending in the middle", "") {
    REQUIRE(rail_fence_cipher::encode("EXERCISES", 4) == "ESXIEECSR");
}

TEST_CASE("decode_with_three_rails", "") {
    REQUIRE(rail_fence_cipher::decode("TEITELHDVLSNHDTISEIIEA", 3) ==
            "THEDEVILISINTHEDETAILS");
}

TEST_CASE("decode_with_five_rails", "") {
    REQUIRE(rail_fence_cipher::decode("EIEXMSMESAORIWSCE", 5) ==
            "EXERCISMISAWESOME");
}

TEST_CASE("decode_with_six_rails", "") {
    REQUIRE(rail_fence_cipher::decode(
                "133714114238148966225439541018335470986172518171757571896261",
                6) ==
            "112358132134558914423337761098715972584418167651094617711286");
}

#endif
