#include "food_chain.h"

using namespace std;

namespace food_chain {

namespace {

class song_verse {
   public:
    song_verse(string f, string r, string v)
        : food_(f), reaction_(r), verse_(v) {}

    string sing() const {
        return "I know an old lady who swallowed a " + food_ + ".\n" +
               reaction_ + verse_;
    }

    string verse() const { return verse_; }

   private:
    string food_;
    string reaction_;
    string verse_;
};

song_verse const song_verses[] = {
    {"fly", "",
     "I don't know why she swallowed the fly. Perhaps she'll die.\n"},
    {"spider", "It wriggled and jiggled and tickled inside her.\n",
     "She swallowed the spider to catch the fly.\n"},
    {"bird", "How absurd to swallow a bird!\n",
     "She swallowed the bird to catch the spider that wriggled and jiggled and "
     "tickled inside her.\n"},
    {"cat", "Imagine that, to swallow a cat!\n",
     "She swallowed the cat to catch the bird.\n"},
    {"dog", "What a hog, to swallow a dog!\n",
     "She swallowed the dog to catch the cat.\n"},
    {"goat", "Just opened her throat and swallowed a goat!\n",
     "She swallowed the goat to catch the dog.\n"},
    {"cow", "I don't know how she swallowed a cow!\n",
     "She swallowed the cow to catch the goat.\n"},
    {"horse", "", "She's dead, of course!\n"}};

const unsigned num_verses = sizeof(song_verses) / sizeof(song_verses[0]);

}  // namespace

string verse(unsigned num) {
    if (num > 0 && num <= num_verses) {
        --num;
        string text = song_verses[num].sing();
        if (num < num_verses - 1) {
            while (num--) {
                text += song_verses[num].verse();
            }
        }
        return text;
    }
    return "";
}

string verses(unsigned begin, unsigned end) {
    string text;
    for (unsigned v = begin; v <= end; ++v) {
        text += verse(v) + "\n";
    }
    return text;
}

string sing() { return verses(1, num_verses); }

}  // namespace food_chain
