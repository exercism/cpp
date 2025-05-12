#pragma once

#include <string>
#include <vector>

namespace anagram {

class anagram {
   public:
    anagram(std::string const& subject);

    std::vector<std::string> matches(std::vector<std::string> const& matches);

   private:
    std::string const subject_;
    std::string const key_;
};

}  // namespace anagram
