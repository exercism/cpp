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

struct House {
    Color color;
    Nationality nationality;
    Pet pet;
    Drink drink;
    Cigarette cigarette;
};

vector<House> houses(5);

bool check_constraints_cigarette_drink() {
    for (size_t i = 0; i < houses.size(); i++) {
        const auto& house = houses[i];

        // Constraint 9: Milk is drunk in the middle house.
        if ((i == 2) && (house.drink != Milk)) {
            return false;
        }

        // Constraint 13: The Lucky Strike smoker drinks orange juice.
        if ((house.cigarette == LuckyStrike) && (house.drink != OrangeJuice)) {
            return false;
        }
    }
    return true;
}

bool check_constraints_cigarette_drink_pet() {
    for (size_t i = 0; i < houses.size(); i++) {
        const auto& house = houses[i];

        // Constraint 7: The Old Gold smoker owns snails.
        if ((house.pet == Snails) && (house.cigarette != OldGold)) {
            return false;
        }

        // Constraint 11: The man who smokes Chesterfields lives in the house
        // next to the man with the fox.
        if (((i > 0) && (house.pet == Fox) &&
             (houses[i - 1].cigarette != Chesterfields)) &&
            ((i < 4) && (house.pet == Fox) &&
             (houses[i + 1].cigarette != Chesterfields))) {
            return false;
        }

        if ((i == 0) && (house.pet == Fox) &&
            (houses[i + 1].cigarette != Chesterfields)) {
            return false;
        }

        if ((i == 4) && (house.pet == Fox) &&
            (houses[i - 1].cigarette != Chesterfields)) {
            return false;
        }

        // Constraint 12: Kools are smoked in a house next to the house where
        // the horse is kept.
        if (((i > 0) && (house.pet == Horse) &&
             (houses[i - 1].cigarette != Kools)) &&
            ((i < 4) && (house.pet == Horse) &&
             (houses[i + 1].cigarette != Kools))) {
            return false;
        }

        if ((i == 0) && (house.pet == Horse) &&
            (houses[i + 1].cigarette != Kools)) {
            return false;
        }

        if ((i == 4) && (house.pet == Horse) &&
            (houses[i - 1].cigarette != Kools)) {
            return false;
        }
    }
    return true;
}

bool check_constraints_cigarette_drink_pet_nationality() {
    for (size_t i = 0; i < houses.size(); i++) {
        const auto& house = houses[i];

        // Constraint 3: The Spaniard owns the dog.
        if ((house.nationality == Spaniard) && (house.pet != Dog)) {
            return false;
        }

        // Constraint 5: The Ukrainian drinks tea.
        if ((house.nationality == Ukrainian) && (house.drink != Tea)) {
            return false;
        }

        // Constraint 10: The Norwegian lives in the first house.
        if ((i == 0) && (house.nationality != Norwegian)) {
            return false;
        }

        // Constraint 14: The Japanese smokes Parliaments.
        if ((house.nationality == Japanese) &&
            (house.cigarette != Parliaments)) {
            return false;
        }
    }
    return true;
}

bool check_constraints_cigarette_drink_pet_nationality_color() {
    for (size_t i = 0; i < houses.size(); i++) {
        const auto& house = houses[i];

        // Constraint 2: The Englishman lives in the red house.
        if ((house.color == Red) && (house.nationality != Englishman)) {
            return false;
        }

        // Constraint 4: Coffee is drunk in the green house.
        if ((house.color == Green) && (house.drink != Coffee)) {
            return false;
        }

        // Constraint 6: The green house is immediately to the right of the
        // ivory house.
        if ((i > 0) && (house.color == Green) &&
            (houses[i - 1].color != Ivory)) {
            return false;
        }

        if ((i == 0) && (house.color == Green)) {
            return false;
        }

        // Constraint 8: Kools are smoked in the yellow house.
        if ((house.color == Yellow) && (house.cigarette != Kools)) {
            return false;
        }

        // Constraint 15: The Norwegian lives next to the blue house.
        if (((i > 0) && (house.nationality == Norwegian) &&
             (houses[i - 1].color != Blue)) &&
            ((i < 4) && (house.nationality == Norwegian) &&
             (houses[i + 1].color != Blue))) {
            return false;
        }

        if ((i == 0) && (house.nationality == Norwegian) &&
            (houses[i + 1].color != Blue)) {
            return false;
        }

        if ((i == 4) && (house.nationality == Norwegian) &&
            (houses[i - 1].color != Blue)) {
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
        for (size_t i = 0; i < 5; i++) {
            houses[i].cigarette = cigarettes[i];
        }

        do {
            for (size_t i = 0; i < 5; i++) {
                houses[i].drink = drinks[i];
            }

            if (!check_constraints_cigarette_drink()) {
                continue;
            }

            do {
                for (size_t i = 0; i < 5; i++) {
                    houses[i].pet = pets[i];
                }

                if (!check_constraints_cigarette_drink_pet()) {
                    continue;
                }

                do {
                    for (size_t i = 0; i < 5; i++) {
                        houses[i].nationality = nationalities[i];
                    }

                    if (!check_constraints_cigarette_drink_pet_nationality()) {
                        continue;
                    }

                    do {
                        for (size_t i = 0; i < 5; i++) {
                            houses[i].color = colors[i];
                        }

                        if (check_constraints_cigarette_drink_pet_nationality_color()) {
                            return;
                        }

                    } while (next_permutation(colors.begin(), colors.end()));

                } while (next_permutation(nationalities.begin(),
                                          nationalities.end()));

            } while (next_permutation(pets.begin(), pets.end()));

        } while (next_permutation(drinks.begin(), drinks.end()));

    } while (next_permutation(cigarettes.begin(), cigarettes.end()));
}

Solution solve() {
    solve_with_permutation();
    Solution solution;

    // find the house with the zebra
    for (size_t i = 0; i < houses.size(); i++) {
        if (houses[i].pet == Zebra) {
            solution.ownsZebra = nationalityStrings[houses[i].nationality];
            break;
        }
    }

    // find the house with the water
    for (size_t i = 0; i < houses.size(); i++) {
        if (houses[i].drink == Water) {
            solution.drinksWater = nationalityStrings[houses[i].nationality];
            break;
        }
    }

    return solution;
}

}  // namespace zebra_puzzle