#if !defined(GIGASECOND_H)
#define GIGASECOND_H

#include <boost/date_time/gregorian/gregorian.hpp>

namespace gigasecond
{

extern boost::gregorian::date advance(const boost::gregorian::date& start);

}

#endif
