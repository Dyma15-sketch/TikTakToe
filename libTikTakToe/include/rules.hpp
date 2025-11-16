#pragma once
#include <iostream>
#include "board.hpp"
#include "player.hpp"

namespace ttt {

class Rules {
public:
    Rules() = default;
    Rules(const Rules& other) = default;
    Rules& operator=(const Rules& other) = default;
    bool operator==(const Rules& other) const { return true; }

    static bool CheckWin(const Board& board, const Player& player);
    static bool CheckDraw(const Board& board);

    friend std::ostream& operator<<(std::ostream& os, const Rules& rules) {
        os << "TicTacToe rules\n";
        return os;
    }
    friend std::istream& operator>>(std::istream& is, Rules& r) {
        (void)is; (void)r; return is;
    }
};

} 
