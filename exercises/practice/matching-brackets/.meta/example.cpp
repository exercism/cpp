#include <stack>

#include "matching_brackets.h"

using namespace std;

namespace matching_brackets {

bool check(string const& expression) {
    const string open("({[");
    const string close(")}]");
    stack<char> st;
    for (const char c : expression) {
        if (open.find(c) != string::npos) {
            st.push(c);
        } else if (close.find(c) != string::npos) {
            if (st.empty() || st.top() != open[close.find(c)]) {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

}  // namespace matching_brackets
