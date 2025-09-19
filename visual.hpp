#pragma once
#include "board.hpp"

class Painter {
public:
    void DrawBoard(const Board& board);         
    void ShowMessage( const char* message);      
};
