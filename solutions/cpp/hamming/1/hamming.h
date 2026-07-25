#if !defined(HAMMING_H)
#define HAMMING_H

#include <string_view>

namespace hamming {

int compute(std::string_view a, std::string_view b);

}  // namespace hamming

#endif // HAMMING_H