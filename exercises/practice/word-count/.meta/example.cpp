#include <algorithm>
#include <cctype>
#include <iterator>
#include <vector>

#include "word_count.h"

using namespace std;

namespace {

string trim_copy_if(string const& s, string const& delims) {
    string cpy(s);
    // Trim front
    while (!cpy.empty() && delims.find(cpy.front()) != string::npos)
        cpy.erase(cpy.begin());
    // Trim back
    while (!cpy.empty() && delims.find(cpy.back()) != string::npos)
        cpy.pop_back();
    return cpy;
}

vector<string> split(string const& s, string const& delims) {
    auto start = s.begin();
    vector<string> words;
    for (auto end = s.begin(); end != s.end(); end++) {
        if (delims.find(*end) != string::npos) {
            if (start != end) {
                words.push_back(s.substr(start - s.begin(), end - start));
            }
            start = end + 1;
        }
    }
    if (start < s.end()) {
        words.push_back(s.substr(start - s.begin(), s.end() - start));
    }
    return words;
}

string normalize_text(string const& text) {
    string normalized;
    transform(text.begin(), text.end(), back_inserter(normalized),
              [](const char c) {
                  return (isalnum(c) || c == '\'') ? tolower(c) : ' ';
              });
    return normalized;
}

string trim_word(string const& word) { return trim_copy_if(word, "' "); }

vector<string> split_text_into_words(string const& text) {
    vector<string> words = split(text, "\t ");
    transform(words.begin(), words.end(), words.begin(), trim_word);
    return words;
}

}  // namespace

namespace word_count {

map<string, int> words(string const& text) {
    map<string, int> count;
    for (auto const& word : split_text_into_words(normalize_text(text))) {
        if (!word.empty()) {
            ++count[word];
        }
    }
    return count;
}

}  // namespace word_count
