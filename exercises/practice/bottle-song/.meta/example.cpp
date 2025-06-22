#include "bottle_song.h"

namespace bottle_song {

static const std::string wordsCap[] = {"Zero",  "One",  "Two", "Three",
                                       "Four",  "Five", "Six", "Seven",
                                       "Eight", "Nine", "Ten"};
static const std::string wordsLower[] = {"no",    "one",  "two", "three",
                                         "four",  "five", "six", "seven",
                                         "eight", "nine", "ten"};

std::vector<std::string> recite(int startBottles, int takeDown) {
    std::vector<std::string> verses;
    int end = startBottles - takeDown + 1;
    for (int bottles = startBottles; bottles >= end; --bottles) {
        int next = bottles - 1;
        verses.push_back(wordsCap[bottles] + " green bottle" +
                         (bottles == 1 ? "" : "s") + " hanging on the wall,");
        verses.push_back(wordsCap[bottles] + " green bottle" +
                         (bottles == 1 ? "" : "s") + " hanging on the wall,");
        verses.push_back("And if one green bottle should accidentally fall,");
        std::string nextWord =
            (next >= 0 && next <= 10) ? wordsLower[next] : std::to_string(next);
        verses.push_back("There'll be " + nextWord + " green bottle" +
                         (next == 1 ? "" : "s") + " hanging on the wall.");
        if (bottles > end) {
            verses.push_back("");
        }
    }
    return verses;
}

}  // namespace bottle_song