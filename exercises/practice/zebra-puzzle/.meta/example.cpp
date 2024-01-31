#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "zebra_puzzle.h"
using namespace std;
#define TOTAL_HOUSES 5

enum Nationality {
    NAT_NONE,
    ENGLISHMAN,
    SPANIARD,
    UKRAINIAN,
    NORWEGIAN,
    JAPANESE
};

map<Nationality, std::string> nationalityStrings = {
    {NAT_NONE, "None"},       {ENGLISHMAN, "Englishman"},
    {SPANIARD, "Spaniard"},   {UKRAINIAN, "Ukrainian"},
    {NORWEGIAN, "Norwegian"}, {JAPANESE, "Japanese"}};

enum Color { COLOR_NONE, RED, GREEN, IVORY, YELLOW, BLUE };
enum Pet { PET_NONE, DOG, SNAILS, FOX, HORSE, ZEBRA };
enum Drink { DRINK_NONE, TEA, COFFEE, MILK, ORANGE_JUICE, WATER };
enum Cigarette {
    CIG_NONE,
    OLD_GOLD,
    KOOLS,
    CHESTERFIELDS,
    LUCKY_STRIKE,
    PARLIAMENTS
};

struct House {
    Nationality nationality;
    Color color;
    Pet pet;
    Drink drink;
    Cigarette cigarette;
};

