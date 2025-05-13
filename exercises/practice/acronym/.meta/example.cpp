#include <cctype>

#include "acronym.h"

using std::string;

namespace acronym {

string acronym(string const &input_str) {
    string acronym_str;
    string delimiters = " :-,_";
    enum DelimiterState { NOT_FOUND, FOUND };
    DelimiterState delimiter_state = FOUND;
    for (char c : input_str) {
        if (delimiters.find(c) != string::npos) {
            delimiter_state = FOUND;
        } else if (delimiter_state == FOUND) {
            delimiter_state = NOT_FOUND;
            acronym_str.push_back(std::toupper(c));
        }
    }
    return acronym_str;
}

}  // namespace acronym
