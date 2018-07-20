#include "collatz_conjecture.h"
#include <stdexcept>

int collatz::steps(int num) {
	int steps = 0;
	
	if (num <= 0) {
		throw std::domain_error("Only positive numbers are allowed.");
	}

	while (num != 1) {
		num = num % 2 ? num * 3 + 1 : num / 2;
		++steps;
	}

	return steps;
}
