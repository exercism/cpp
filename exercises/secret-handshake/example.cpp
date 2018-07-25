#include "secret_handshake.h"
#include <algorithm>

std::vector<std::string> handshake::commands(int num) {
	int curr_bit = 1;
	const std::vector<std::string> command_list{ "wink", "double blink", "close your eyes", "jump" };
	std::vector<std::string> output;

	do {
		if (num & 1) {
			if (curr_bit < 5) {
				output.push_back(command_list.at(curr_bit - 1));
			}
			else {
				std::reverse(output.begin(), output.end());
			}
		}
		++curr_bit;
	} while (num >>= 1, num && curr_bit <= 5);

	return output;
}
