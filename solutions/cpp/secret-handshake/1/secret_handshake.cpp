#include "secret_handshake.h"
#include <algorithm>

namespace secret_handshake {

    std::vector<std::string> commands(int code) {
        std::vector<std::string> sequence;

        if (code & 1) sequence.push_back("wink");
        if (code & 2) sequence.push_back("double blink");
        if (code & 4) sequence.push_back("close your eyes");
        if (code & 8) sequence.push_back("jump");

        if (code & 16) {
            std::reverse(sequence.begin(), sequence.end());
        }

        return sequence;
    }

}  // namespace secret_handshake