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

int cipher::size() const
{
    int length = 1;
    while (length*length < static_cast<int>(text_.size())) {
        ++length;
    }
    return length; //static_cast<int>(ceil(sqrt(text_.size())));
}

vector<string> cipher::plain_text_segments() const
{
    vector<string> segments;
    const int segment_size{size()};
    for (size_t i = 0; i < text_.length(); i += segment_size) {
        segments.push_back(text_.substr(i, segment_size));
    }
    return segments;
}

string cipher::cipher_text() const
{
    string result;
    const vector<string> segments{plain_text_segments()};
    for (int i = 0, end = size(); i < end; ++i) {
        for (int j = 0, end = static_cast<int>(segments.size()); j < end; ++j) {
            if (i < static_cast<int>(segments[j].length())) {
                result += segments[j].substr(i, 1);
            }
        }
    }
    return result;
}

string cipher::normalized_cipher_text() const
{
    const string encoded{cipher_text()};
    string result;
    for (int i = 0; i < static_cast<int>(encoded.length()); i += 5) {
        if (!result.empty()) {
            result += ' ';
        }
        result += encoded.substr(i, 5);
    }
    return result;
}

}
