#include <cmath>

// daily_rate calculates the daily rate given an hourly rate
double daily_rate(double hourly_rate) {
    // 8 hours of work per day
    return hourly_rate * 8.0;
}

// apply_discount calculates the price after a discount
double apply_discount(double before_discount, double discount) {
    // Convert percentage discount (e.g. 10.0) into a factor (e.g. 0.10)
    return before_discount * (1.0 - (discount / 100.0));
}

// monthly_rate calculates the monthly rate, given an hourly rate and a discount
// The returned monthly rate is rounded up to the nearest integer.
int monthly_rate(double hourly_rate, double discount) {
    // 1. Calculate un-discounted monthly rate for 22 days
    double total_monthly_before_discount = daily_rate(hourly_rate) * 22.0;
    
    // 2. Apply the discount
    double discounted_monthly = apply_discount(total_monthly_before_discount, discount);
    
    // 3. Round up using std::ceil and cast back to an integer
    return static_cast<int>(std::ceil(discounted_monthly));
}

// days_in_budget calculates the number of workdays given a budget, hourly rate, and discount
// The returned number of days is rounded down (take the floor) to the next integer.
int days_in_budget(int budget, double hourly_rate, double discount) {
    // 1. Find out how much the freelancer costs per day AFTER the discount
    double discounted_daily_rate = apply_discount(daily_rate(hourly_rate), discount);
    
    // 2. Divide total budget by daily cost and take the floor (round down)
    return static_cast<int>(std::floor(budget / discounted_daily_rate));
}