#include "crypto_square.h"
#include <algorithm>
#include <cctype>
#include <iterator>

using namespace std;

namespace
{

string to_lower_copy(string const& s)
{
    string cpy(s);
    for (auto& c: cpy) {
        c = tolower(c);
    }
    return cpy;
}

string normalize(string const& text)
{
    string result;
    copy_if(text.begin(), text.end(), back_inserter(result),
        [](const char c) { return !isspace(c) && !ispunct(c); });
    return to_lower_copy(result);
}

}

namespace crypto_square
{

cipher::cipher(string const& text)
    : text_(normalize(text))
{
}

string cipher::normalize_plain_text() const
{
    return text_;
}

size_t cipher::size() const
{
    size_t length = 0;
    while (length*length < text_.size()) {
        ++length;
    }
    return length;
}

vector<string> cipher::plain_text_segments() const
{
    vector<string> segments;
    const size_t segment_size{size()};
    for (size_t i = 0; i < text_.length(); i += segment_size) {
        segments.push_back(text_.substr(i, segment_size));
    }
    return segments;
}

string cipher::cipher_text() const
{
    string s{normalized_cipher_text()};
    if (!s.empty()) {
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
    }
    return s;
}

string cipher::normalized_cipher_text() const
{
    const auto num_rows = size();
    const auto plain = plain_text_segments();
    string result;
    for (size_t i = 0; i < num_rows; ++i) {
        for (string const& s : plain) {
            if (s.length() > i) {
                result += s[i];
            }
            else {
                result += ' ';
            }
        }
        result += ' ';
    }
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

}
