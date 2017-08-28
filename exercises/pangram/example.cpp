#include "example.h"

bool pangram::foundLetter(char a, std::string s) {
    for(auto c: s) {
        if(tolower(c) ==a) {
            return true;
        }
    }
    return false;
}
bool pangram::isPangram(std::string s) {
    char letters[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    for(char l : letters) {
        if(!foundLetter(l, s)) {
            return false;
        }
    }
    return true;
}
