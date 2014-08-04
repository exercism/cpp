#include "anagram.h"
#include <boost/algorithm/string/case_conv.hpp>
#include <algorithm>
#include <cctype>

using namespace std;

namespace
{

string to_lower(std::string const& s)
{
    string result{s};
    boost::to_lower(result);
    return result;
}

string make_key(std::string const& s)
{
    string key{to_lower(s)};
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
                && to_lower(s) != to_lower(subject_)
                && make_key(s) == key_) {
            result.push_back(s);
        }
    }
    return result;
}

}
