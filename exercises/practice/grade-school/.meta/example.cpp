#include <algorithm>

#include "grade_school.h"

namespace grade_school {

void school::add(std::string const& name, int grade) {
    if (students.find(name) != students.end()) {
        return;
    }

    students.insert(name);

    std::vector<std::string>& grade_roster = students_by_grade[grade];
    auto it = std::lower_bound(grade_roster.begin(), grade_roster.end(), name);
    grade_roster.insert(it, name);
}

std::vector<std::string> school::grade(int grade) const {
    auto it = students_by_grade.find(grade);
    return (it != students_by_grade.end()) ? it->second
                                           : std::vector<std::string>{};
}

}  // namespace grade_school
