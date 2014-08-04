#include "grains.h"

namespace grains
{

extern unsigned long long square(int which)
{
    return 1ULL << (which-1);
}

extern unsigned long long total()
{
    unsigned long long result = 0;
    for (int i = 1; i <= 64; ++i) {
        result += square(i);
    }
    return result;
}

}
