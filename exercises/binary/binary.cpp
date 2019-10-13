#include "binary.h"
#include <string>
#include <iostream>
#include <algorithm>

namespace binary {
	int convert(std::string binaryStr) {
		int binaryConverted = 0;
		int bits = std::count(binaryStr.begin(), binaryStr.end(), '0') + std::count(binaryStr.begin(), binaryStr.end(), '1');
		for (int i = bits; binaryStr[bits - i]; i--) {
			if (binaryStr[bits - i] == '0' || binaryStr[bits - i] == '1') {
				binaryConverted += (binaryStr[bits - i] - '0') * pow(2, i - 1);
			}
			else {
				std::cout << "Please enter a valid number.";
				binaryConverted = 0;
				break;
			}
		}
		return binaryConverted;
	}
}  // namespace binary