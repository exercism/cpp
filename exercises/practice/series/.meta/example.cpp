#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "series.h"

using namespace std;

namespace series {

inline string slice_me(const string &input, unsigned int start,
                       unsigned int window) {
    auto end = start + window;
    stringstream baby_slice;
    for (size_t pos = start; pos < end; pos++) baby_slice << input[pos];
    return baby_slice.str();
}

string digits(const string &input) {
    return slice_me(input, 0, input.length());
}

vector<string> slice(const string &input, size_t window) {
    auto len = input.length();
    if (len < window || window < 1)
        throw domain_error("Window size must be within size of the slice.");
    vector<string> ginger_slice;
    ginger_slice.reserve(len / window);
    auto end = len - window;
    for (size_t position = 0; position <= end; position++)
        ginger_slice.emplace_back(slice_me(input, position, window));
    return ginger_slice;
}

}  // namespace series
