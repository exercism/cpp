#include "anagram.h"
#include <boost/algorithm/string/case_conv.hpp>
#include <algorithm>
#include <cctype>

using namespace std;

namespace
{

string make_key(std::string const& s)
{
    string key{boost::to_lower_copy(s)};
    sort(key.begin(), key.end());
    return key;
}

}

namespace anagram
{

anagram::anagram(string const& subject)
    : subject_(subject),
    key_(make_key(subject))
{
}

vector<string> anagram::matches(vector<string> const& matches)
{
    vector<string> result;
    for (string const& s : matches) {
        if (s.length() == key_.length()
                && boost::to_lower_copy(s) != boost::to_lower_copy(subject_)
                && make_key(s) == key_) {
            result.push_back(s);
        }
    }
    return result;
}

}
