#pragma once
#include "Board.hpp"
#include "Rules.hpp"
#include "Player.hpp"
#include <iostream>

class GameEngine {
private:
    Board board;
    Player currentPlayer;

public:
    GameEngine();
    GameEngine(const Board& b, const Player& startingPlayer);
    GameEngine(const GameEngine& other);
    GameEngine& operator=(const GameEngine& other);
    bool operator==(const GameEngine& other) const;
    bool operator!=(const GameEngine& other) const;
    friend std::ostream& operator<<(std::ostream& os, const GameEngine& engine);
    friend std::istream& operator>>(std::istream& is, GameEngine& engine);


    void Init();
    bool MakeMove(int row, int col);
    Player GetCurrentPlayer() const;
    void SwitchTurn();
    Player CheckWinner();
    Board GetBoard() const;
};

