#pragma once

#include <iomanip>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

namespace baffling_birthdays {

struct Date {
    int year;
    int month;
    int day;
};

Date parse_date(const std::string& iso);

std::string to_string(const Date& d);

bool shared_birthday(const std::vector<Date>& dates);
std::vector<Date> random_birthdates_dates(std::size_t group_size);

double estimated_probability_of_shared_birthday(std::size_t group_size);

inline bool shared_birthday(const std::vector<std::string>& birthdates) {
    std::vector<Date> dates;
    dates.reserve(birthdates.size());
    for (auto const& s : birthdates) {
        dates.push_back(parse_date(s));
    }
    return shared_birthday(dates);
}

inline std::vector<std::string> random_birthdates(std::size_t group_size) {
    auto dates = random_birthdates_dates(group_size);
    std::vector<std::string> out;
    out.reserve(group_size);
    for (auto const& d : dates) out.push_back(to_string(d));
    return out;
}

}  // namespace baffling_birthdays