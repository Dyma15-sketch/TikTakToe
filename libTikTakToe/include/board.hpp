#pragma once
#include <vector>
#include <memory>
#include <ostream>
#include "player.hpp"

namespace ttt {

class Board {
public:
    Board();
    explicit Board(const Player& initialPlayer);
    Board(const Board& other);
    Board& operator=(const Board& other);
    bool operator==(const Board& other) const;

    
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
    friend std::istream& operator>>(std::istream& is, Board& board);

    bool PlaceMark(int row, int col, const Player& player);
    Player GetCell(int row, int col) const;
    bool IsFull() const;
    void Reset();

private:
    std::vector<std::vector<std::shared_ptr<Player>>> cells; 
};

} 

