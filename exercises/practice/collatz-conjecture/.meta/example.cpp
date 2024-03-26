#include <stdexcept>

#include "collatz_conjecture.h"

int collatz_conjecture::steps(int value) {
    if (value <= 0)
        throw std::domain_error("Only positive numbers are allowed!");
    int step = 0;
    while (value != 1) {
        value = value % 2 == 0 ? value / 2 : 3 * value + 1;
        ++step;
    }
    return step;
}
