#include <vector>
#include <boost/algorithm/string.hpp>
#include "acronym.h"

using std::string;
using std::vector;

namespace acronym {

string acronym(string const& input_str)
{
    vector<string> words;
    boost::split(words, input_str, boost::is_any_of(" :-,"));
    string acronym_str;
    for (auto const& s : words) {
        if (!s.empty()) {
            acronym_str.push_back((boost::algorithm::to_upper_copy(s)).front());
        }
    }
    return acronym_str;
}

}
