#include "game_engine.hpp"
#include "rules.hpp"

namespace ttt {

GameEngine::GameEngine() { Init(); }
GameEngine::GameEngine(const Board& b, const Player& startingPlayer)
    : board(b), currentPlayer(startingPlayer) {}

bool GameEngine::operator==(const GameEngine& other) const {
    return board == other.board && currentPlayer == other.currentPlayer;
}

std::ostream& operator<<(std::ostream& os, const GameEngine& engine) {
    os << "=== Game State ===\n";
    os << "Current: " << engine.currentPlayer << "\n";
    os << engine.board;
    return os;
}

std::istream& operator>>(std::istream& is, GameEngine& engine) {
    is >> engine.board;
    is >> engine.currentPlayer;
    return is;
}

void GameEngine::Init() {
    board.Reset();
    currentPlayer = Player(PlayerType::X);
}

bool GameEngine::MakeMove(int row, int col) {
    if (board.PlaceMark(row, col, currentPlayer)) {
        SwitchTurn();
        return true;
    }
    return false;
}

Player GameEngine::GetCurrentPlayer() const { return currentPlayer; }

void GameEngine::SwitchTurn() {
    if (currentPlayer.GetType() == PlayerType::X) currentPlayer.SetType(PlayerType::O);
    else currentPlayer.SetType(PlayerType::X);
}

Player GameEngine::CheckWinner() {
    Player x(PlayerType::X), o(PlayerType::O);
    if (Rules::CheckWin(board, x)) return x;
    if (Rules::CheckWin(board, o)) return o;
    return Player(PlayerType::None);
}

bool GameEngine::IsDraw() const {
    return Rules::CheckDraw(board);
}

Board GameEngine::GetBoard() const { return board; }

} 




