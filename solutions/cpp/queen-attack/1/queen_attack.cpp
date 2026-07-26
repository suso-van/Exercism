#include "queen_attack.h"
#include <stdexcept>
#include <cstdlib>

namespace queen_attack {

chess_board::chess_board(std::pair<int, int> white, std::pair<int, int> black)
    : white_pos(white), black_pos(black) {
    
    // Check if coordinates are within the 8x8 board (0 to 7)
    if (white.first < 0 || white.first > 7 || white.second < 0 || white.second > 7 ||
        black.first < 0 || black.first > 7 || black.second < 0 || black.second > 7) {
        throw std::domain_error("Queen must be placed on a valid 8x8 board square.");
    }
    
    // Check if both queens are on the exact same square
    if (white == black) {
        throw std::domain_error("Queens cannot occupy the same square.");
    }
}

std::pair<int, int> chess_board::white() const {
    return white_pos;
}

std::pair<int, int> chess_board::black() const {
    return black_pos;
}

bool chess_board::can_attack() const {
    // Attack on the same row
    if (white_pos.first == black_pos.first) {
        return true;
    }
    
    // Attack on the same column
    if (white_pos.second == black_pos.second) {
        return true;
    }
    
    // Attack on the same diagonal
    // If the absolute difference of rows equals the absolute difference of columns, they are on a diagonal.
    int row_diff = std::abs(white_pos.first - black_pos.first);
    int col_diff = std::abs(white_pos.second - black_pos.second);
    
    if (row_diff == col_diff) {
        return true;
    }
    
    return false;
}

}  // namespace queen_attack