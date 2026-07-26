#pragma once

#include <string>
#include <map>

namespace nucleotide_count {

    // Declares a free function that takes a string and returns the map of counts
    std::map<char, int> count(const std::string& dna);

}  // namespace nucleotide_count