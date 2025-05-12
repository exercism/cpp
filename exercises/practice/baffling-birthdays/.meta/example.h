#pragma once

#include <vector>
#include <string>

namespace baffling_birthdays {

    bool shared_birthday(const std::vector<std::string>& birthdates);

    std::vector<std::string> random_birthdates(std::size_t group_size);

    double estimated_probability_of_shared_birthday(std::size_t group_size);

}  // namespace baffling_birthdays