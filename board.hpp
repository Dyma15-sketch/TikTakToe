#pragma once
#include "player.hpp"

class Board {
    Player cells[3][3];  
public:
    Board();                     
    bool PlaceMark(int row, int col, Player player); 
    Player GetCell(int row, int col) const;         
    bool IsFull();            
    void Reset(); 
};
