#include "grains.h"

namespace grains {

unsigned long long square(int square_num) {
    // Left bit-shifting by (n - 1) is equivalent to 2^(n - 1)
    // 1ULL ensures the literal '1' is treated as an Unsigned Long Long
    return 1ULL << (square_num - 1);
}

unsigned long long total() {
    // The sum of grains on all 64 squares is exactly the maximum 
    // possible value of a 64-bit unsigned integer. 
    // ~0ULL flips all 0 bits to 1s, giving us 2^64 - 1.
    return ~0ULL; 
}

}  // namespace grains