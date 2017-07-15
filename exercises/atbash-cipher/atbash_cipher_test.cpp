#include "atbash_cipher.h"
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(encode_yes)
{
    BOOST_REQUIRE_EQUAL("bvh", atbash::encode("yes"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
BOOST_AUTO_TEST_CASE(encode_no)
{
    BOOST_REQUIRE_EQUAL("ml", atbash::encode("no"));
}

BOOST_AUTO_TEST_CASE(encode_OMG)
{
    BOOST_REQUIRE_EQUAL("lnt", atbash::encode("OMG"));
}

BOOST_AUTO_TEST_CASE(encode_spaces)
{
    BOOST_REQUIRE_EQUAL("lnt", atbash::encode("O M G"));
}

BOOST_AUTO_TEST_CASE(encode_mindblowingly)
{
    BOOST_REQUIRE_EQUAL("nrmwy oldrm tob", atbash::encode("mindblowingly"));
}

BOOST_AUTO_TEST_CASE(encode_numbers)
{
    BOOST_REQUIRE_EQUAL("gvhgr mt123 gvhgr mt", atbash::encode("Testing,1 2 3, testing."));
}

BOOST_AUTO_TEST_CASE(encode_deep_thought)
{
    BOOST_REQUIRE_EQUAL("gifgs rhurx grlm", atbash::encode("Truth is fiction."));
}

BOOST_AUTO_TEST_CASE(encode_all_the_letters)
{
    BOOST_REQUIRE_EQUAL("gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt",
                        atbash::encode("The quick brown fox jumps over the lazy dog."));
}

BOOST_AUTO_TEST_CASE(decode_exercism)
{
    BOOST_REQUIRE_EQUAL("exercism", atbash::decode("vcvix rhn"));
}

BOOST_AUTO_TEST_CASE(decode_a_sentence)
{
    BOOST_REQUIRE_EQUAL("anobstacleisoftenasteppingstone",
                        atbash::decode("zmlyh gzxov rhlug vmzhg vkkrm thglm v"));
}

BOOST_AUTO_TEST_CASE(decode_numbers)
{
    BOOST_REQUIRE_EQUAL("testing123testing", atbash::decode("gvhgr mt123 gvhgr mt"));
}

BOOST_AUTO_TEST_CASE(decode_all_the_letters)
{
    BOOST_REQUIRE_EQUAL("thequickbrownfoxjumpsoverthelazydog",
                        atbash::decode("gsvjf rxpyi ldmul cqfnk hlevi gsvoz abwlt"));
}
#endif
