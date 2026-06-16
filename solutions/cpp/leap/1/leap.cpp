#include "leap.h"

namespace leap {

bool is_leap_year(int year) {
    // Rule 1 & 2: Divisible by 4 AND NOT divisible by 100
    // Rule 3: OR it is divisible by 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

}  // namespace leap