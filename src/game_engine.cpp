#include "GameEngine.hpp"


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



// Initializeaza jocul 
void GameEngine::Init() {
    board.Reset();
    currentPlayer = Player(PlayerType::X);
}

// Face o mutare pe tabla de joc 
bool GameEngine::MakeMove(int row, int col) {
    bool success = board.PlaceMark(row, col, currentPlayer);
    if (success) {
        SwitchTurn();
    }
    return success;
}

// Returneaza jucatorul curent 
Player GameEngine::GetCurrentPlayer() const {
    return currentPlayer;
}

// Schimba jucatorul curent 
void GameEngine::SwitchTurn() {
    if (currentPlayer.GetType() == PlayerType::X)
        currentPlayer.SetType(PlayerType::O);
    else if (currentPlayer.GetType() == PlayerType::O)
        currentPlayer.SetType(PlayerType::X);
}

// Verifica cine e castigatorul 
Player GameEngine::CheckWinner() {
    if (Rules::CheckWin(board, Player(PlayerType::X)))
        return Player(PlayerType::X);
    if (Rules::CheckWin(board, Player(PlayerType::O)))
        return Player(PlayerType::O);
    return Player(PlayerType::None);
}

// Returneaza tabla curenta
Board GameEngine::GetBoard() const {
    return board;
}


