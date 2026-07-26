#include "rna_transcription.h"
#include <stdexcept>

namespace rna_transcription {

char to_rna(char dna) {
    switch (dna) {
        case 'G': return 'C';
        case 'C': return 'G';
        case 'T': return 'A';
        case 'A': return 'U';
        default: throw std::invalid_argument("Invalid DNA nucleotide");
    }
}

std::string to_rna(std::string_view dna) {
    std::string rna;
    // Reserving space prevents multiple memory allocations during the loop
    rna.reserve(dna.length());
    
    for (char nucleotide : dna) {
        rna += to_rna(nucleotide);
    }
    
    return rna;
}

}  // namespace rna_transcription