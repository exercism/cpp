#if !defined(MEETUP_H)
#define MEETUP_H

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup
{

class scheduler
{
public:
    scheduler(boost::gregorian::date::month_type month,
            boost::gregorian::date::year_type year)
        : year_(year),
        month_(month)
    {}

    boost::gregorian::date monteenth() const
    {
        return teenth_day(boost::date_time::weekdays::Monday);
    }
    boost::gregorian::date tuesteenth() const
    {
        return teenth_day(boost::date_time::weekdays::Tuesday);
    }
    boost::gregorian::date wednesteenth() const
    {
        return teenth_day(boost::date_time::weekdays::Wednesday);
    }
    boost::gregorian::date thursteenth() const
    {
        return teenth_day(boost::date_time::weekdays::Thursday);
    }
    boost::gregorian::date friteenth() const
    {
        return teenth_day(boost::date_time::weekdays::Friday);
    }
    boost::gregorian::date saturteenth() const
    {
        return teenth_day(boost::date_time::weekdays::Saturday);
    }
    boost::gregorian::date sunteenth() const
    {
        return teenth_day(boost::date_time::weekdays::Sunday);
    }

    boost::gregorian::date first_monday() const
    {
        return first_weekday(boost::date_time::weekdays::Monday);
    }
    boost::gregorian::date first_tuesday() const
    {
        return first_weekday(boost::date_time::weekdays::Tuesday);
    }
    boost::gregorian::date first_wednesday() const
    {
        return first_weekday(boost::date_time::weekdays::Wednesday);
    }
    boost::gregorian::date first_thursday() const
    {
        return first_weekday(boost::date_time::weekdays::Thursday);
    }
    boost::gregorian::date first_friday() const
    {
        return first_weekday(boost::date_time::weekdays::Friday);
    }
    boost::gregorian::date first_saturday() const
    {
        return first_weekday(boost::date_time::weekdays::Saturday);
    }
    boost::gregorian::date first_sunday() const
    {
        return first_weekday(boost::date_time::weekdays::Sunday);
    }

    boost::gregorian::date second_monday() const
    {
        return second_weekday(boost::date_time::weekdays::Monday);
    }
    boost::gregorian::date second_tuesday() const
    {
        return second_weekday(boost::date_time::weekdays::Tuesday);
    }
    boost::gregorian::date second_wednesday() const
    {
        return second_weekday(boost::date_time::weekdays::Wednesday);
    }
    boost::gregorian::date second_thursday() const
    {
        return second_weekday(boost::date_time::weekdays::Thursday);
    }
    boost::gregorian::date second_friday() const
    {
        return second_weekday(boost::date_time::weekdays::Friday);
    }
    boost::gregorian::date second_saturday() const
    {
        return second_weekday(boost::date_time::weekdays::Saturday);
    }
    boost::gregorian::date second_sunday() const
    {
        return second_weekday(boost::date_time::weekdays::Sunday);
    }

    boost::gregorian::date third_monday() const
    {
        return third_weekday(boost::date_time::weekdays::Monday);
    }
    boost::gregorian::date third_tuesday() const
    {
        return third_weekday(boost::date_time::weekdays::Tuesday);
    }
    boost::gregorian::date third_wednesday() const
    {
        return third_weekday(boost::date_time::weekdays::Wednesday);
    }
    boost::gregorian::date third_thursday() const
    {
        return third_weekday(boost::date_time::weekdays::Thursday);
    }
    boost::gregorian::date third_friday() const
    {
        return third_weekday(boost::date_time::weekdays::Friday);
    }
    boost::gregorian::date third_saturday() const
    {
        return third_weekday(boost::date_time::weekdays::Saturday);
    }
    boost::gregorian::date third_sunday() const
    {
        return third_weekday(boost::date_time::weekdays::Sunday);
    }

    boost::gregorian::date fourth_monday() const
    {
        return fourth_weekday(boost::date_time::weekdays::Monday);
    }
    boost::gregorian::date fourth_tuesday() const
    {
        return fourth_weekday(boost::date_time::weekdays::Tuesday);
    }
    boost::gregorian::date fourth_wednesday() const
    {
        return fourth_weekday(boost::date_time::weekdays::Wednesday);
    }
    boost::gregorian::date fourth_thursday() const
    {
        return fourth_weekday(boost::date_time::weekdays::Thursday);
    }
    boost::gregorian::date fourth_friday() const
    {
        return fourth_weekday(boost::date_time::weekdays::Friday);
    }
    boost::gregorian::date fourth_saturday() const
    {
        return fourth_weekday(boost::date_time::weekdays::Saturday);
    }
    boost::gregorian::date fourth_sunday() const
    {
        return fourth_weekday(boost::date_time::weekdays::Sunday);
    }

    boost::gregorian::date last_monday() const
    {
        return last_weekday(boost::date_time::weekdays::Monday);
    }
    boost::gregorian::date last_tuesday() const
    {
        return last_weekday(boost::date_time::weekdays::Tuesday);
    }
    boost::gregorian::date last_wednesday() const
    {
        return last_weekday(boost::date_time::weekdays::Wednesday);
    }
    boost::gregorian::date last_thursday() const
    {
        return last_weekday(boost::date_time::weekdays::Thursday);
    }
    boost::gregorian::date last_friday() const
    {
        return last_weekday(boost::date_time::weekdays::Friday);
    }
    boost::gregorian::date last_saturday() const
    {
        return last_weekday(boost::date_time::weekdays::Saturday);
    }
    boost::gregorian::date last_sunday() const
    {
        return last_weekday(boost::date_time::weekdays::Sunday);
    }

private:
    boost::gregorian::date teenth_day(boost::date_time::weekdays day) const
    {
        return boost::gregorian::first_day_of_the_week_after(day).get_date({year_, month_, 12});
    }

    boost::gregorian::date first_weekday(boost::date_time::weekdays day) const
    {
        return boost::gregorian::first_day_of_the_week_in_month(day, month_).get_date(year_);
    }

    boost::gregorian::date nth_weekday(
        boost::gregorian::nth_day_of_the_week_in_month::week_num n,
        boost::date_time::weekdays day) const
    {
        return boost::gregorian::nth_day_of_the_week_in_month(n, day, month_).get_date(year_);
    }

    boost::gregorian::date second_weekday(boost::date_time::weekdays day) const
    {
        return nth_weekday(boost::gregorian::nth_day_of_the_week_in_month::second, day);
    }

    boost::gregorian::date third_weekday(boost::date_time::weekdays day) const
    {
        return nth_weekday(boost::gregorian::nth_day_of_the_week_in_month::third, day);
    }

    boost::gregorian::date fourth_weekday(boost::date_time::weekdays day) const
    {
        return nth_weekday(boost::gregorian::nth_day_of_the_week_in_month::fourth, day);
    }

    boost::gregorian::date last_weekday(boost::date_time::weekdays day) const
    {
        return boost::gregorian::last_day_of_the_week_in_month(day, month_).get_date(year_);
    }

    const boost::gregorian::date::year_type year_;
    const boost::gregorian::date::month_type month_;
};

}

#endif
