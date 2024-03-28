#if !defined(ZEBRA_PUZZLE_H)
#define ZEBRA_PUZZLE_H

#include <string>

namespace zebra_puzzle 
{

typedef struct 
{
    std::string drinksWater;
    std::string ownsZebra;
} Solution;

Solution solve();

}  // namespace zebra_puzzle

#endif
