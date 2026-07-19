#include "reverse_string.h"
#include <string>
#include <algorithm>

namespace reverse_string {

std::string reverse_string(const std::string& str) {
    // We can elegantly create a new string using reverse iterators 
    // from the original string (rbegin to rend).
    return std::string(str.rbegin(), str.rend());
}

}  // namespace reverse_string