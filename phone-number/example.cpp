#include <algorithm>
#include <cctype>
#include <iterator>
#include <sstream>
#include "phone_number.h"

using namespace std;

namespace
{

string clean_number(const string& text)
{
    string result;
    copy_if(text.begin(), text.end(), back_inserter(result), isdigit);
    if (result.length() == 11) {
        if (result[0] == '1') {
            result.erase(result.begin());
        } else {
            result.replace(0, result.length(), 10, '0');
        }
    } else if (result.length() == 9) {
        result.replace(0, result.length(), 10, '0');
    }
    return result;
}

}

phone_number::phone_number(const string& text)
    : digits_(clean_number(text))
{
}

string phone_number::area_code() const
{
    return digits_.substr(0, 3);
}

string phone_number::number() const
{
    return digits_;
}

phone_number::operator std::string() const
{
    ostringstream buff;
    buff << '(' << digits_.substr(0, 3) << ") "
        << digits_.substr(3, 3) << '-' << digits_.substr(6);
    return buff.str();
}
