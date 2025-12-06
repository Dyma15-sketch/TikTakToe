#include "player.hpp"
#include <algorithm>
#include <string>

namespace ttt {


Player::Player() : type(PlayerType::None) {}
Player::Player(PlayerType t) : type(t) {}
Player::Player(const Player& other) : type(other.type) {}
Player& Player::operator=(const Player& other) {
    if (this != &other) type = other.type;
    return *this;
}

bool Player::operator==(const Player& other) const {
    return type == other.type;
}

PlayerType Player::GetType() const { return type; }
void Player::SetType(PlayerType t) { type = t; }

std::ostream& operator<<(std::ostream& os, const Player& player) {
    switch (player.type) {
        case PlayerType::X: os << 'X'; break;
        case PlayerType::O: os << 'O'; break;
        default: os << '-'; break;
    }
    return os;
}

std::istream& operator>>(std::istream& is, Player& player) {
    std::string token;
    if (!(is >> token)) return is;
    std::transform(token.begin(), token.end(), token.begin(), ::toupper);
    if (token == "X") player.type = PlayerType::X;
    else if (token == "O") player.type = PlayerType::O;
    else player.type = PlayerType::None;
    return is;
}

} 
