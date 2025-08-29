#include "twelve_days.h"
#include <array>
#include <string>

namespace twelve_days {

std::string verse(int day) {
    const std::array<std::string, 13> ordinals = {
        "", "first", "second", "third", "fourth", "fifth", "sixth",
        "seventh", "eighth", "ninth", "tenth", "eleventh", "twelfth"
    };
    
    const std::array<std::string, 13> gifts = {
        "", "a Partridge in a Pear Tree", "two Turtle Doves", "three French Hens",
        "four Calling Birds", "five Gold Rings", "six Geese-a-Laying",
        "seven Swans-a-Swimming", "eight Maids-a-Milking", "nine Ladies Dancing",
        "ten Lords-a-Leaping", "eleven Pipers Piping", "twelve Drummers Drumming"
    };
    
    std::string result = "On the " + ordinals[day] + " day of Christmas my true love gave to me: ";
    
    for (int i = day; i >= 1; --i) {
        if (i == day) {
            result += gifts[i];
        } else if (i == 1) {
            result += ", and ";
            result += gifts[i];
        } else {
            result += ", ";
            result += gifts[i];
        }
    }
    
    result += ".";
    return result;
}

std::string lyrics(int start_day, int end_day) {
    std::string result = "";
    for (int i = start_day; i <= end_day; ++i) {
        if (i > start_day) {
            result += "\n\n";
        }
        result += verse(i);
    }
    return result;
}

std::string lyrics(int end_day) {
    return lyrics(1, end_day);
}

}  // namespace twelve_days
