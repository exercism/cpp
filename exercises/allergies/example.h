#if !defined(ALLERGIES_H)
#define ALLERGIES_H

#include <string>
#include <map>
#include <vector>

namespace allergies
{

class allergy_test
{
public:
    allergy_test(const int test_result);

    bool is_allergic_to(std::string const& allergen) const;
    std::vector<std::string> get_allergies() const;

private:
    int const result;
    std::map<std::string, int> const allergens;
};

}

#endif
