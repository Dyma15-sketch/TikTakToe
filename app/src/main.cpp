#include <iostream>
#include <vector>
#include <algorithm>
#include "visual.hpp"
#include "game_engine.hpp"
#include "player.hpp"
#include "rules.hpp"

using namespace ttt;

int main() {
    GameEngine game;
    Visual visual;

    visual.ShowMessage("=== Jocul a fost inițializat ===");
    visual.DrawBoardConsole(game.GetBoard());

    visual.ShowMessage("Efectuam cateva mutari de test...");

    std::vector<std::pair<int,int>> moves = {{0,0},{1,1},{0,1},{2,2},{0,2}};
    for (auto mv : moves) {
        bool ok = game.MakeMove(mv.first, mv.second);
        std::cout << "Mutare ("<<mv.first<<","<<mv.second<<") " << (ok ? "reusita" : "esuata") << "\n";
        visual.DrawBoardConsole(game.GetBoard());
    }

    Player winner = game.CheckWinner();
    if (winner.GetType() != PlayerType::None) {
        std::cout << "Castigator: " << winner << "\n";
    } else if (Rules::CheckDraw(game.GetBoard())) {
        std::cout << "Este remiza!\n";
    } else {
        std::cout << "Jocul continua...\n";
    }

    return 0;
}

