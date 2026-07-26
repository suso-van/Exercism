#pragma once

#include <string>

namespace say {

    // Spells out a number from 0 to 999,999,999,999 in English
    std::string in_english(long long number);

}  // namespace say