#include "raindrops.h"

namespace raindrops {

std::string convert(int number) {
    std::string result = "";

    // Check factor 3
    if (number % 3 == 0) {
        result += "Pling";
    }
    // Check factor 5
    if (number % 5 == 0) {
        result += "Plang";
    }
    // Check factor 7
    if (number % 7 == 0) {
        result += "Plong";
    }

    // Fallback: If no factors matched, the string is still empty
    if (result.empty()) {
        return std::to_string(number);
    }

    return result;
}

}  // namespace raindrops