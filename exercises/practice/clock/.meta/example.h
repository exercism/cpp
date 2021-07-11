#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent
{

class clock
{
public:
    static clock at(int hour, int minute = 0);

    clock& plus(int minutes);
    clock& minus(int minutes);

    operator std::string() const;

    bool operator==(const clock& rhs) const;

private:
    clock(int hour, int minute);
    void clean();
    int hour_;
    int minute_;
};

inline bool operator!=(const clock& lhs, const clock& rhs)
{
    return !(lhs == rhs);
}

}

#endif
