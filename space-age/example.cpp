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
