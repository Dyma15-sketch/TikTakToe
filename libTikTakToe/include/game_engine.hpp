#pragma once
#include "board.hpp"
#include "player.hpp"
#include <iostream>

namespace ttt {

class GameEngine {
public:
    GameEngine();
    GameEngine(const Board& b, const Player& startingPlayer);
    GameEngine(const GameEngine& other) = default;
    GameEngine& operator=(const GameEngine& other) = default;

    bool operator==(const GameEngine& other) const;
    friend std::ostream& operator<<(std::ostream& os, const GameEngine& engine);
    friend std::istream& operator>>(std::istream& is, GameEngine& engine);

    void Init();
    bool MakeMove(int row, int col);
    Player GetCurrentPlayer() const;
    void SwitchTurn();
    Player CheckWinner();
    bool IsDraw() const;
    Board GetBoard() const;

private:
    Board board;
    Player currentPlayer;
};

} 