#include "nucleotide_count.h"
#include <stdexcept>

namespace nucleotide_count {

std::map<char, int> count(const std::string& dna) {
    // Initialize the map with 0 for all valid nucleotides
    std::map<char, int> counts = {{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    for (char nucleotide : dna) {
        // If the character isn't a valid key in our map, throw an error
        if (counts.find(nucleotide) == counts.end()) {
            throw std::invalid_argument("Invalid nucleotide found in DNA sequence");
        }
        // Increment the count for the valid nucleotide
        counts[nucleotide]++;
    }

    return counts;
}

}  // namespace nucleotide_count