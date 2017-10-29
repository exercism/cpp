#include "gigasecond.h"
#include <ctime>

using namespace std;

namespace {

// Convert string to time
time_t time_from_string(string const& s)
{
    // Convert string to date
    struct tm date;
    sscanf(s.c_str(), "%4d-%2d-%2d %2d:%2d:%2d",
                        &date.tm_year, &date.tm_mon, &date.tm_mday,
                        &date.tm_hour, &date.tm_min, &date.tm_sec);
    date.tm_year -= 1900;
    date.tm_mon -= 1;
    date.tm_isdst = 0; // Ignore daylight savings time
    return mktime(&date);
}

// Convert time to string
string string_from_time(time_t const& t)
{
    // Allocate enough space in the string object for the formatted date
    // At least 20 chars
    string end;
    end.resize(25);

    size_t len = strftime(&end[0], end.size(), "%F %T", localtime(&t));
    end.resize(len); // Resize down to the actual written length

    return end;
}

}

namespace gigasecond
{

string advance(const string& start)
{
    return string_from_time(time_from_string(start) + 1e9);
}

}
