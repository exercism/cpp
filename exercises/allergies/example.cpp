#include "allergies.h"

#include <string>
#include <map>
#include <set>

namespace allergies
{

allergy_test::allergy_test(const int test_result)
    : result(test_result)
    , allergens({
    	{"eggs", 1},
	{"peanuts", 2},
	{"shellfish", 4},
	{"strawberries", 8},
	{"tomatoes", 16},
	{"chocolate", 32},
    	{"pollen", 64},
	{"cats", 128}
   })
{} 

bool allergy_test::is_allergic_to(std::string const& allergen)
{
    int allergen_value = allergens.at(allergen);
    return (result & allergen_value) == allergen_value;
}

std::set<std::string> allergy_test::get_allergies()
{
    std::set<std::string> allergy_set;
    
    for(auto const &ent : allergens)
        if((result & ent.second) == ent.second)
            allergy_set.insert(ent.first);

    return allergy_set;
}

}
