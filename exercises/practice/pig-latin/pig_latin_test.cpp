#include "pig_latin.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

TEST_CASE("word beginning with a", "[11567f84-e8c6-4918-aedb-435f0b73db57]") {
    REQUIRE("appleay" == pig_latin::translate("apple"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("word beginning with e", "[f623f581-bc59-4f45-9032-90c3ca9d2d90]") {
    REQUIRE("earay" == pig_latin::translate("ear"));
}

TEST_CASE("word beginning with i", "[7dcb08b3-23a6-4e8a-b9aa-d4e859450d58]") {
    REQUIRE("iglooay" == pig_latin::translate("igloo"));
}

TEST_CASE("word beginning with o", "[0e5c3bff-266d-41c8-909f-364e4d16e09c]") {
    REQUIRE("objectay" == pig_latin::translate("object"));
}

TEST_CASE("word beginning with u", "[614ba363-ca3c-4e96-ab09-c7320799723c]") {
    REQUIRE("underay" == pig_latin::translate("under"));
}

TEST_CASE("word beginning with a vowel and followed by a qu",
          "[bf2538c6-69eb-4fa7-a494-5a3fec911326]") {
    REQUIRE("equalay" == pig_latin::translate("equal"));
}

TEST_CASE("word beginning with p", "[e5be8a01-2d8a-45eb-abb4-3fcc9582a303]") {
    REQUIRE("igpay" == pig_latin::translate("pig"));
}

TEST_CASE("word beginning with k", "[d36d1e13-a7ed-464d-a282-8820cb2261ce]") {
    REQUIRE("oalakay" == pig_latin::translate("koala"));
}

TEST_CASE("word beginning with x", "[d838b56f-0a89-4c90-b326-f16ff4e1dddc]") {
    REQUIRE("enonxay" == pig_latin::translate("xenon"));
}

TEST_CASE("word beginning with q without a following u",
          "[bce94a7a-a94e-4e2b-80f4-b2bb02e40f71]") {
    REQUIRE("atqay" == pig_latin::translate("qat"));
}

TEST_CASE("word beginning with ch", "[c01e049a-e3e2-451c-bf8e-e2abb7e438b8]") {
    REQUIRE("airchay" == pig_latin::translate("chair"));
}

TEST_CASE("word beginning with qu", "[9ba1669e-c43f-4b93-837a-cfc731fd1425]") {
    REQUIRE("eenquay" == pig_latin::translate("queen"));
}

TEST_CASE("word beginning with qu and a preceding consonant",
          "[92e82277-d5e4-43d7-8dd3-3a3b316c41f7]") {
    REQUIRE("aresquay" == pig_latin::translate("square"));
}

TEST_CASE("word beginning with th", "[79ae4248-3499-4d5b-af46-5cb05fa073ac]") {
    REQUIRE("erapythay" == pig_latin::translate("therapy"));
}

TEST_CASE("word beginning with thr", "[e0b3ae65-f508-4de3-8999-19c2f8e243e1]") {
    REQUIRE("ushthray" == pig_latin::translate("thrush"));
}

TEST_CASE("word beginning with sch", "[20bc19f9-5a35-4341-9d69-1627d6ee6b43]") {
    REQUIRE("oolschay" == pig_latin::translate("school"));
}

TEST_CASE("word beginning with yt", "[54b796cb-613d-4509-8c82-8fbf8fc0af9e]") {
    REQUIRE("yttriaay" == pig_latin::translate("yttria"));
}

TEST_CASE("word beginning with xr", "[8c37c5e1-872e-4630-ba6e-d20a959b67f6]") {
    REQUIRE("xrayay" == pig_latin::translate("xray"));
}

TEST_CASE("y is treated like a consonant at the beginning of a word",
          "[a4a36d33-96f3-422c-a233-d4021460ff00]") {
    REQUIRE("ellowyay" == pig_latin::translate("yellow"));
}

TEST_CASE("y is treated like a vowel at the end of a consonant cluster",
          "[adc90017-1a12-4100-b595-e346105042c7]") {
    REQUIRE("ythmrhay" == pig_latin::translate("rhythm"));
}
// clang-format off
TEST_CASE(
    "first_letter_and_ay_are_moved_to_the_end_of_words_that_start_with_consonants_->_word_beginning_with_consonant_and_vowel_containing_qu",
    "[e59dbbe8-ccee-4619-a8e9-ce017489bfc0]") {
    REQUIRE("iquidlay" == pig_latin::translate("liquid"));
}
// clang-format on

TEST_CASE("y as second letter in two letter word",
          "[29b4ca3d-efe5-4a95-9a54-8467f2e5e59a]") {
    REQUIRE("ymay" == pig_latin::translate("my"));
}

TEST_CASE("a whole phrase", "[44616581-5ce3-4a81-82d0-40c7ab13d2cf]") {
    REQUIRE("ickquay astfay unray" == pig_latin::translate("quick fast run"));
}

#endif
