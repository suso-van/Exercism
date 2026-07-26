#include "nth_prime.h"
#include <stdexcept>

// Anonymous namespace for internal helper functions
namespace {

    bool is_prime(int number) {
        if (number <= 1) return false;
        if (number == 2) return true;
        
        // Even numbers greater than 2 are not prime
        if (number % 2 == 0) return false;
        
        // Check for odd factors up to the square root of the number
        for (int i = 3; i * i <= number; i += 2) {
            if (number % i == 0) return false;
        }
        
        return true;
    }

} // end anonymous namespace

namespace nth_prime {

int nth(int n) {
    if (n <= 0) {
        throw std::domain_error("There is no zeroth prime.");
    }

    int count = 0;
    int current = 1; // Start checking right before the first prime (2)

    // Keep counting up until we've found 'n' primes
    while (count < n) {
        current++;
        if (is_prime(current)) {
            count++;
        }
    }

    return current;
}

}  // namespace nth_prime