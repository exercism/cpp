#include "roman_numerals.h"

namespace {

struct digit_values {
    char numeral;
    int value;
};

const digit_values roman_numerals[] = {{'M', 1000}, {'D', 500}, {'C', 100},
                                       {'L', 50},   {'X', 10},  {'V', 5},
                                       {'I', 1}};

class converter {
   public:
    converter(int n) : n_(n) {}

    std::string convert();

   private:
    void thousands();
    void hundreds();
    void tens();
    void ones();
    void place(int place);
    void place_numeral(int place);
    void place_numeral_penultimate(int place, int penultimate_place);

    int n_;
    std::string result_;
};

std::string converter::convert() {
    thousands();
    hundreds();
    tens();
    ones();
    return result_;
}

void converter::thousands() { place(0); }

void converter::hundreds() { place(2); }

void converter::tens() { place(4); }

void converter::ones() { result_ += std::string(n_, 'I'); }

void converter::place(int place) {
    const int tenth_place = place + 2;
    place_numeral(place);
    place_numeral_penultimate(place, tenth_place);
    const int half_place = place + 1;
    place_numeral(half_place);
    place_numeral_penultimate(half_place, tenth_place);
}

void converter::place_numeral(int place) {
    while (n_ >= roman_numerals[place].value) {
        result_ += roman_numerals[place].numeral;
        n_ -= roman_numerals[place].value;
    }
}

void converter::place_numeral_penultimate(int place, int penultimate_place) {
    const int amount =
        roman_numerals[place].value - roman_numerals[penultimate_place].value;
    if (n_ >= amount) {
        result_ += roman_numerals[penultimate_place].numeral;
        result_ += roman_numerals[place].numeral;
        n_ -= amount;
    }
}

}  // namespace

std::string roman_numerals::convert(int n) { return converter(n).convert(); }
