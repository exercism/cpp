#include "bob.h"
#include <algorithm>
#include <cctype>
#include <iterator>

using namespace std;

namespace bob
{
namespace
{

const char upper_case_a_umlaut = '\xc4';
const char upper_case_u_umlaut = '\xdc';

bool is_upper(string const& text)
{
    auto last = end(text);
    auto it = find_if_not(begin(text), last, [](char c) {
        if (c < 0 || c > 127) {
            return c == upper_case_a_umlaut
                || c == upper_case_u_umlaut;
        }
        return c == toupper(c);
    });
    return it == last;
}

bool has_alpha(string const& text)
{
    auto last = end(text);
    auto it = find_if(begin(text), last, [](char c) { return c < 0 || c > 127 || isalpha(c); });
    return it != last;
}

string trim(string const& text)
{
    auto first = text.find_first_not_of(' ');
    if (first == string::npos) {
        return string();
    }
    auto last = text.find_last_not_of(' ');
    return string(&text[first], &text[last]);
}

bool is_shouting(string const &text)
{
    return is_upper(text) && has_alpha(text);
}

bool is_question(string const &text)
{
    return text.back() == '?';
}

bool is_silence(string const& text)
{
    return trim(text).length() == 0;
}

}

string hey(string const& text)
{
    if (is_silence(text)) {
        return "Fine. Be that way!";
    }
    if (is_shouting(text)) {
        return "Woah, chill out!";
    }
    if (is_question(text)) {
        return "Sure.";
    }
    return "Whatever.";
}

}
