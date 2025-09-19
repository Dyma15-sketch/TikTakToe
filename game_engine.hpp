#pragma once
#include "board.hpp"
#include "rules.hpp"
#include "player.hpp"

class GameEngine {
    Board board;
    Player currentPlayer;
public:
    GameEngine();                     
    void Init();                        
    bool MakeMove(int row, int col);     
    Player GetCurrentPlayer() const;     
    void SwitchTurn();                  
    Player CheckWinner() const;          
    const Board& GetBoard() const;       
};
