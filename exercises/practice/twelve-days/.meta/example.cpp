#include <array>
#include <string>

#include "twelve_days.h"

namespace twelve_days {

std::string recite(int start_day, int end_day) {
    constexpr std::array<const char*, 13> ordinals = {
        "",        "first",  "second", "third", "fourth",   "fifth",  "sixth",
        "seventh", "eighth", "ninth",  "tenth", "eleventh", "twelfth"};

    constexpr std::array<const char*, 13> gifts = {"",
                                                   "a Partridge in a Pear Tree",
                                                   "two Turtle Doves",
                                                   "three French Hens",
                                                   "four Calling Birds",
                                                   "five Gold Rings",
                                                   "six Geese-a-Laying",
                                                   "seven Swans-a-Swimming",
                                                   "eight Maids-a-Milking",
                                                   "nine Ladies Dancing",
                                                   "ten Lords-a-Leaping",
                                                   "eleven Pipers Piping",
                                                   "twelve Drummers Drumming"};

    if (start_day == end_day) {
        // Single verse case
        auto result = std::string{"On the "} +
                      std::string{ordinals[start_day]} +
                      " day of Christmas my true love gave to me: ";

        for (int i = start_day; i >= 1; --i) {
            if (i == start_day) {
                result += std::string{gifts[i]};
            } else if (i == 1) {
                result += std::string{", and "} + std::string{gifts[i]};
            } else {
                result += std::string{", "} + std::string{gifts[i]};
            }
        }

        result += ".\n";
        return result;
    } else {
        // Multiple verses case
        std::string result = "";
        for (int i = start_day; i <= end_day; ++i) {
            if (i > start_day) {
                result += "\n";
            }

            auto verse = std::string{"On the "} + std::string{ordinals[i]} +
                         " day of Christmas my true love gave to me: ";

            for (int j = i; j >= 1; --j) {
                if (j == i) {
                    verse += std::string{gifts[j]};
                } else if (j == 1) {
                    verse += std::string{", and "} + std::string{gifts[j]};
                } else {
                    verse += std::string{", "} + std::string{gifts[j]};
                }
            }

            verse += ".\n";
            result += verse;
        }
        return result;
    }
}

}  // namespace twelve_days
