#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include "Rules.hpp"
#include "Board.hpp"
#include "Player.hpp"

class Rules {
private:
    std::shared_ptr<Board> board; 

public:
    // Constructor implicit
    Rules() : board(std::make_shared<Board>()) {}

    // Constructor cu parametri
    Rules(const Board& b) : board(std::make_shared<Board>(b)) {}

    // Constructor de copiere
    Rules(const Rules& other) : board(std::make_shared<Board>(*other.board)) {}

    // Operator de atribuire
    Rules& operator=(const Rules& other) {
        if (this != &other) {
            board = std::make_shared<Board>(*other.board);
        }
        return *this;
    }

    // Operator de comparare 
    bool operator==(const Rules& other) const {
        return *board == *other.board;
    }

    // Operator de ieșire 
    friend std::ostream& operator<<(std::ostream& os, const Rules& rules) {
        os << "Reguli și starea curentă a tablei:\n" << *rules.board;
        return os;
    }

    // Operator de intrare
    friend std::istream& operator>>(std::istream& is, Rules& rules) {
        std::cout << "Introduceți tabla de joc pentru verificare:\n";
        is >> *rules.board;
        return is;
    }

    // Verifica daca un jucator a castigat
    bool CheckWin(const Player& player) const {
        PlayerType pType = player.GetType();

        auto lineWin = [&](int r) {
            return std::all_of({0,1,2}.begin(), {0,1,2}.end(),
                [&](int c){ return board->GetCell(r, c).GetType() == pType; });
        };

        auto columnWin = [&](int c) {
            return std::all_of({0,1,2}.begin(), {0,1,2}.end(),
                [&](int r){ return board->GetCell(r, c).GetType() == pType; });
        };

        auto diagonal1 = std::all_of({0,1,2}.begin(), {0,1,2}.end(),
            [&](int i){ return board->GetCell(i, i).GetType() == pType; });

        auto diagonal2 = std::all_of({0,1,2}.begin(), {0,1,2}.end(),
            [&](int i){ return board->GetCell(i, 2 - i).GetType() == pType; });

        // Verifica liniile, coloanele și diagonalele folosind algoritmi STL
        return std::any_of({0,1,2}.begin(), {0,1,2}.end(), lineWin)
            || std::any_of({0,1,2}.begin(), {0,1,2}.end(), columnWin)
            || diagonal1 || diagonal2;
    }

    // Verifica daca este remiza
    bool CheckDraw() const {
        Player x(PlayerType::X);
        Player o(PlayerType::O);
        return board->IsFull() && !CheckWin(x) && !CheckWin(o);
    }

    // Acces la board (getter și setter)
    std::shared_ptr<Board> GetBoard() const { return board; }
    void SetBoard(const Board& b) { board = std::make_shared<Board>(b); }
};

