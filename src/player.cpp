#include "player.hpp"


// Constructor implicit
Player::Player() : type(PlayerType::None) {}

// Constructor cu parametri 
Player::Player(PlayerType t) : type(t) {}

// Constructor de copiere 
Player::Player(const Player& other) : type(other.type) {}

// Operator de atribuire 
Player& Player::operator=(const Player& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}

// Operator de comparare
bool Player::operator==(const Player& other) const {
    return type == other.type;
}

// Operator de iesire 
std::ostream& operator<<(std::ostream& os, const Player& player) {
    switch (player.type) {
        case PlayerType::X: os << "X"; break;
        case PlayerType::O: os << "O"; break;
        case PlayerType::None: os << "None"; break;
    }
    return os;
}

// Operator de intrare 
std::istream& operator>>(std::istream& is, Player& player) {
    std::string input;
    is >> input;

    if (input == "X" || input == "x") player.type = PlayerType::X;
    else if (input == "O" || input == "o") player.type = PlayerType::O;
    else player.type = PlayerType::None;

    return is;
}

   
    PlayerType Player::GetType() const {
        return type;
    }

    void Player::SetType(PlayerType t) {
        type = t;
    }



