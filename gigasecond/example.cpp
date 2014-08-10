#include "gigasecond.h"

namespace gigasecond
{

boost::gregorian::date advance(const boost::gregorian::date& start)
{
    const unsigned long long seconds_per_minute = 60;
    const unsigned long long seconds_per_hour = 60*seconds_per_minute;
    const unsigned long long seconds_per_day = 24*seconds_per_hour;
    const unsigned long long one_giga_second = 1000000000;
    return start + boost::gregorian::days(one_giga_second/seconds_per_day);
}

}
