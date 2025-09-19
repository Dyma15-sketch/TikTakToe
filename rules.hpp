#pragma once
#include "board.hpp"

class Rules {
public:
    static bool CheckWin(const Board& board, Player player); 
    static bool CheckDraw(const Board& board);               
};
