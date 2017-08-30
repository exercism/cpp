#include "gigasecond.h"
#include "boost/date_time/posix_time/posix_time_types.hpp"

namespace gigasecond
{

boost::posix_time::ptime advance(const boost::posix_time::ptime& start)
{
    return start + boost::posix_time::seconds(1e9);
}

}
