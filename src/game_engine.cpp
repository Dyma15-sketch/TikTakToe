#include "game_engine.hpp"


GameEngine::GameEngine() {
    Init();
}

GameEngine::GameEngine(const Board& b, const Player& startingPlayer)
    : board(b), currentPlayer(startingPlayer) {}


GameEngine::GameEngine(const GameEngine& other)
    : board(other.board), currentPlayer(other.currentPlayer) {}


GameEngine& GameEngine::operator=(const GameEngine& other) {
    if (this != &other) {
        board = other.board;
        currentPlayer = other.currentPlayer;
    }
    return *this;
}


bool GameEngine::operator==(const GameEngine& other) const {
    return (board == other.board && currentPlayer == other.currentPlayer);
}


bool GameEngine::operator!=(const GameEngine& other) const {
    return !(*this == other);
}


std::ostream& operator<<(std::ostream& os, const GameEngine& engine) {
    os << "Jucător curent: " << engine.currentPlayer << "\n";
    os << engine.board;
    return os;
}


std::istream& operator>>(std::istream& is, GameEngine& engine) {
    std::cout << "Introduceți tabla de joc:\n";
    is >> engine.board;
    std::cout << "Introduceți jucătorul curent (X, O sau None): ";
    is >> engine.currentPlayer;
    return is;
}


void GameEngine::Init() {
    board.Reset();
    currentPlayer = Player(PlayerType::X);
}

bool GameEngine::MakeMove(int row, int col) {}
Player GameEngine::GetCurrentPlayer() const {
    return currentPlayer;
}

void GameEngine::SwitchTurn() {}
Player GameEngine::CheckWinner() {}
Board GameEngine::GetBoard() const {
    return board;
}

