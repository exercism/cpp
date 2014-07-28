#include <algorithm>
#include <cctype>
#include <iterator>
#include <vector>

#include "word_count.h"

using namespace std;

namespace
{

vector<string> split_words(string const& text)
{
    vector<string> words;
    string::size_type start = 0;
    string::size_type space = text.find_first_of(" \n");
    for (; space != string::npos; space = text.find_first_of(" \n", start)) {
        if (space > start) {
            words.push_back(text.substr(start, space-start));
        }
        start = space + 1;
    }
    words.push_back(text.substr(start));
    return words;
}

string to_lower(string const& text)
{
    string lowered;
    transform(text.begin(), text.end(), back_inserter(lowered), tolower);
    return lowered;
}

string strip_punctuation(string const& text)
{
    string stripped;
    remove_copy_if(text.begin(), text.end(), back_inserter(stripped), ispunct);
    return stripped;
}

}

namespace word_count
{

extern map<string, int> words(string const& text)
{
    map<string, int> counts;
    for (string word : split_words(to_lower(strip_punctuation(text)))) {
        counts[word]++;
    }
    return counts;
}

}
