#include "clock.h"

#include <iomanip>
#include <sstream>

using namespace std;

namespace date_independent
{

clock& clock::plus(int minutes)
{
    minute_ += minutes;
    if (minute_ > 60) {
        hour_ += (minute_/60);
        hour_ %= 24;
        minute_ %= 60;
    }
    return *this;
}

clock& clock::minus(int minutes)
{
    minute_ -= minutes;
    while (minute_ < 0) {
        --hour_;
        minute_ += 60;
    }
    while (hour_ < 0) {
        hour_ += 24;
    }
    return *this;
}

clock::operator string() const
{
    ostringstream str;
    str << setw(2) << setfill('0') << hour_ << ':' << setw(2) << setfill('0') << minute_;
    return str.str();
}

clock::clock(int hour, int minute)
    : hour_(hour),
    minute_(minute)
{
}

clock clock::at(int hour, int minute /*= 0*/)
{
    return clock(hour, minute);
}

bool clock::operator==(const clock& rhs) const
{
    return hour_ == rhs.hour_
        && minute_ == rhs.minute_;
}

}
