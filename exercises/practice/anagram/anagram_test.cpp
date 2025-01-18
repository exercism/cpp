#include "anagram.h"
#ifdef EXERCISM_TEST_SUITE
#include <catch2/catch.hpp>
#else
#include "test/catch.hpp"
#endif

#include <string>
#include <unordered_set>

using namespace std;

// Anagram exercise test case data version 1.5.0

// This class is a helper to allow the solution to return any container type. It
// takes an std::unordered_set of expected values and provides a method
// `is_identical_to` that checks if a given container is as expected. Since the
// method is a method template, it works for any container.
class ExpectedSet {
   public:
    explicit ExpectedSet(std::unordered_set<std::string> e)
        : expected{std::move(e)} {}

    template <typename Container>
    bool is_identical_to(Container const& container) {
        return std::size(expected) == std::size(container) &&
               std::all_of(std::cbegin(container), std::cend(container),
                           [this](auto const& elem) {
                               return expected.count(elem) == 1;
                           });
    }

   private:
    std::unordered_set<std::string> expected{};
};

TEST_CASE("no_matches") {
    // 'anagram::anagram' defines a class
    anagram::anagram subject = anagram::anagram("diaper");
    auto matches = subject.matches({"hello", "world", "zombies", "pants"});
    REQUIRE(ExpectedSet({}).is_identical_to(matches));
}

#if defined(EXERCISM_RUN_ALL_TESTS)
TEST_CASE("detects_two_anagrams",
          "[findAnagrams][03eb9bbe-8906-4ea0-84fa-ffe711b52c8b]") {
    auto subject = anagram::anagram("solemn");
    auto matches = subject.matches({"cherry", "melons", "lemons"});

    REQUIRE(ExpectedSet({"lemons", "melons"}).is_identical_to(matches));
}

TEST_CASE("does_not_detect_anagram_subsets",
          "[findAnagrams][a27558ee-9ba0-4552-96b1-ecf665b06556]") {
    auto subject = anagram::anagram("good");
    auto matches = subject.matches({"dog", "goody"});

    REQUIRE(ExpectedSet({}).is_identical_to(matches));
}

TEST_CASE("detects_anagram",
          "[findAnagrams][64cd4584-fc15-4781-b633-3d814c4941a4]") {
    auto subject = anagram::anagram("listen");
    auto matches = subject.matches({"enlists", "google", "inlets", "banana"});

    REQUIRE(ExpectedSet({"inlets"}).is_identical_to(matches));
}

TEST_CASE("detects_three_anagrams",
          "[findAnagrams][99c91beb-838f-4ccd-b123-935139917283]") {
    auto subject = anagram::anagram("allergy");
    auto matches = subject.matches(
        {"gallery", "ballerina", "regally", "clergy", "largely", "leading"});

    REQUIRE(ExpectedSet({"gallery", "regally", "largely"})
                .is_identical_to(matches));
}

TEST_CASE("detects_multiple_anagrams_with_different_case",
          "[findAnagrams][78487770-e258-4e1f-a646-8ece10950d90]") {
    auto subject = anagram::anagram("nose");
    auto matches = subject.matches({"Eons", "ONES"});

    REQUIRE(ExpectedSet({"Eons", "ONES"}).is_identical_to(matches));
}

TEST_CASE("does_not_detect_non_anagrams_with_identical_checksum",
          "[findAnagrams][1d0ab8aa-362f-49b7-9902-3d0c668d557b]") {
    auto subject = anagram::anagram("mass");
    auto matches = subject.matches({"last"});

    REQUIRE(ExpectedSet({}).is_identical_to(matches));
}

TEST_CASE("detects_anagrams_case_insensitively",
          "[findAnagrams][9e632c0b-c0b1-4804-8cc1-e295dea6d8a8]") {
    auto subject = anagram::anagram("Orchestra");
    auto matches = subject.matches({"cashregister", "Carthorse", "radishes"});

    REQUIRE(ExpectedSet({"Carthorse"}).is_identical_to(matches));
}

TEST_CASE("detects_anagrams_using_case_insensitive_subject",
          "[findAnagrams][b248e49f-0905-48d2-9c8d-bd02d8c3e392]") {
    auto subject = anagram::anagram("Orchestra");
    auto matches = subject.matches({"cashregister", "carthorse", "radishes"});

    REQUIRE(ExpectedSet({"carthorse"}).is_identical_to(matches));
}

TEST_CASE("detects_anagrams_using_case_insensitive_possible_matches",
          "[findAnagrams][f367325c-78ec-411c-be76-e79047f4bd54]") {
    auto subject = anagram::anagram("orchestra");
    auto matches = subject.matches({"cashregister", "Carthorse", "radishes"});

    REQUIRE(ExpectedSet({"Carthorse"}).is_identical_to(matches));
}

TEST_CASE("does_not_detect_an_anagram_if_the_original_word_is_repeated",
          "[findAnagrams][630abb71-a94e-4715-8395-179ec1df9f91]") {
    auto subject = anagram::anagram("go");
    auto matches = subject.matches({"goGoGO"});

    REQUIRE(ExpectedSet({}).is_identical_to(matches));
}

TEST_CASE("anagrams_must_use_all_letters_exactly_once",
          "[findAnagrams][9878a1c9-d6ea-4235-ae51-3ea2befd6842]") {
    auto subject = anagram::anagram("tapper");
    auto matches = subject.matches({"patter"});

    REQUIRE(ExpectedSet({}).is_identical_to(matches));
}

TEST_CASE("words_are_not_anagrams_of_themselves",
          "[findAnagrams][68934ed0-010b-4ef9-857a-20c9012d1ebf]") {
    auto subject = anagram::anagram("BANANA");
    auto matches = subject.matches({"BANANA"});

    REQUIRE(ExpectedSet({}).is_identical_to(matches));
}

TEST_CASE(
    // clang-format off
    "words_are_not_anagrams_of_themselves_even_if_letter_case_is_partially_different",
    // clang-format on
    "[findAnagrams][589384f3-4c8a-4e7d-9edc-51c3e5f0c90e]") {
    auto subject = anagram::anagram("BANANA");
    auto matches = subject.matches({"Banana"});

    REQUIRE(ExpectedSet({}).is_identical_to(matches));
}

TEST_CASE(
    // clang-format off
    "words_are_not_anagrams_of_themselves_even_if_letter_case_is_completely_different",
    // clang-format on
    "[findAnagrams][ba53e423-7e02-41ee-9ae2-71f91e6d18e6]") {
    auto subject = anagram::anagram("BANANA");
    auto matches = subject.matches({"banana"});

    REQUIRE(ExpectedSet({}).is_identical_to(matches));
}

TEST_CASE("words_other_than_themselves_can_be_anagrams",
          "[findAnagrams][33d3f67e-fbb9-49d3-a90e-0beb00861da7]") {
    auto subject = anagram::anagram("LISTEN");
    auto matches = subject.matches({"Silent", "LISTEN"});

    REQUIRE(ExpectedSet({"Silent"}).is_identical_to(matches));
}
#endif
