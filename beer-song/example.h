#if !defined(BEER_SONG_H)
#define BEER_SONG_H

#include <string>

namespace beer
{

extern std::string verse(unsigned bottles);
extern std::string sing(unsigned begin, unsigned end);
extern std::string sing(unsigned bottles);

}

#endif
