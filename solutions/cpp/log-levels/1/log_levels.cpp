#include <string>
#include <cctype> // Needed for std::toupper

namespace log_line {

std::string message(std::string line) {
    // 1. Find where the log level prefix ends "]: "
    size_t prefix_end = line.find("]: ");
    
    // 2. Grab everything after "]: "
    std::string raw_message = line.substr(prefix_end + 3);
    
    // 3. Trim whitespace from the front and back
    size_t first = raw_message.find_first_not_of(" \t\r\n");
    size_t last = raw_message.find_last_not_of(" \t\r\n");
    
    if (first == std::string::npos) {
        return "";
    }
    
    return raw_message.substr(first, (last - first + 1));
}

std::string log_level(std::string line) {
    // 1. Find the closing bracket
    size_t close_bracket = line.find(']');
    
    // 2. Extract the string between '[' (index 1) and ']'
    std::string level = line.substr(1, close_bracket - 1);
    
    // 3. Convert each character to UPPERCASE to match instructions
    for (char &c : level) {
        c = std::toupper(c);
    }
    
    return level;
}

std::string reformat(std::string line) {
    // Format: "message (LOG_LEVEL)"
    return message(line) + " (" + log_level(line) + ")";
}

}  // namespace log_line