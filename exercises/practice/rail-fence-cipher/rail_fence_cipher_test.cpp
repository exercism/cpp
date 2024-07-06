#include "rail_fence_cipher.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("encode with two rails", "[46dc5c50-5538-401d-93a5-41102680d068]") {
    REQUIRE(rail_fence_cipher::encode("XOXOXOXOXOXOXOXOXO", 2) ==
            "XXXXXXXXXOOOOOOOOO");
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("encode with three rails", "[25691697-fbd8-4278-8c38-b84068b7bc29]") {
    REQUIRE(rail_fence_cipher::encode("WEAREDISCOVEREDFLEEATONCE", 3) ==
            "WECRLTEERDSOEEFEAOCAIVDEN");
}

TEST_CASE("encode with ending in the middle",
          "[384f0fea-1442-4f1a-a7c4-5cbc2044002c]") {
    REQUIRE(rail_fence_cipher::encode("EXERCISES", 4) == "ESXIEECSR");
}

TEST_CASE("decode_with_three_rails", "[cd525b17-ec34-45ef-8f0e-4f27c24a7127]") {
    REQUIRE(rail_fence_cipher::decode("TEITELHDVLSNHDTISEIIEA", 3) ==
            "THEDEVILISINTHEDETAILS");
}

TEST_CASE("decode_with_five_rails", "[dd7b4a98-1a52-4e5c-9499-cbb117833507]") {
    REQUIRE(rail_fence_cipher::decode("EIEXMSMESAORIWSCE", 5) ==
            "EXERCISMISAWESOME");
}

TEST_CASE("decode_with_six_rails", "[93e1ecf4-fac9-45d9-9cd2-591f47d3b8d3]") {
    REQUIRE(rail_fence_cipher::decode(
                "133714114238148966225439541018335470986172518171757571896261",
                6) ==
            "112358132134558914423337761098715972584418167651094617711286");
}

#endif
