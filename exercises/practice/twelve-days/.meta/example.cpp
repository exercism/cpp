#include <array>
#include <string>

#include "twelve_days.h"

namespace twelve_days {

namespace {
std::string verse(int day) {
    constexpr std::array ordinals = {
        "",        "first",  "second", "third", "fourth",   "fifth",  "sixth",
        "seventh", "eighth", "ninth",  "tenth", "eleventh", "twelfth"};

    constexpr std::array gifts = {"",
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

    auto result = std::string{"On the "} + ordinals[day] +
                  " day of Christmas my true love gave to me: " + gifts[day];

    for (int i = day - 1; i >= 1; --i) {
        if (i == 1) {
            result += std::string{", and "};
        } else {
            result += std::string{", "};
        }
        result += gifts[i];
    }

    return result + ".\n";
}
}  // namespace

std::string recite(int start_day, int end_day) {
    std::string result{};
    for (int i = start_day; i <= end_day; ++i) {
        if (i > start_day) {
            result += '\n';
        }
        result += verse(i);
    }
    return result;
}

}  // namespace twelve_days
