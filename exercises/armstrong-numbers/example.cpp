#include "armstrong_numbers.h"
#include <cmath>

bool armstrong_numbers::is_armstrong_number(int number) {
    int length = static_cast<bool>(number) * static_cast<int>(std::log10(std::abs(number))) + 1;
    int accumulate = 0;
    for (int current = number; current != 0; current /= 10) {
        accumulate += std::pow(current % 10, length);
    }
    return accumulate == number;
}