#pragma once
#include "board.hpp"

class Rules {
public:
    static bool CheckWin( Board& board, Player player); 
    static bool CheckDraw( Board& board);               
};
