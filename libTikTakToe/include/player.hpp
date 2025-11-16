#pragma once
#include <iostream>

namespace ttt {

enum class PlayerType { None, X, O };

class Player {
public:
    Player();
    explicit Player(PlayerType t);
    Player(const Player& other);
    Player& operator=(const Player& other);

    bool operator==(const Player& other) const;

    PlayerType GetType() const;
    void SetType(PlayerType t);

    
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    friend std::istream& operator>>(std::istream& is, Player& player);

private:
    PlayerType type;
};

} 


