#pragma once
#include "Player.hpp"
#include <iostream>

class Board {
private:
    Player cells[3][3];

public:
    Board();
    Board(const Player& initialPlayer); 
    Board(const Board& other);
    Board& operator=(const Board& other);
    bool operator==(const Board& other) const;
    bool operator!=(const Board& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
    friend std::istream& operator>>(std::istream& is, Board& board);
    
    bool PlaceMark(int row, int col, Player player);
    Player GetCell(int row, int col) const;
    bool IsFull() const;
    void Reset();
};

