#include <sstream>

#include "beer_song.h"

using namespace std;

namespace beer_song {

namespace {

struct bottles {
    bottles(unsigned num) : count(num), suffix(num > 1 ? "s" : "") {}
    unsigned const count;
    string const suffix;
};

ostream& operator<<(ostream& stream, bottles const& b) {
    if (b.count) {
        stream << b.count << " bottle" << b.suffix;
    } else {
        stream << "no more bottles";
    }
    return stream << " of beer";
}

void bottles_of_beer_on_the_wall(ostream& stream, unsigned count) {
    if (count) {
        stream << bottles(count) << " on the wall, " << bottles(count) << ".\n";
    } else {
        stream << "No more bottles of beer on the wall, " << bottles(count)
               << ".\n";
    }
}

void take_one_down_and_pass_it_around(ostream& stream, unsigned count) {
    if (count > 1) {
        stream << "Take one down and pass it around, " << bottles(count - 1)
               << " on the wall.\n";
    } else if (count) {
        stream << "Take it down and pass it around, " << bottles(count - 1)
               << " on the wall.\n";
    } else {
        stream << "Go to the store and buy some more, 99 bottles of beer on "
                  "the wall.\n";
    }
}

void verse(ostream& stream, unsigned count) {
    bottles_of_beer_on_the_wall(stream, count);
    take_one_down_and_pass_it_around(stream, count);
}

}  // namespace

string verse(unsigned num) {
    ostringstream stream;
    verse(stream, num);
    return stream.str();
}

string sing(unsigned begin, unsigned end) {
    ostringstream stream;
    for (unsigned num = begin; num > end; --num) {
        verse(stream, num);
        stream << '\n';
    }
    verse(stream, end);
    return stream.str();
}

string sing(unsigned num) { return sing(num, 0); }

}  // namespace beer_song
