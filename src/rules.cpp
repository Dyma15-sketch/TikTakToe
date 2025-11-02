#include "Rules.hpp"


// Constructor implicit 
Rules::Rules() : board() {}

// Constructor cu parametri
Rules::Rules(const Board& b) : board(b) {}

// Constructor de copiere 
Rules::Rules(const Rules& other) : board(other.board) {}

// Operator de atribuire 
Rules& Rules::operator=(const Rules& other) {
    if (this != &other) {
        board = other.board;
    }
    return *this;
}

//  Operator de comparare egalitate 
bool Rules::operator==(const Rules& other) const {
    return board == other.board;
}

//  Operator de ieșire 
std::ostream& operator<<(std::ostream& os, const Rules& rules) {
    os << "Reguli pentru tabla:\n" << rules.board;
    return os;
}

// Operator de intrare 
std::istream& operator>>(std::istream& is, Rules& rules) {
    std::cout << "Introduceți o tablă pentru reguli:\n";
    is >> rules.board;
    return is;
}

//  Verifica daca un jucator a castigat 
bool Rules::CheckWin(Board& board, Player player) {
    PlayerType pType = player.GetType();

    //  Verificare linii 
    for (int i = 0; i < 3; ++i) {
        if (board.GetCell(i, 0).GetType() == pType &&
            board.GetCell(i, 1).GetType() == pType &&
            board.GetCell(i, 2).GetType() == pType)
            return true;
    }

    //  Verificare coloane 
    for (int j = 0; j < 3; ++j) {
        if (board.GetCell(0, j).GetType() == pType &&
            board.GetCell(1, j).GetType() == pType &&
            board.GetCell(2, j).GetType() == pType)
            return true;
    }

    //  Verificare diagonale 
    if (board.GetCell(0, 0).GetType() == pType &&
        board.GetCell(1, 1).GetType() == pType &&
        board.GetCell(2, 2).GetType() == pType)
        return true;

    if (board.GetCell(0, 2).GetType() == pType &&
        board.GetCell(1, 1).GetType() == pType &&
        board.GetCell(2, 0).GetType() == pType)
        return true;

    return false;
}

//  Verifica daca este remiza
bool Rules::CheckDraw(Board& board) {
    if (board.IsFull() &&
        !CheckWin(board, Player(PlayerType::X)) &&
        !CheckWin(board, Player(PlayerType::O)))
        return true;

    return false;
}
