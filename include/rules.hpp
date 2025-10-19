#pragma once
#include "Board.hpp"
#include <iostream>

class Rules {
private:
    Board board; 

public:
    Rules();
    Rules(const Board& b);
    Rules(const Rules& other);
    Rules& operator=(const Rules& other);
    bool operator==(const Rules& other) const;
    bool operator!=(const Rules& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Rules& rules);
    friend std::istream& operator>>(std::istream& is, Rules& rules);

  
    static bool CheckWin(Board& board, Player player);
    static bool CheckDraw(Board& board);
};
