#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

namespace grade_school {

class school {
   public:
    const std::map<int, std::vector<std::string>>& roster() const {
        return students_by_grade;
    }

    void add(std::string const& name, int grade);

    std::vector<std::string> grade(int grade) const;

   private:
    std::map<int, std::vector<std::string>> students_by_grade;
    std::set<std::string> students;
};

}  // namespace grade_school
