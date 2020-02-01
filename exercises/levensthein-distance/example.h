#if !defined(LEVENSTHEIN_DISTANCE)
#define LEVENSTHEIN_DISTANCE

#include <string>

namespace levensthein {

	int distance(const std::string& source, const std::string& target);

}

#endif // LEVENSTHEIN_DISTANCE