#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include "GameEngine.hpp"
#include "Visual.hpp"
#include "Rules.hpp"
#include "Player.hpp"
#include "Board.hpp"

int main() {
    using std::cout;
    using std::endl;

  
    auto playerX = std::make_shared<Player>(PlayerType::X);
    auto playerO = std::make_shared<Player>(PlayerType::O);
    auto playerNone = std::make_shared<Player>();

    cout << "Testare operatori << pentru Player:\n";
    cout << "Player X: " << *playerX << "\nPlayer O: " << *playerO << "\nPlayer None: " << *playerNone << endl;

  
    cout << "\nTestare operator == : ";
    cout << ((*playerX == *playerO) ? "Egal" : "Diferit") << endl;

    Player pCopy = *playerX;
    cout << "Copie după X: " << pCopy << endl;

   
    auto game = std::make_shared<GameEngine>();
    Visual visual;
    visual.ShowMessage("\n=== Jocul a fost inițializat ===");
    visual.DrawBoard(game->GetBoard());

  
    visual.ShowMessage("\nEfectuăm câteva mutări de test...");

    std::vector<std::pair<int, int>> moves = {{0,0}, {1,1}, {0,1}, {2,2}, {0,2}};

    std::for_each(moves.begin(), moves.end(), [&](auto move) {
        bool success = game->MakeMove(move.first, move.second);
        cout << "Mutare (" << move.first << ", " << move.second << ") "
             << (success ? "reusita" : "esuată") << endl;
        visual.DrawBoard(game->GetBoard());
        cout << endl;
    });

  
    Rules rules;
    Player winner = game->CheckWinner();
    if (winner.GetType() != PlayerType::None) {
        cout << "\nCastigatorul este: " << winner << endl;
    } else if (rules.CheckDraw(game->GetBoard())) {
        cout << "\nEste remiza!" << endl;
    } else {
        cout << "\nJocul continua..." << endl;
    }


    cout << "\nCăutăm o celulă liberă..." << endl;
    std::vector<Player> allCells;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            allCells.push_back(game->GetBoard().GetCell(i, j));

    auto emptyCell = std::find_if(allCells.begin(), allCells.end(), [](const Player& cell) {
        return cell.GetType() == PlayerType::None;
    });

    if (emptyCell != allCells.end()) {
        cout << "Celula libera gasita!" << endl;
    } else {
        cout << "Tabla este plină!" << endl;
    }

    cout << "\n=== Testare finalizată cu succes ===" << endl;

    return 0;
}
