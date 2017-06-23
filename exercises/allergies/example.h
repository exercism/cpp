#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <map>

namespace allergies
{

class allergy_test
{
public:
    allergy_test(const int test_result);

    bool is_allergic_to(std::string const& allergen);

private:
    int result;
    std::map<std::string, int> allergens;

};

}

#endif
