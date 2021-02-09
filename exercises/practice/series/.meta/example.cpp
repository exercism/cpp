#include "series.h"
#include <stdexcept>

using namespace std;

namespace series
{

vector<int> digits(string const& sequence)
{
    vector<int> result;
    for (const char digit : sequence) {
        result.push_back(digit - '0');
    }
    return result;
}

vector<vector<int>> slice(string const& sequence, int span)
{
    if (span > static_cast<int>(sequence.length())) {
        throw domain_error("Requested span too long for sequence");
    }
    vector<vector<int>> result;
    for (size_t i = 0; i < sequence.length() - (span - 1); ++i) {
        result.push_back(digits(sequence.substr(i, span)));
    }
    return result;
}

}
