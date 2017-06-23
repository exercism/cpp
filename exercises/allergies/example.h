#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <map>
#include <set>

namespace allergies
{

class allergy_test
{
public:
    allergy_test(const int test_result);

    bool is_allergic_to(std::string const& allergen);
    std::set<std::string> get_allergies();

private:
    int result;
    std::map<std::string, int> allergens;

};

}

#endif
