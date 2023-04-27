// INFO: Headers from the standard library should be inserted at the top via
#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    auto per_hour{8.0};
    return per_hour * hourly_rate;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    return before_discount * (100.0 - discount) / 100.0;
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    auto per_day{daily_rate(hourly_rate)};
    auto workdays_per_month{22};
    auto per_month{per_day * workdays_per_month};
    auto after_discount{apply_discount(per_month, discount)};
    auto rounded_up{std::ceil(after_discount)};

    return rounded_up;
}

// days_in_budget calculates the number of workdays given a budget, hourly rate,
// and discount The returned number of days is rounded down (take the floor) to
// the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    auto discounted_per_hour{apply_discount(hourly_rate, discount)};
    auto discounted_daily{daily_rate(discounted_per_hour)};

    return static_cast<int>(budget / discounted_daily);
}