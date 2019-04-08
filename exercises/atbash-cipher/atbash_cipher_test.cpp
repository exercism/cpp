#include "atbash_cipher.h"
#define CATCH_CONFIG_MAIN
#include "test/catch.hpp"

TEST_CASE("encode_yes")
{
    REQUIRE("bvh" == atbash::encode("yes"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("encode_no")
{
    REQUIRE("ml" == atbash::encode("no"));
}

TEST_CASE("encode_OMG")
{
    REQUIRE("lnt" == atbash::encode("OMG"));
}

TEST_CASE("encode_spaces")
{
    REQUIRE("lnt" == atbash::encode("O M G"));
}

TEST_CASE("encode_mindblowingly")
{
    REQUIRE("nrmwy oldrm tob" == atbash::encode("mindblowingly"));
}

TEST_CASE("encode_numbers")
{
    REQUIRE("gvhgr mt123 gvhgr mt" == atbash::encode("Testing,1 2 3, testing."));
}

TEST_CASE("encode_deep_thought")
{
    REQUIRE("gifgs rhurx grlm" == atbash::encode("Truth is fiction."));
}

TEST_CASE("encode_all_the_letters")
{
    REQUIRE("gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt" ==
                        atbash::encode("The quick brown fox jumps over the lazy dog."));
}

TEST_CASE("decode_exercism")
{
    REQUIRE("exercism" == atbash::decode("vcvix rhn"));
}

TEST_CASE("decode_a_sentence")
{
    REQUIRE("anobstacleisoftenasteppingstone" ==
                        atbash::decode("zmlyh gzxov rhlug vmzhg vkkrm thglm v"));
}

TEST_CASE("decode_numbers")
{
    REQUIRE("testing123testing" == atbash::decode("gvhgr mt123 gvhgr mt"));
}

TEST_CASE("decode_all_the_letters")
{
    REQUIRE("thequickbrownfoxjumpsoverthelazydog" ==
                        atbash::decode("gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt"));
}
#endif
