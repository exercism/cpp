#include "allergies.h"

#include <string>
#include <map>
#include <vector>
#include <algorithm>

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

bool allergy_test::is_allergic_to(std::string const& allergen) const
{
    int allergen_value = allergens.at(allergen);
    return (result & allergen_value) == allergen_value;
}

std::vector<std::string> allergy_test::get_allergies() const
{
    std::vector<std::string> allergy_list({"eggs", "peanuts", "shellfish", "strawberries",
		    			   "tomatoes", "chocolate", "pollen", "cats"});
    auto is_not_allergic = [this](std::string allergen){return !(this->is_allergic_to(allergen));};

    allergy_list.erase(
        std::remove_if(allergy_list.begin(),
		       allergy_list.end(),
		       is_not_allergic),
	allergy_list.end());
    
    return allergy_list;
}

}
