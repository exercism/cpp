#include <algorithm>
#include <cctype>

#include "anagram.h"

using namespace std;

namespace {

string to_lower_copy(string const& s) {
    string cpy(s);
    for (auto& c : cpy) {
        c = tolower(c);
    }
    return cpy;
}

string make_key(string const& s) {
    string key{to_lower_copy(s)};
    sort(key.begin(), key.end());
    return key;
}

}  // namespace

namespace anagram {

anagram::anagram(string const& subject)
    : subject_(subject), key_(make_key(subject)) {}

vector<string> anagram::matches(vector<string> const& matches) {
    vector<string> result;
    for (string const& s : matches) {
        if (s.length() == key_.length() &&
            to_lower_copy(s) != to_lower_copy(subject_) &&
            make_key(s) == key_) {
            result.push_back(s);
        }
    }
    return result;
}

}  // namespace anagram
