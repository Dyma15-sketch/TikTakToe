#include "Rules.hpp"


Rules::Rules() : board() {}

Rules::Rules(const Board& b) : board(b) {}

Rules::Rules(const Rules& other) : board(other.board) {}

Rules& Rules::operator=(const Rules& other) {
    if (this != &other) {
        board = other.board;
    }
    return *this;
}

bool Rules::operator==(const Rules& other) const {
    return board == other.board;
}

bool Rules::operator!=(const Rules& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Rules& rules) {
    os << "Reguli pentru tabla:\n" << rules.board;
    return os;
}

std::istream& operator>>(std::istream& is, Rules& rules) {
    std::cout << "Introduceți o tablă pentru reguli:\n";
    is >> rules.board;
    return is;
}



bool Rules::CheckWin(Board& board, Player player) {}
bool Rules::CheckDraw(Board& board) {}

