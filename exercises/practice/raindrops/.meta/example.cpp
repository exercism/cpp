#include <sstream>

#include "raindrops.h"

using namespace std;

namespace raindrops {

string convert(int drops) {
    const int pling_factor{3};
    const int plang_factor{5};
    const int plong_factor{7};
    ostringstream result;
    if (drops % pling_factor == 0) {
        result << "Pling";
    }
    if (drops % plang_factor == 0) {
        result << "Plang";
    }
    if (drops % plong_factor == 0) {
        result << "Plong";
    }
    if (!result.tellp()) {
        result << drops;
    }
    return result.str();
}

}  // namespace raindrops
