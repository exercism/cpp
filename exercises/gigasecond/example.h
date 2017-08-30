#if !defined(GIGASECOND_H)
#define GIGASECOND_H

namespace boost{ namespace posix_time{
class ptime;
} }

namespace gigasecond
{

boost::posix_time::ptime advance(const boost::posix_time::ptime& start);

}

#endif
