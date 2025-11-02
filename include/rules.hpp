#pragma once
#include "Board.hpp"
#include <iostream>

class Rules {
private:
    Board board; 

public:
    // Constructor implicit
    Rules();

    // Constructor cu parametrii
    Rules(const Board& b);

    // Constructor de copiere
    Rules(const Rules& other);

    // Op. de atribuire
    Rules& operator=(const Rules& other);

    // Op. de comparare
    bool operator==(const Rules& other) const;

    // Op. de iesire
    friend std::ostream& operator<<(std::ostream& os, const Rules& rules);

    // Op. de intrare
    friend std::istream& operator>>(std::istream& is, Rules& rules);

  
    static bool CheckWin(Board& board, Player player);
    static bool CheckDraw(Board& board);
};
