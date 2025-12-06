#include "rules.hpp"

namespace ttt {

bool Rules::CheckWin(const Board& board, const Player& player) {
    PlayerType p = player.GetType();

    
    for (int r = 0; r < 3; ++r)
        if (board.GetCell(r,0).GetType() == p &&
            board.GetCell(r,1).GetType() == p &&
            board.GetCell(r,2).GetType() == p)
            return true;

    
    for (int c = 0; c < 3; ++c)
        if (board.GetCell(0,c).GetType() == p &&
            board.GetCell(1,c).GetType() == p &&
            board.GetCell(2,c).GetType() == p)
            return true;

    
    if (board.GetCell(0,0).GetType() == p &&
        board.GetCell(1,1).GetType() == p &&
        board.GetCell(2,2).GetType() == p) return true;

    if (board.GetCell(0,2).GetType() == p &&
        board.GetCell(1,1).GetType() == p &&
        board.GetCell(2,0).GetType() == p) return true;

    return false;
}

bool Rules::CheckDraw(const Board& board) {
    Player x(PlayerType::X), o(PlayerType::O);
    return board.IsFull() && !CheckWin(board, x) && !CheckWin(board, o);
}

}
