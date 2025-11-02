#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
#include "GameEngine.hpp"
#include "Board.hpp"
#include "Rules.hpp"
#include "Player.hpp"

class GameEngine {
private:
    std::shared_ptr<Board> board;     
    std::shared_ptr<Player> currentPlayer; 
    std::shared_ptr<Rules> rules;     

public:
    // Constructor implicit
    GameEngine() {
        Init();
    }

    // Constructor cu parametri
    GameEngine(const Board& b, const Player& startingPlayer)
        : board(std::make_shared<Board>(b)),
          currentPlayer(std::make_shared<Player>(startingPlayer)),
          rules(std::make_shared<Rules>(*board)) {}

    // Constructor de copiere
    GameEngine(const GameEngine& other)
        : board(std::make_shared<Board>(*other.board)),
          currentPlayer(std::make_shared<Player>(*other.currentPlayer)),
          rules(std::make_shared<Rules>(*other.rules)) {}

    // Operator de atribuire
    GameEngine& operator=(const GameEngine& other) {
        if (this != &other) {
            board = std::make_shared<Board>(*other.board);
            currentPlayer = std::make_shared<Player>(*other.currentPlayer);
            rules = std::make_shared<Rules>(*other.rules);
        }
        return *this;
    }

    // Operator de egalitate
    bool operator==(const GameEngine& other) const {
        return *board == *other.board && *currentPlayer == *other.currentPlayer;
    }

    // Operator de iesire
    friend std::ostream& operator<<(std::ostream& os, const GameEngine& engine) {
        os << "=== Starea Jocului ===\n";
        os << "Jucător curent: " << *engine.currentPlayer << "\n";
        os << *engine.board;
        return os;
    }

    // Operator de intrare
    friend std::istream& operator>>(std::istream& is, GameEngine& engine) {
        std::cout << "Introduceți tabla de joc (3x3):\n";
        is >> *engine.board;
        std::cout << "Introduceți jucătorul curent (X, O, None): ";
        is >> *engine.currentPlayer;
        return is;
    }

    // Initializeaza jocul
    void Init() {
        board = std::make_shared<Board>();
        currentPlayer = std::make_shared<Player>(PlayerType::X);
        rules = std::make_shared<Rules>(*board);
    }

    // Face o mutare pe tabla de joc
    bool MakeMove(int row, int col) {
        if (board->PlaceMark(row, col, *currentPlayer)) {
            SwitchTurn();
            return true;
        }
        return false;
    }

    // Obtine jucatorul curent
    Player GetCurrentPlayer() const {
        return *currentPlayer;
    }

    // Schimba tura jucătorului
    void SwitchTurn() {
        if (currentPlayer->GetType() == PlayerType::X)
            currentPlayer->SetType(PlayerType::O);
        else if (currentPlayer->GetType() == PlayerType::O)
            currentPlayer->SetType(PlayerType::X);
    }

    // Verifica cine e castigatorul
    Player CheckWinner() const {
        if (rules->CheckWin(Player(PlayerType::X)))
            return Player(PlayerType::X);
        if (rules->CheckWin(Player(PlayerType::O)))
            return Player(PlayerType::O);
        return Player(PlayerType::None);
    }

    // Verifica remiza
    bool IsDraw() const {
        return rules->CheckDraw();
    }

    // Returneaza tabla curenta
    Board GetBoard() const {
        return *board;
    }
};


