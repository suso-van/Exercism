#pragma once

#include <string>
#include <string_view>

namespace rna_transcription {

    // Translates a single DNA nucleotide to RNA
    char to_rna(char dna);

    // Translates a full DNA sequence to an RNA sequence
    std::string to_rna(std::string_view dna);

}  // namespace rna_transcription