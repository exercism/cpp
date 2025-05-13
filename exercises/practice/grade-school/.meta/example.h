#pragma once

#include <map>
#include <string>
#include <vector>

namespace grade_school {

class school {
   public:
    const std::map<int, std::vector<std::string>>& roster() const {
        return roster_;
    }

    void add(std::string const& name, int grade);

    std::vector<std::string> grade(int grade) const;

   private:
    std::map<int, std::vector<std::string>> roster_;
};

}  // namespace grade_school
