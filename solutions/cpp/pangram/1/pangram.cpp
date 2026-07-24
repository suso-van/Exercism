#include "pangram.h"
#include <cctype>
#include <bitset>

namespace pangram {

bool is_pangram(std::string_view sentence) {
    std::bitset<26> letters_seen;

    for (char c : sentence) {
        // Only process alphabetic characters
        if (std::isalpha(static_cast<unsigned char>(c))) {
            // Convert to lowercase and map 'a'-'z' to indices 0-25
            int index = std::tolower(static_cast<unsigned char>(c)) - 'a';
            letters_seen.set(index);
        }
    }

    // A pangram must have all 26 bits set to true
    return letters_seen.all();
}

}  // namespace pangram