#include "word_count.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif


/*
For each word in the input, count the number of times it appears in the
entire sentence.
*/

TEST_CASE("count one word", "[61559d5f-2cad-48fb-af53-d3973a9ee9ef]") {
	const std::map<std::string, int> expected{{"word", 1}};
	REQUIRE(expected == word_count::words("word"));
}

#if defined(EXERCISM_RUN_ALL_TESTS)

TEST_CASE("count one of each word", "[5abd53a3-1aed-43a4-a15a-29f88c09cbbd]") {
	const std::map<std::string, int> expected{{"one", 1}, {"of", 1}, {"each", 1}};
	REQUIRE(expected == word_count::words("one of each"));
}

TEST_CASE("multiple occurrences of a word", "[2a3091e5-952e-4099-9fac-8f85d9655c0e]") {
	const std::map<std::string, int> expected{{"one", 1}, {"fish", 4}, {"two", 1}, {"red", 1}, {"blue", 1}};
	REQUIRE(expected == word_count::words("one fish two fish red fish blue fish"));
}

TEST_CASE("handles cramped lists", "[e81877ae-d4da-4af4-931c-d923cd621ca6]") {
	const std::map<std::string, int> expected{{"one", 1}, {"two", 1}, {"three", 1}};
	REQUIRE(expected == word_count::words("one,two,three"));
}

TEST_CASE("handles expanded lists", "[7349f682-9707-47c0-a9af-be56e1e7ff30]") {
	const std::map<std::string, int> expected{{"one", 1}, {"two", 1}, {"three", 1}};
	REQUIRE(expected == word_count::words("one,\ntwo,\nthree"));
}

TEST_CASE("ignore punctuation", "[a514a0f2-8589-4279-8892-887f76a14c82]") {
	const std::map<std::string, int> expected{{"car", 1}, {"carpet", 1}, {"as", 1}, {"java", 1}, {"javascript", 1}};
	REQUIRE(expected == word_count::words("car: carpet as java: javascript!!&@$%^&"));
}

TEST_CASE("include numbers", "[d2e5cee6-d2ec-497b-bdc9-3ebe092ce55e]") {
	const std::map<std::string, int> expected{{"testing", 2}, {"1", 1}, {"2", 1}};
	REQUIRE(expected == word_count::words("testing, 1, 2 testing"));
}

TEST_CASE("normalize case", "[dac6bc6a-21ae-4954-945d-d7f716392dbf]") {
	const std::map<std::string, int> expected{{"go", 3}, {"stop", 2}};
	REQUIRE(expected == word_count::words("go Go GO Stop stop"));
}

TEST_CASE("with apostrophes", "[4ff6c7d7-fcfc-43ef-b8e7-34ff1837a2d3]") {
	const std::map<std::string, int> expected{{"first", 1}, {"don't", 2}, {"laugh", 1}, {"then", 1}, {"cry", 1}, {"you're", 1}, {"getting", 1}, {"it", 1}};
	REQUIRE(expected == word_count::words("'First: don't laugh. Then: don't cry. You're getting it.'"));
}

TEST_CASE("with quotations", "[be72af2b-8afe-4337-b151-b297202e4a7b]") {
	const std::map<std::string, int> expected{{"joe", 1}, {"can't", 1}, {"tell", 1}, {"between", 1}, {"large", 2}, {"and", 1}};
	REQUIRE(expected == word_count::words("Joe can't tell between 'large' and large."));
}

TEST_CASE("substrings from the beginning", "[8d6815fe-8a51-4a65-96f9-2fb3f6dc6ed6]") {
	const std::map<std::string, int> expected{{"joe", 1}, {"can't", 1}, {"tell", 1}, {"between", 1}, {"app", 1}, {"apple", 1}, {"and", 1}, {"a", 1}};
	REQUIRE(expected == word_count::words("Joe can't tell between app, apple and a."));
}

TEST_CASE("multiple spaces not detected as a word", "[c5f4ef26-f3f7-4725-b314-855c04fb4c13]") {
	const std::map<std::string, int> expected{{"multiple", 1}, {"whitespaces", 1}};
	REQUIRE(expected == word_count::words(" multiple   whitespaces"));
}

TEST_CASE("alternating word separators not detected as a word", "[50176e8a-fe8e-4f4c-b6b6-aa9cf8f20360]") {
	const std::map<std::string, int> expected{{"one", 1}, {"two", 1}, {"three", 1}};
	REQUIRE(expected == word_count::words(",\n,one,\n ,two \n 'three'"));
}

TEST_CASE("quotation for word with apostrophe", "[6d00f1db-901c-4bec-9829-d20eb3044557]") {
	const std::map<std::string, int> expected{{"can", 1}, {"can't", 2}};
	REQUIRE(expected == word_count::words("can, can't, 'can't'"));
}

#endif
