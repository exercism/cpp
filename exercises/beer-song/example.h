#if !defined(BEER_SONG_H)
#define BEER_SONG_H

#include <string>

namespace beer_song
{

std::string verse(unsigned bottles);
std::string sing(unsigned begin, unsigned end);
std::string sing(unsigned bottles);

}

#endif
