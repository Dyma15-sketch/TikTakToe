#include "Board.hpp"

// Constructor implicit 
Board::Board() {
    Reset();
}

// Constructor cu parametri 
Board::Board(const Player& initialPlayer) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cells[i][j] = initialPlayer;
}

// Constructor de copiere 
Board::Board(const Board& other) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cells[i][j] = other.cells[i][j];
}

// Operator de atribuire 
Board& Board::operator=(const Board& other) {
    if (this != &other) {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                cells[i][j] = other.cells[i][j];
    }
    return *this;
}

// Operator de comparare 
bool Board::operator==(const Board& other) const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (cells[i][j] != other.cells[i][j])
                return false;
    return true;
}

// Operator de iesire 
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

// Operator de intrare
std::istream& operator>>(std::istream& is, Board& board) {
    std::cout << "Introduceți tabla (3x3) folosind X, O sau None:\n";
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            is >> board.cells[i][j];
    return is;
}

// Plaseaza pe celula
bool Board::PlaceMark(int row, int col, Player player) {
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
        return false;

    if (cells[row][col].GetType() == PlayerType::None) {
        cells[row][col] = player;
        return true;
    }

    return false;
}

//  Ia celula 
Player Board::GetCell(int row, int col) const {
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
        return Player(PlayerType::None);
    return cells[row][col];
}

// Daca celula e ocupata
bool Board::IsFull() const {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (cells[i][j].GetType() == PlayerType::None)
                return false;
    return true;
}

// Reseteaza tabla
void Board::Reset() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cells[i][j].SetType(PlayerType::None);
}


