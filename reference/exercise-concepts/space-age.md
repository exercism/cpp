# Space Age

## Task

Given an age in seconds, calculate how old someone would be on:

- Mercury: orbital period 0.2408467 Earth years
- Venus: orbital period 0.61519726 Earth years
- Earth: orbital period 1.0 Earth years, 365.25 Earth days, or 31557600 seconds
- Mars: orbital period 1.8808158 Earth years
- Jupiter: orbital period 11.862615 Earth years
- Saturn: orbital period 29.447498 Earth years
- Uranus: orbital period 84.016846 Earth years
- Neptune: orbital period 164.79132 Earth years

So if you were told someone were 1,000,000,000 seconds old, you should be able to say that they're 31.69 Earth-years old.

## Example

`space-age.h`

```cpp
#if !defined(SPACE_AGE_H)
#define SPACE_AGE_H

namespace space_age
{

class space_age
{
public:
    explicit space_age(unsigned long long secs);

    unsigned long long seconds() const;
    double on_earth() const;
    double on_mercury() const;
    double on_venus() const;
    double on_mars() const;
    double on_jupiter() const;
    double on_saturn() const;
    double on_uranus() const;
    double on_neptune() const;

private:
    unsigned long long seconds_;
};

}

#endif
```

`space_age.cpp`

```cpp
#include "space_age.h"

namespace space_age
{

namespace
{
const double earth_years_per_second = 1.0/31557600.0;
const double earth_years_per_mercury_year = 0.2408467;
const double earth_years_per_venus_year = 0.61519726;
const double earth_years_per_mars_year = 1.8808158;
const double earth_years_per_jupiter_year = 11.862615;
const double earth_years_per_saturn_year = 29.447498;
const double earth_years_per_uranus_year = 84.016846;
const double earth_years_per_neptune_year = 164.79132;
}

space_age::space_age(unsigned long long secs)
    : seconds_(secs)
{
}

unsigned long long space_age::seconds() const
{
    return seconds_;
}

double space_age::on_earth() const
{
    return seconds_*earth_years_per_second;
}

double space_age::on_mercury() const
{
    return on_earth()/earth_years_per_mercury_year;
}

double space_age::on_venus() const
{
    return on_earth()/earth_years_per_venus_year;
}

double space_age::on_mars() const
{
    return on_earth()/earth_years_per_mars_year;
}

double space_age::on_jupiter() const
{
    return on_earth()/earth_years_per_jupiter_year;
}

double space_age::on_saturn() const
{
    return on_earth()/earth_years_per_saturn_year;
}

double space_age::on_uranus() const
{
    return on_earth()/earth_years_per_uranus_year;
}

double space_age::on_neptune() const
{
    return on_earth()/earth_years_per_neptune_year;
}

}
```

## Concepts

- .h file: the tests include `"space-age.h"`
- .cpp file: the most common approach is to use a `.cpp` for declaring member functions
- include guard: protect against multiple inclusion within a single translation unit
- namespaces: the class/struct is member of a namespace
- constructors: to store number of seconds passed as an argument
- class/struct members: to store input given in the constructor
- classes: used as the main entry point for the exercise
- member functions: used as a way of calculating/getting results
- const-qualification: member functions must be qualified as `const`
- return values: the result is returned by the function
- floating point types: all constants are stored as `double`
- signed and unsigned integer types: number of seconds is a large integer
- sizes of integer types: using `std::int64_t` to correctly represent input
- member declaration qualification: number of seconds does not change after the initialization, member that holds it can be declared `const`
- member initializer lists: for initialization of member holding number of seconds
- `noexcept` function specifier: none of the functions in this exercise are throwing
- type casts: casting from int input to store number of seconds as `double`

## Alternative approaches

- Declaring all the member functions in the header file
- Using array of constants for storing number of seconds in the year for different planets
- Using hash-map for storing number of seconds in the year for different planets

## Common mistakes

- forgetting to submit the `.h` file
- forgetting to enable and/or run all the tests
- no include guards
- using `float` instead of `double`
- explicit constructor: with one argument should be marked `explicit`
- passing numeric types by reference
- bad variable and constants names
- different types for the local `result` variable and the return type
- writing to `std::cout` or `std::cerr`
- not using member initializer lists
- not marking all members as `constexpr`
- using C-style casts when `static_cast` is more appropriate

## Common suggestions to improve a solution

- use `constexpr` whenever the result of computation does not depend on run-time data
- use using member initializer lists
- use anonymous namespace for storing constants
- add `noexcept` to mark all functions that are not expected to throw exceptions
