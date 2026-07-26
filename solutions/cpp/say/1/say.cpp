#include "say.h"
#include <stdexcept>
#include <vector>

// Anonymous namespace for private helpers
namespace {

    const std::vector<std::string> ones = {
        "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
        "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };

    const std::vector<std::string> tens = {
        "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
    };

    // Helper to spell out numbers up to 999
    std::string spell_below_1000(long long n) {
        if (n == 0) return "";
        if (n < 20) return ones[n];
        
        if (n < 100) {
            std::string res = tens[n / 10];
            if (n % 10 != 0) {
                res += "-" + ones[n % 10]; // e.g., "twenty-two"
            }
            return res;
        }
        
        std::string res = ones[n / 100] + " hundred";
        if (n % 100 != 0) {
            res += " " + spell_below_1000(n % 100);
        }
        return res;
    }

} // end anonymous namespace

namespace say {

std::string in_english(long long n) {
    if (n < 0 || n >= 1000000000000LL) {
        throw std::domain_error("Number must be between 0 and 999,999,999,999.");
    }
    
    if (n == 0) return "zero";

    // Scales to chunk the number by
    std::vector<std::pair<long long, std::string>> scales = {
        {1000000000LL, "billion"},
        {1000000LL, "million"},
        {1000LL, "thousand"},
        {1LL, ""}
    };

    std::string result = "";
    
    for (const auto& scale : scales) {
        if (n >= scale.first) {
            long long chunk = n / scale.first;
            n %= scale.first; // Keep the remainder for the next loop
            
            if (!result.empty()) {
                result += " ";
            }
            
            result += spell_below_1000(chunk);
            
            if (!scale.second.empty()) {
                result += " " + scale.second;
            }
        }
    }
    
    return result;
}

}  // namespace say