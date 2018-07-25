#include "isogram.h"
#include <unordered_set>

bool isogram::is_isogram(std::string word) {
	std::unordered_set<char> letters;
	const std::unordered_set<char> alphabet({'a','b','c','d','e','f','g','h',
		                                           'i','j','k','l','m','n','o','p',
												   'q','r','s','t','u','v','w','x',
		                                           'y','z'});

	for (auto&& ch : word) {
		ch = tolower(ch);

		// character not parsed over
		if (letters.find(ch) == letters.end()) {
			letters.insert(ch);
		}
		// character is a member of the alphabet
		else if (alphabet.find(ch) != alphabet.end()) {
			return false;
		}
	}
	
	return true;
}