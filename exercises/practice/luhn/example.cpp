#include "luhn.h"

using namespace std;

namespace luhn {
bool valid(string const& input_str) {
    int result = 0;
    int counter = 0;
    for (auto c = input_str.rbegin(); c != input_str.rend(); c++) {
        if (*c == ' ') {
            continue;
        } else if (isdigit(*c)) {
            const int digit = (int)*c - '0';
            if (counter % 2 == 1) {
                result = (digit * 2 > 9) ? (result + digit * 2 - 9)
                                         : (result + digit * 2);
            } else {
                result = result + digit;
            }
            counter++;
        } else {
            return false;
        }
    }

    if (counter > 1) {
        return result % 10 == 0;
    } else {
        return false;
    }
}
}  // namespace luhn
