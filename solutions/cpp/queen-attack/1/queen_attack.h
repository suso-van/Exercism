#pragma once

#include <utility>

namespace queen_attack {

class chess_board {
private:
    std::pair<int, int> white_pos;
    std::pair<int, int> black_pos;

public:
    // Constructor with default positions
    chess_board(std::pair<int, int> white = {0, 3}, std::pair<int, int> black = {7, 3});

    // Accessors for the queen positions
    std::pair<int, int> white() const;
    std::pair<int, int> black() const;

    // Returns true if the queens can attack each other
    bool can_attack() const;
};

}  // namespace queen_attack