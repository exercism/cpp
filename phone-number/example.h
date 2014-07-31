#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

class phone_number
{
public:
    phone_number(const std::string& text);

    std::string area_code() const;
    std::string number() const;

    explicit operator std::string() const;

private:
    std::string extension() const;

    std::string exchange() const;

    const std::string digits_;
};

#endif
