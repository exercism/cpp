#include "baffling_birthdays.h"

#include <unordered_set>
#include <random>
#include <chrono>
#include <sstream>
#include <iomanip>

namespace baffling_birthdays {

    bool shared_birthday(const std::vector<std::string>& birthdates) {
        std::unordered_set<std::string> seen;
        for (auto const& date : birthdates) {
            if (date.size() < 10) continue;
            std::string month_day = date.substr(5, 2) + "-" + date.substr(8, 2);
            if (seen.count(month_day)) {
                return true;
            }
            seen.insert(month_day);
        }
        return false;
    }

    std::vector<std::string> random_birthdates(std::size_t group_size) {
        static std::mt19937_64 gen(
            std::chrono::system_clock::now().time_since_epoch().count());
        std::uniform_int_distribution<int> month_dist(1, 12);
        const int days_in_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

        std::vector<std::string> dates;
        dates.reserve(group_size);
        for (std::size_t i = 0; i < group_size; ++i) {
            int month = month_dist(gen);
            std::uniform_int_distribution<int> day_dist(1, days_in_month[month-1]);
            int day = day_dist(gen);
            int year = 2001;
            std::ostringstream oss;
            oss << year << "-" << std::setw(2) << std::setfill('0') << month
                << "-" << std::setw(2) << std::setfill('0') << day;
            dates.push_back(oss.str());
        }
        return dates;
    }

    double estimated_probability_of_shared_birthday(std::size_t group_size) {
        if (group_size <= 1) return 0.0;
        if (group_size > 365) return 100.0;
        double unique_prob = 1.0;
        for (std::size_t i = 0; i < group_size; ++i) {
            unique_prob *= (365.0 - static_cast<double>(i)) / 365.0;
        }
        double shared_prob = (1.0 - unique_prob) * 100.0;
        return shared_prob;
    }

}  // namespace baffling_birthdays