namespace zebra_puzzle {

// This function is for finding the remaining possibilities
vector<int> find_remaining(vector<House>& houses, const string& prop1,
                           const string& prop2) {
    vector<int> ans;
    if (prop1 == "nationality" && prop2 == "pet") {
        for (int i = 0; i < TOTAL_HOUSES; i++) {
            if (houses[i].nationality == NAT_NONE && houses[i].pet == PET_NONE)
                ans.push_back(i);
        }
    } else if (prop1 == "nationality" && prop2 == "drink") {
        for (int i = 0; i < TOTAL_HOUSES; i++) {
            if (houses[i].nationality == NAT_NONE &&
                houses[i].drink == DRINK_NONE)
                ans.push_back(i);
        }
    } else if (prop1 == "nationality" && prop2 == "cigarette") {
        for (int i = 0; i < TOTAL_HOUSES; i++) {
            if (houses[i].nationality == NAT_NONE &&
                houses[i].cigarette == CIG_NONE)
                ans.push_back(i);
        }
    } else if (prop1 == "cigarette" && prop2 == "drink") {
        for (int i = 0; i < TOTAL_HOUSES; i++) {
            if (houses[i].cigarette == CIG_NONE &&
                houses[i].drink == DRINK_NONE)
                ans.push_back(i);
        }
    } else if (prop1 == "cigarette" && prop2 == "pet") {
        for (int i = 0; i < TOTAL_HOUSES; i++) {
            if (houses[i].cigarette == CIG_NONE && houses[i].pet == PET_NONE)
                ans.push_back(i);
        }
    }
    return ans;
}

// The Lucky Strike smoker drinks orange juice
bool luckyStrike_orangeJuice(vector<House>& houses) {
    vector<int> remains = find_remaining(houses, "cigarette", "drink");

    for (auto i : remains) {
        houses[i].drink = ORANGE_JUICE;
        houses[i].cigarette = LUCKY_STRIKE;
        return true;
        houses[i].drink = DRINK_NONE;
        houses[i].cigarette = CIG_NONE;
    }

    return false;
}

// The Old Gold smoker owns snails
bool oldGold_snails(vector<House>& houses) {
    vector<int> remains = find_remaining(houses, "cigarette", "pet");

    for (auto i : remains) {
        houses[i].pet = SNAILS;
        houses[i].cigarette = OLD_GOLD;
        if (luckyStrike_orangeJuice(houses)) return true;
        houses[i].pet = PET_NONE;
        houses[i].cigarette = CIG_NONE;
    }

    return false;
}

// The man who smokes Chesterfields lives in the house next to the man with the fox
bool chesterfields_fox(vector<House>& houses) {
    for (int i = 0; i < TOTAL_HOUSES; i++) {
        if (houses[i].cigarette == CIG_NONE) {
            if (i == 0) {
                if (houses[i + 1].pet == PET_NONE) {
                    houses[i].cigarette = CHESTERFIELDS;
                    houses[i + 1].pet = FOX;
                    if (oldGold_snails(houses)) return true;
                    houses[i].cigarette = CIG_NONE;
                    houses[i + 1].pet = PET_NONE;
                }
            } else if (i == TOTAL_HOUSES - 1) {
                if (houses[i - 1].pet == PET_NONE) {
                    houses[i].cigarette = CHESTERFIELDS;
                    houses[i - 1].pet = FOX;
                    if (oldGold_snails(houses)) return true;
                    houses[i].cigarette = CIG_NONE;
                    houses[i - 1].pet = PET_NONE;
                }
            } else {
                if (houses[i - 1].pet == PET_NONE) {
                    houses[i].cigarette = CHESTERFIELDS;
                    houses[i - 1].pet = FOX;
                    if (oldGold_snails(houses)) return true;
                    houses[i].cigarette = CIG_NONE;
                    houses[i - 1].pet = PET_NONE;
                }
                if (houses[i + 1].pet == PET_NONE) {
                    houses[i].cigarette = CHESTERFIELDS;
                    houses[i + 1].pet = FOX;
                    if (oldGold_snails(houses)) return true;
                    houses[i].cigarette = CIG_NONE;
                    houses[i + 1].pet = PET_NONE;
                }
            }
        }
    }

    return false;
}

// The Japanese smokes Parliaments
bool japanese_parliaments(vector<House>& houses) {
    vector<int> remains = find_remaining(houses, "nationality", "cigarette");

    for (auto i : remains) {
        houses[i].nationality = JAPANESE;
        houses[i].cigarette = PARLIAMENTS;
        if (chesterfields_fox(houses)) return true;
        houses[i].nationality = NAT_NONE;
        houses[i].cigarette = CIG_NONE;
    }

    return false;
}

// The Ukrainian drinks tea
bool ukrainian_tea(vector<House>& houses) {
    vector<int> remains = find_remaining(houses, "nationality", "drink");

    for (auto i : remains) {
        houses[i].nationality = UKRAINIAN;
        houses[i].drink = TEA;
        if (japanese_parliaments(houses)) return true;
        houses[i].nationality = NAT_NONE;
        houses[i].drink = DRINK_NONE;
    }

    return false;
}

// The Spaniard owns the dog
bool spaniard_dog(vector<House>& houses) {
    vector<int> remains = find_remaining(houses, "nationality", "pet");

    for (auto i : remains) {
        houses[i].nationality = SPANIARD;
        houses[i].pet = DOG;
        if (ukrainian_tea(houses)) return true;
        houses[i].nationality = NAT_NONE;
        houses[i].pet = PET_NONE;
    }

    return false;
}

bool colorsConditions(vector<House>& houses) {
    // At this point we have three left houses(2,3,4) and three left colors(red,
    // gree, ivory) We know that gree is next to ivory so there is two
    // possibilities

    // i. red, ivory, green
    houses[2].color = RED;
    // Englishman lives in the red house so
    houses[2].nationality = ENGLISHMAN;
    // so other two become like
    houses[3].color = IVORY;
    houses[4].color = GREEN;
    // Coffee is drunk in the green house
    houses[4].drink = COFFEE;

    if (spaniard_dog(houses)) return true;

    houses[2].color = COLOR_NONE;
    houses[2].nationality = NAT_NONE;
    houses[3].color = COLOR_NONE;
    houses[4].color = COLOR_NONE;
    houses[4].drink = DRINK_NONE;

    // ii. ivory, green, red
    houses[4].color = RED;
    houses[4].nationality = ENGLISHMAN;
    houses[2].color = IVORY;
    houses[3].color = GREEN;
    houses[3].drink = COFFEE;

    if (spaniard_dog(houses)) return true;

    houses[4].color = COLOR_NONE;
    houses[4].nationality = NAT_NONE;
    houses[2].color = COLOR_NONE;
    houses[3].color = COLOR_NONE;
    houses[3].drink = DRINK_NONE;

    return false;
}

// This function is for filling up matrix with default conditions
// Means there is no possibilities of the multiple cases
bool defaultConditions(vector<House>& houses) {
    // Norwegian lives in the first houses
    houses[0].nationality = NORWEGIAN;

    // Milk is drunk in the middle house
    houses[2].drink = MILK;

    // Norwegian lives next to the blue house
    houses[1].color = BLUE;

    // Green house is immediately to the right of the ivory house
    // So the place where ivory and gree can be are 2-3 or 3-4
    // And Englishman lives in the red house
    // which leave only yellow house so first house color is yellow
    houses[0].color = YELLOW;

    // Kools are smoked in the yellow house
    houses[0].cigarette = KOOLS;

    // Horse is next to Kools
    houses[1].pet = HORSE;

    // Check all the color related conditions
    bool flag = colorsConditions(houses);
    return flag;
}

bool solveZebraPuzzle(vector<House>& houses) {
    bool flag = defaultConditions(houses);
    return flag;
}
std::string zebra_puzzle::drinks_water() const {
    vector<House> houses(TOTAL_HOUSES);

    bool flag = solveZebraPuzzle(houses);

    if (!flag) throw std::domain_error("No solution found");

    string nationality = "";
    for (House h : houses) {
        if (h.drink == DRINK_NONE) {
            h.drink = WATER;
            nationality = nationalityStrings.at(h.nationality);
        }
    }

    if (nationality.length() == 0) throw std::domain_error("No solution found");
    return nationality;
}

std::string zebra_puzzle::who_owns_zebra() const {
    vector<House> houses(TOTAL_HOUSES);

    bool flag = solveZebraPuzzle(houses);

    if (!flag) throw std::domain_error("No solution found");

    string nationality = "";
    for (House h : houses) {
        if (h.pet == PET_NONE) {
            h.pet = ZEBRA;
            nationality = nationalityStrings.at(h.nationality);
        }
    }

    if (nationality.length() == 0) throw std::domain_error("No solution found");
    return nationality;
}

}  // namespace zebra_puzzle
