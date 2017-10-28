#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include "acronym.h"

using std::string;
using std::vector;

namespace acronym {

const string acronym(string const& input_str)
{
    vector<string> words;
    boost::split(words, input_str, boost::is_any_of(" :-,"));

    string acronym_str;
    for(vector<string>::iterator it = words.begin(); it != words.end(); ++it)
    {
        boost::algorithm::to_upper(*it);
        acronym_str.append(*it, 0, 1);
    }

    return acronym_str;
}

}
