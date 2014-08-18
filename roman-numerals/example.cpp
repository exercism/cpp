#include "roman_numerals.h"

namespace
{

struct digit_values
{
    char numeral;
    int value;
};

const digit_values roman_numerals[] =
{
    { 'M', 1000 },
    { 'D', 500 },
    { 'C', 100 },
    { 'L', 50 },
    { 'X', 10 },
    { 'V', 5 },
    { 'I', 1 }
};

class converter
{
public:
    converter(int n)
        : n_(n)
    {}

    std::string convert();

private:
    void convert_thousands();
    void convert_hundreds();
    void convert_tens();
    void convert_ones();
    void convert_place(int place);
    void convert_place_numeral(int place);
    void convert_place_numeral_penultimate(int place, int penultimate_place);

    int n_;
    std::string result_;
};

std::string converter::convert()
{
    convert_thousands();
    convert_hundreds();
    convert_tens();
    convert_ones();
    return result_;
}

void converter::convert_thousands()
{
    convert_place(0);
}

void converter::convert_hundreds()
{
    convert_place(2);
}

void converter::convert_tens()
{
    convert_place(4);
}

void converter::convert_ones()
{
    result_ += std::string(n_, 'I');
}

void converter::convert_place(int place)
{
    const int tenth_place = place + 2;
    convert_place_numeral(place);
    convert_place_numeral_penultimate(place, tenth_place);
    const int half_place = place + 1;
    convert_place_numeral(half_place);
    convert_place_numeral_penultimate(half_place, tenth_place);
}

void converter::convert_place_numeral(int place)
{
    while (n_ >= roman_numerals[place].value) {
        result_ += roman_numerals[place].numeral;
        n_ -= roman_numerals[place].value;
    }
}

void converter::convert_place_numeral_penultimate(int place, int penultimate_place)
{
    if (n_ >= roman_numerals[place].value - roman_numerals[penultimate_place].value) {
        result_ += roman_numerals[penultimate_place].numeral;
        result_ += roman_numerals[place].numeral;
        n_ -= roman_numerals[place].value - roman_numerals[penultimate_place].value;
    }
}

}

std::string roman::convert(int n)
{
    return converter(n).convert();
}
