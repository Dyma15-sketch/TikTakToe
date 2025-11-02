#pragma once
#include "Player.hpp"
#include <iostream>

class Board {
private:
    Player cells[3][3];

public:
    // Constructor implicit
    Board();

    // Constructor cu parametrii
    Board(const Player& initialPlayer); 

    // Constructor de copiere
    Board(const Board& other);

    //Op. de atribuire
    Board& operator=(const Board& other);

    //Op. de comparare
    bool operator==(const Board& other) const;

    // Op. de iesire 
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
    
    //Op. de intrare
    friend std::istream& operator>>(std::istream& is, Board& board);

    
    bool PlaceMark(int row, int col, Player player);
    Player GetCell(int row, int col) const;
    bool IsFull() const;
    void Reset();
};

