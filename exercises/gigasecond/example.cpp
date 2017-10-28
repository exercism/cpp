#include "gigasecond.h"

namespace gigasecond
{

std::time_t advance(const std::time_t& start)
{
    return start + 1e9;
}

}
