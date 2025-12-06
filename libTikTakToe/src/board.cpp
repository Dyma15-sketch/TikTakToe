#include "board.hpp"
#include <algorithm>
#include <functional>

namespace ttt {

Board::Board() {
    Reset();
}

Board::Board(const Player& initialPlayer) {
    cells.resize(3, std::vector<std::shared_ptr<Player>>(3));
    for (auto &row : cells)
        for (auto &cell : row)
            cell = std::make_shared<Player>(initialPlayer);
}

Board::Board(const Board& other) {
    cells.resize(3, std::vector<std::shared_ptr<Player>>(3));
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 3; ++j)
            cells[i][j] = std::make_shared<Player>(*other.cells[i][j]);
}

Board& Board::operator=(const Board& other) {
    if (this != &other) {
        for (size_t i = 0; i < 3; ++i)
            for (size_t j = 0; j < 3; ++j)
                *cells[i][j] = *other.cells[i][j];
    }
    return *this;
}

bool Board::operator==(const Board& other) const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (!(*cells[i][j] == *other.cells[i][j])) return false;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Board& board) {
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            os << *board.cells[i][j];
            if (j < 2) os << " | ";
        }
        os << "\n";
        if (i < 2) os << "--+---+--\n";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Board& board) {
    for (size_t i = 0; i < 3; ++i)
        for (size_t j = 0; j < 3; ++j)
            is >> *board.cells[i][j];
    return is;
}

bool Board::PlaceMark(int row, int col, const Player& player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) return false;
    if (cells[row][col]->GetType() == PlayerType::None) {
        *cells[row][col] = player;
        return true;
    }
    return false;
}

Player Board::GetCell(int row, int col) const {
    if (row < 0 || row >= 3 || col < 0 || col >= 3) return Player(PlayerType::None);
    return *cells[row][col];
}

bool Board::IsFull() const {
    for (const auto &row : cells)
        for (const auto &cell : row)
            if (cell->GetType() == PlayerType::None) return false;
    return true;
}

void Board::Reset() {
    cells.assign(3, std::vector<std::shared_ptr<Player>>(3));
    for (auto &row : cells)
        for (auto &cell : row)
            cell = std::make_shared<Player>(PlayerType::None);
}

}
