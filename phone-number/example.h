#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

class phone_number
{
public:
    phone_number(const std::string& text);

    std::string area_code() const;
    std::string number() const;

    operator std::string() const;

private:
    const std::string digits_;
};

#endif
