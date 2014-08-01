#include "grains.h"

namespace grains
{

unsigned long long grains::square(int which) const
{
    return 1ULL << (which-1);
}

unsigned long long grains::total() const
{
    unsigned long long result = 0;
    for (int i = 1; i <= 64; ++i) {
        result += square(i);
    }
    return result;
}

}
