#include "hamming.h"
#include <stdexcept>

namespace hamming {

int compute(std::string_view a, std::string_view b) {
    // The Hamming distance is only defined for sequences of equal length
    if (a.length() != b.length()) {
        throw std::domain_error("Strands must be of equal length");
    }

    int distance = 0;
    
    // Iterate through both strands simultaneously and compare characters
    for (std::size_t i = 0; i < a.length(); ++i) {
        if (a[i] != b[i]) {
            distance++;
        }
    }

    return distance;
}

}  // namespace hamming