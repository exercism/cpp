#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    std::vector<int> rounded{};
    for (int i{}; i < student_scores.size(); ++i)
        rounded.emplace_back(student_scores.at(i));
    return rounded;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    int counter{};
    for (int i{}; i < student_scores.size(); ++i) {
        if (student_scores.at(i) < 41) ++counter;
    }
    return counter;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    std::array<int, 4> grades{};
    for (int i{}, lower_threshold{41}, step_size{(highest_score - 40) / 4};
         i < 4; ++i) {
        grades.at(i) = lower_threshold + step_size * i;
    }
    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    std::vector<std::string> ranking{};
    for (int i{}; i < student_scores.size(); ++i) {
        ranking.emplace_back(std::to_string(i + 1) + ". " +
                             student_names.at(i) + ": " +
                             std::to_string(student_scores.at(i)));
    }

    return ranking;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    std::vector<std::string> ranking{};
    for (int i{}; i < student_scores.size(); ++i) {
        if (student_scores.at(i) == 100) return student_names.at(i);
    }

    return "";
}
