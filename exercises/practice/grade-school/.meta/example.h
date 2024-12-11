#include <map>
#include <set>
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
    std::set<std::string> students_;  // New member to track existing students
};

}  // namespace grade_school
