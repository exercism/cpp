#include "crypto_square.h"
#include <boost/algorithm/string/case_conv.hpp>
#include <algorithm>
#include <cctype>
#include <iterator>

using namespace std;

namespace
{

string normalize(string const &text)
{
    string result;
    copy_if(text.begin(), text.end(), back_inserter(result),
        [](const char c) { return !isspace(c) && !ispunct(c); });
    return boost::to_lower_copy(result);
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
    size_t length = 1;
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
    string result;
    const vector<string> segments{plain_text_segments()};
    const size_t rows{size()};
    const size_t num_segments{segments.size()};
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < num_segments; ++j) {
            if (i < segments[j].length()) {
                result += segments[j][i];
            }
        }
    }
    return result;
}

string cipher::normalized_cipher_text() const
{
    const string encoded{cipher_text()};
    const auto num_rows = size();
    string result{encoded.substr(0, num_rows)};
    for (auto i = num_rows; i < encoded.length(); i += num_rows) {
        result += ' ' + encoded.substr(i, num_rows);
    }
    return result;
}

}
