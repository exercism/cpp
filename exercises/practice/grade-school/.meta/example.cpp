#include "grade_school.h"

namespace grade_school {
    void school::add(std::string const& name, int grade) {
        // Check if the student already exists
        if (students_.find(name) != students_.end())
        {
            // Student already exists; do not add
            return;
        }
        // Add the student to the set of students
        students_.insert(name);
        // Proceed to add the student to the given grade in sorted order
        std::vector<std::string>& grade_roster = roster_[grade];
        auto it = lower_bound(grade_roster.begin(), grade_roster.end(), name);
        grade_roster.insert(it, name);
    }

    std::vector<std::string> school::grade(int grade) const
    {
        auto it = roster_.find(grade);
        return (it != roster_.end()) ? it->second : std::vector<std::string>{};
    }


}  // namespace grade_school

