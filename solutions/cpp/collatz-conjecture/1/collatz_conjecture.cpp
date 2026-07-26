#include "collatz_conjecture.h"
#include <stdexcept>

namespace collatz_conjecture {

int steps(int n) {
    // The conjecture only applies to strictly positive integers
    if (n <= 0) {
        throw std::domain_error("Only positive integers are allowed");
    }

    int step_count = 0;

    // Continue the process until n reaches 1
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;     // Even rule
        } else {
            n = 3 * n + 1; // Odd rule
        }
        step_count++;
    }

    return step_count;
}

}  // namespace collatz_conjecture