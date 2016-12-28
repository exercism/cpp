#include "bob.h"
#include <boost/algorithm/string/trim.hpp>
#include <algorithm>
#include <cctype>
#include <iterator>

using namespace std;

namespace bob
{
namespace
{

bool is_upper(string const& text)
{
    auto last = end(text);
    auto it = find_if_not(begin(text), last,
        [](char c) { return c == toupper(c); });
    return it == last;
}

bool has_alpha(string const& text)
{
    auto last = end(text);
    auto it = find_if(begin(text), last, [](char c) { return isalpha(c) != 0; });
    return it != last;
}

bool is_shouting(string const &text)
{
    return is_upper(text) && has_alpha(text);
}

bool is_question(string const &text)
{
    return boost::algorithm::trim_copy(text).back() == '?';
}

bool is_silence(string const& text)
{
    return boost::algorithm::trim_copy(text).length() == 0;
}

}

string hey(string const& text)
{
    if (is_silence(text)) {
        return "Fine. Be that way!";
    }
    if (is_shouting(text)) {
        return "Whoa, chill out!";
    }
    if (is_question(text)) {
        return "Sure.";
    }
    return "Whatever.";
}

}
