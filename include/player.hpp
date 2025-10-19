#pragma once
#include <iostream>

enum class PlayerType {
    None,
    X,
    O
};

class Player {
private:
    PlayerType type;

public:
   
    Player();
    Player(PlayerType t);
    Player(const Player& other);
    Player& operator=(const Player& other);
    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;  
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    friend std::istream& operator>>(std::istream& is, Player& player);

    
};


