#ifndef PANGRAM
#define PANGRAM
#include <string>
#include <cctype>
namespace pangram {
    bool foundLetter(char a, std::string s);
   bool isPangram(std::string s);
}
#endif
