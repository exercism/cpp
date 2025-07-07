#include <random>
#include <unordered_set>

#include "baffling_birthdays.h"

namespace baffling_birthdays {

Date parse_date(const std::string& iso) {
    try {
        return boost::gregorian::from_simple_string(iso);
    } catch (...) {
        return Date(boost::gregorian::not_a_date_time);
    }
}

bool shared_birthday(const std::vector<Date>& dates) {
    std::unordered_set<unsigned> seen_md;
    seen_md.reserve(dates.size());
    for (auto const& d : dates) {
        if (d.is_not_a_date()) continue;
        unsigned key = d.month().as_number() * 100 + d.day();
        if (seen_md.count(key)) return true;
        seen_md.insert(key);
    }
    return false;
}

std::vector<Date> random_birthdates(std::size_t group_size) {
    static std::mt19937_64 gen(
        static_cast<unsigned long>(std::random_device{}()));
    std::uniform_int_distribution<int> month_dist(1, 12);
    const int days_in_month[12] = {31, 28, 31, 30, 31, 30,
                                   31, 31, 30, 31, 30, 31};
    std::vector<Date> dates;
    dates.reserve(group_size);
    for (std::size_t i = 0; i < group_size; ++i) {
        int m = month_dist(gen);
        std::uniform_int_distribution<int> day_dist(1, days_in_month[m - 1]);
        int d = day_dist(gen);
        dates.push_back(Date(2001, m, d));
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