#include "player.hpp"


Player::Player() : type(PlayerType::None) {}


Player::Player(PlayerType t) : type(t) {}


Player::Player(const Player& other) : type(other.type) {}


Player& Player::operator=(const Player& other) {
    if (this != &other) {
        type = other.type;
    }
    return *this;
}


bool Player::operator==(const Player& other) const {
    return type == other.type;
}


bool Player::operator!=(const Player& other) const {
    return type != other.type;
}


std::ostream& operator<<(std::ostream& os, const Player& player) {
    switch (player.type) {
        case PlayerType::X: os << "X"; break;
        case PlayerType::O: os << "O"; break;
        case PlayerType::None: os << "None"; break;
    }
    return os;
}


std::istream& operator>>(std::istream& is, Player& player) {
    std::string input;
    is >> input;

    if (input == "X" || input == "x") player.type = PlayerType::X;
    else if (input == "O" || input == "o") player.type = PlayerType::O;
    else player.type = PlayerType::None;

    return is;
}



