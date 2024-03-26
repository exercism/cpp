#include <iterator>
#include <sstream>
#include <stdexcept>

#include "say.h"

using namespace std;

namespace {

const string singles_and_teens_names[] = {
    "zero",    "one",     "two",       "three",    "four",
    "five",    "six",     "seven",     "eight",    "nine",
    "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

const string tens_names[] = {"twenty", "thirty",  "forty",  "fifty",
                             "sixty",  "seventy", "eighty", "ninety"};

typedef unsigned long long number_t;

const number_t twenty{20ULL};
const number_t one_hundred{100ULL};
const number_t one_thousand{1000ULL};
const number_t one_million{one_thousand * one_thousand};
const number_t one_billion{one_thousand * one_million};
const number_t one_trillion{one_thousand * one_billion};

struct {
    number_t threshold;
    string name;
} const units[] = {{one_billion, "billion"},
                   {one_million, "million"},
                   {one_thousand, "thousand"},
                   {one_hundred, "hundred"}};

void in_english(ostream& english, number_t number) {
    for (auto unit : units) {
        if (number >= unit.threshold) {
            in_english(english, number / unit.threshold);
            english << ' ' << unit.name;
            number %= unit.threshold;

            if (!number) {
                return;
            }
            english << ' ';
        }
    }

    if (number >= twenty) {
        const number_t tens{number / 10ULL - 2ULL};
        english << tens_names[tens];

        if (const number_t single{number % 10ULL}) {
            english << '-' << singles_and_teens_names[single];
        }
    } else {
        english << singles_and_teens_names[number];
    }
}

}  // namespace

namespace say {

string in_english(number_t number) {
    if (number >= one_trillion) {
        throw std::domain_error("argument out of range");
    }

    ostringstream english;
    ::in_english(english, number);
    return english.str();
}

}  // namespace say
