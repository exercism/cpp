#include <chrono>
#include <random>

#include "baffling_birthdays.h"

namespace baffling_birthdays {

Date parse_date(const std::string& iso) {
    Date d{0, 0, 0};
    if (iso.size() < 10) return d;
    try {
        d.year = std::stoi(iso.substr(0, 4));
        d.month = std::stoi(iso.substr(5, 2));
        d.day = std::stoi(iso.substr(8, 2));
    } catch (...) {
        d = {0, 0, 0};
    }
    return d;
}

std::string to_string(const Date& d) {
    std::ostringstream oss;
    oss << std::setw(4) << std::setfill('0') << d.year << '-' << std::setw(2)
        << std::setfill('0') << d.month << '-' << std::setw(2)
        << std::setfill('0') << d.day;
    return oss.str();
}

bool shared_birthday(const std::vector<Date>& dates) {
    std::unordered_set<int> seen_md;
    seen_md.reserve(dates.size());
    for (auto const& d : dates) {
        if (d.month < 1 || d.month > 12 || d.day < 1 || d.day > 31) continue;
        int key = d.month * 100 + d.day;
        if (seen_md.count(key)) return true;
        seen_md.insert(key);
    }
    return false;
}

std::vector<Date> random_birthdates_dates(std::size_t group_size) {
    static std::mt19937_64 gen(
        std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> month_dist(1, 12);
    const int days_in_month[12] = {31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};
    std::vector<Date> dates;
    dates.reserve(group_size);
    for (std::size_t i = 0; i < group_size; ++i) {
        int m = month_dist(gen);
        std::uniform_int_distribution<int> day_dist(1, days_in_month[m - 1]);
        dates.push_back(Date{2001, m, day_dist(gen)});
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
    return (1.0 - unique_prob) * 100.0;
}

}  // namespace baffling_birthdays