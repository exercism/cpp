#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

#include "zebra_puzzle.h"

using namespace std;

namespace zebra_puzzle {
enum Color { Red, Green, Ivory, Yellow, Blue };
enum Nationality { Englishman, Spaniard, Ukrainian, Norwegian, Japanese };
enum Pet { Dog, Snails, Fox, Horse, Zebra };
enum Drink { Tea, Coffee, Milk, OrangeJuice, Water };
enum Cigarette { OldGold, Kools, Chesterfields, LuckyStrike, Parliaments };
map<Nationality, string> nationalityStrings = {{Englishman, "Englishman"},
                                               {Spaniard, "Spaniard"},
                                               {Ukrainian, "Ukrainian"},
                                               {Norwegian, "Norwegian"},
                                               {Japanese, "Japanese"}};

map<Pet, string> petStrings = {{Dog, "Dog"},
                               {Snails, "Snails"},
                               {Fox, "Fox"},
                               {Horse, "Horse"},
                               {Zebra, "Zebra"}};
map<Drink, string> drinkStrings = {{Tea, "Tea"},
                                   {Coffee, "Coffee"},
                                   {Milk, "Milk"},
                                   {OrangeJuice, "OrangeJuice"},
                                   {Water, "Water"}};
map<Cigarette, string> cigaretteStrings = {{OldGold, "OldGold"},
                                           {Kools, "Kools"},
                                           {Chesterfields, "Chesterfields"},
                                           {LuckyStrike, "LuckyStrike"},
                                           {Parliaments, "Parliaments"}};
map<Color, string> colorStrings = {{Red, "Red"},
                                   {Green, "Green"},
                                   {Ivory, "Ivory"},
                                   {Yellow, "Yellow"},
                                   {Blue, "Blue"}};

struct House {
    Color color;
    Nationality nationality;
    Pet pet;
    Drink drink;
    Cigarette cigarette;
};

vector<House> houses(5);

bool isSolution() {
    // Iterate through houses to check conditions
    for (size_t i = 0; i < houses.size(); ++i) {
        const auto& house = houses[i];

        // Condition 1: The Englishman lives in the red house
        if (house.nationality == Englishman && house.color != Red) {
            return false;
        }

        // Condition 2: The Spaniard owns the dog
        if (house.nationality == Spaniard && house.pet != Dog) {
            return false;
        }

        // Condition 3: Coffee is drunk in the green house
        if (house.drink == Coffee && house.color != Green) {
            return false;
        }

        // Condition 4: The Ukrainian drinks tea
        if (house.nationality == Ukrainian && house.drink != Tea) {
            return false;
        }

        // Condition 5: The green house is immediately to the right of the ivory house
        if (i < 4 && house.color == Green && houses[i - 1].color != Ivory) {
            return false;
        }

        // Condition 6: The Old Gold smoker owns snails
        if (house.cigarette == OldGold && house.pet != Snails) {
            return false;
        }

        // Condition 7: Kools are smoked in the yellow house
        if (house.cigarette == Kools && house.color != Yellow) {
            return false;
        }

        // Condition 8: Milk is drunk in the middle house
        if (i == 2 && house.drink != Milk) {
            return false;
        }

        // Condition 9: The Norwegian lives in the first house
        if (i == 0 && house.nationality != Norwegian) {
            return false;
        }

        // Condition 10: The man who smokes Chesterfields lives in the house next to the man with the fox.
        if ((i > 0 && houses[i - 1].cigarette == Chesterfields && house.pet != Fox) &&
            (i < 4 && houses[i + 1].cigarette == Chesterfields && house.pet != Fox)) {
            return false;
        }

        // Condition 11: Kools are smoked in the house next to the house where the horse is kept.
        if ((i > 0 && houses[i - 1].pet == Horse && house.cigarette != Kools) &&
            (i < 4 && houses[i + 1].pet == Horse && house.cigarette != Kools)) {
            return false;
        }

        // Condition 12: The Lucky Strike smoker drinks orange juice.
        if (house.cigarette == LuckyStrike && house.drink != OrangeJuice) {
            return false;
        }

        // Condition 13: The Japanese smokes Parliaments
        if (house.nationality == Japanese && house.cigarette != Parliaments) {
            return false;
        }

        // Condition 14: The Norwegian lives next to the blue house
        if ((i > 0 && houses[i - 1].color == Blue && house.nationality != Norwegian) &&
            (i < 4 && houses[i + 1].color == Blue && house.nationality != Norwegian)) {
            return false;
        }
    }
    return true;
}


void solve_with_permutation() {
    vector<Color> colors = {Red, Green, Ivory, Yellow, Blue};
    vector<Nationality> nationalities = {Englishman, Spaniard, Ukrainian,
                                         Norwegian, Japanese};
    vector<Pet> pets = {Dog, Snails, Fox, Horse, Zebra};
    vector<Drink> drinks = {Tea, Coffee, Milk, OrangeJuice, Water};
    vector<Cigarette> cigarettes = {OldGold, Kools, Chesterfields, LuckyStrike,
                                    Parliaments};

    do {
        do {
            do {
                do {
                    do {
                        for (size_t i = 0; i < 5; ++i) {
                            houses[i].color = colors[i];
                            houses[i].nationality = nationalities[i];
                            houses[i].pet = pets[i];
                            houses[i].drink = drinks[i];
                            houses[i].cigarette = cigarettes[i];
                        }

                        if (isSolution()) {
                           return;
                        }
                    } while (next_permutation(colors.begin(), colors.end()));
                } while (next_permutation(nationalities.begin(),
                                          nationalities.end()));
            } while (next_permutation(pets.begin(), pets.end()));
        } while (next_permutation(drinks.begin(), drinks.end()));
    } while (next_permutation(cigarettes.begin(), cigarettes.end()));
}

string drinks_water() {
    solve_with_permutation();
    for (const auto& house : houses) {
        if (house.drink == Water) {
            return nationalityStrings[house.nationality];
        }
    }
    throw logic_error("No solution found");
}

string owns_zebra() {
    solve_with_permutation();
    for (const auto& house : houses) {
        if (house.pet == Zebra) {
            return nationalityStrings[house.nationality];
        }
    }
    throw logic_error("No solution found");
}

}  // namespace zebra_puzzle
