#include "Board.hpp"


Board::Board() {
    Reset();
}

Board::Board(const Player& initialPlayer) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cells[i][j] = initialPlayer;
}

Board::Board(const Board& other) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cells[i][j] = other.cells[i][j];
}

Board& Board::operator=(const Board& other) {
    if (this != &other) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cells[i][j] = other.cells[i][j];
    }
    return *this;
}

bool Board::operator==(const Board& other) const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (cells[i][j] != other.cells[i][j])
                return false;
    return true;
}

bool Board::operator!=(const Board& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            os << board.cells[i][j];
            if (j < 2) os << " | ";
        }
        os << "\n";
        if (i < 2) os << "--+---+--\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Board& board) {
    std::cout << "Introduceți tabla (3x3) folosind X, O sau None:\n";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            is >> board.cells[i][j];
    return is;
}


bool Board::PlaceMark(int row, int col, Player player) {}
Player Board::GetCell(int row, int col) const {}
bool Board::IsFull() const {}
void Board::Reset() {}

