/**
 * @file test_game_engine.cpp
 * @brief Unit tests for GameEngine class
 * @author Ermurachi Dmitri
 * @date 2025
 */

#include "test_framework.hpp"
#include "game_engine.hpp"
#include "board.hpp"
#include "player.hpp"
#include "rules.hpp"

using namespace ttt;
using namespace test;

void test_game_engine_default_constructor() {
    GameEngine game;
    
    // Should start with empty board
    Board b = game.GetBoard();
    ASSERT_TRUE(b.GetCell(0, 0).GetType() == PlayerType::None);
    
    // Should start with player X
    ASSERT_TRUE(game.GetCurrentPlayer().GetType() == PlayerType::X);
}

void test_game_engine_constructor_with_board() {
    Board b;
    Player starting(PlayerType::O);
    GameEngine game(b, starting);
    
    ASSERT_TRUE(game.GetCurrentPlayer().GetType() == PlayerType::O);
    ASSERT_TRUE(game.GetBoard() == b);
}

void test_game_engine_init() {
    GameEngine game;
    
    // Make some moves
    game.MakeMove(0, 0);
    game.MakeMove(1, 1);
    
    // Reset
    game.Init();
    
    // Board should be empty
    Board b = game.GetBoard();
    ASSERT_TRUE(b.GetCell(0, 0).GetType() == PlayerType::None);
    ASSERT_TRUE(b.GetCell(1, 1).GetType() == PlayerType::None);
    
    // Current player should be X
    ASSERT_TRUE(game.GetCurrentPlayer().GetType() == PlayerType::X);
}

void test_game_engine_make_move() {
    GameEngine game;
    
    // First move by X
    ASSERT_TRUE(game.MakeMove(0, 0));
    Board b = game.GetBoard();
    ASSERT_TRUE(b.GetCell(0, 0).GetType() == PlayerType::X);
    
    // Current player should switch to O
    ASSERT_TRUE(game.GetCurrentPlayer().GetType() == PlayerType::O);
    
    // Second move by O
    ASSERT_TRUE(game.MakeMove(1, 1));
    b = game.GetBoard();
    ASSERT_TRUE(b.GetCell(1, 1).GetType() == PlayerType::O);
    
    // Current player should switch back to X
    ASSERT_TRUE(game.GetCurrentPlayer().GetType() == PlayerType::X);
}

void test_game_engine_make_move_invalid() {
    GameEngine game;
    
    // Valid move
    ASSERT_TRUE(game.MakeMove(0, 0));
    
    // Invalid: cell already occupied
    ASSERT_FALSE(game.MakeMove(0, 0));
    
    // Invalid: out of bounds
    ASSERT_FALSE(game.MakeMove(-1, 0));
    ASSERT_FALSE(game.MakeMove(0, -1));
    ASSERT_FALSE(game.MakeMove(3, 0));
    ASSERT_FALSE(game.MakeMove(0, 3));
}

void test_game_engine_switch_turn() {
    GameEngine game;
    
    ASSERT_TRUE(game.GetCurrentPlayer().GetType() == PlayerType::X);
    
    game.SwitchTurn();
    ASSERT_TRUE(game.GetCurrentPlayer().GetType() == PlayerType::O);
    
    game.SwitchTurn();
    ASSERT_TRUE(game.GetCurrentPlayer().GetType() == PlayerType::X);
}

void test_game_engine_check_winner_horizontal() {
    GameEngine game;
    
    // X wins horizontally (row 0)
    game.MakeMove(0, 0);  // X
    game.MakeMove(1, 0);  // O
    game.MakeMove(0, 1);  // X
    game.MakeMove(1, 1);  // O
    game.MakeMove(0, 2);  // X wins!
    
    Player winner = game.CheckWinner();
    ASSERT_TRUE(winner.GetType() == PlayerType::X);
}

void test_game_engine_check_winner_vertical() {
    GameEngine game;
    
    // O wins vertically (column 1)
    game.MakeMove(0, 0);  // X
    game.MakeMove(0, 1);  // O
    game.MakeMove(1, 0);  // X
    game.MakeMove(1, 1);  // O
    game.MakeMove(2, 0);  // X
    game.MakeMove(2, 1);  // O wins!
    
    Player winner = game.CheckWinner();
    ASSERT_TRUE(winner.GetType() == PlayerType::O);
}

void test_game_engine_check_winner_diagonal() {
    GameEngine game;
    
    // X wins on main diagonal
    game.MakeMove(0, 0);  // X
    game.MakeMove(0, 1);  // O
    game.MakeMove(1, 1);  // X
    game.MakeMove(0, 2);  // O
    game.MakeMove(2, 2);  // X wins!
    
    Player winner = game.CheckWinner();
    ASSERT_TRUE(winner.GetType() == PlayerType::X);
}

void test_game_engine_check_winner_anti_diagonal() {
    GameEngine game;
    
    // O wins on anti-diagonal (0,2) -> (1,1) -> (2,0)
    game.MakeMove(0, 0);  // X
    game.MakeMove(0, 2);  // O
    game.MakeMove(1, 0);  // X
    game.MakeMove(1, 1);  // O
    game.MakeMove(0, 1);  // X
    game.MakeMove(2, 0);  // O wins on anti-diagonal!
    
    Player winner = game.CheckWinner();
    ASSERT_TRUE(winner.GetType() == PlayerType::O);
}

void test_game_engine_check_winner_none() {
    GameEngine game;
    
    // No winner yet
    game.MakeMove(0, 0);
    game.MakeMove(0, 1);
    
    Player winner = game.CheckWinner();
    ASSERT_TRUE(winner.GetType() == PlayerType::None);
}

void test_game_engine_is_draw() {
    GameEngine game;
    
    // Create a draw scenario
    // X O X
    // O X O
    // O X O
    game.MakeMove(0, 0);  // X
    game.MakeMove(0, 1);  // O
    game.MakeMove(0, 2);  // X
    game.MakeMove(1, 0);  // O
    game.MakeMove(1, 1);  // X
    game.MakeMove(1, 2);  // O
    game.MakeMove(2, 0);  // X
    game.MakeMove(2, 1);  // O
    game.MakeMove(2, 2);  // X
    
    ASSERT_TRUE(game.IsDraw());
    Player winner = game.CheckWinner();
    ASSERT_TRUE(winner.GetType() == PlayerType::None);
}

void test_game_engine_get_board() {
    GameEngine game;
    Board initial = game.GetBoard();
    
    // Make a move
    game.MakeMove(0, 0);
    Board after = game.GetBoard();
    
    // Boards should be different
    ASSERT_FALSE(initial == after);
    ASSERT_TRUE(after.GetCell(0, 0).GetType() == PlayerType::X);
}

void test_game_engine_equality() {
    GameEngine game1;
    GameEngine game2;
    
    ASSERT_TRUE(game1 == game2);
    
    game1.MakeMove(0, 0);
    ASSERT_FALSE(game1 == game2);
    
    game2.MakeMove(0, 0);
    // Current players might be different after one move
    // Let's make both moves to sync
    game1.MakeMove(1, 1);
    game2.MakeMove(1, 1);
    ASSERT_TRUE(game1 == game2);
}

void run_game_engine_tests() {
    TestSuite suite("GameEngine Tests");
    
    std::cout << "Running GameEngine tests...\n";
    
    RUN_TEST(suite, "Default Constructor", test_game_engine_default_constructor);
    RUN_TEST(suite, "Constructor with Board", test_game_engine_constructor_with_board);
    RUN_TEST(suite, "Init", test_game_engine_init);
    RUN_TEST(suite, "MakeMove", test_game_engine_make_move);
    RUN_TEST(suite, "MakeMove Invalid", test_game_engine_make_move_invalid);
    RUN_TEST(suite, "SwitchTurn", test_game_engine_switch_turn);
    RUN_TEST(suite, "CheckWinner Horizontal", test_game_engine_check_winner_horizontal);
    RUN_TEST(suite, "CheckWinner Vertical", test_game_engine_check_winner_vertical);
    RUN_TEST(suite, "CheckWinner Diagonal", test_game_engine_check_winner_diagonal);
    RUN_TEST(suite, "CheckWinner Anti-Diagonal", test_game_engine_check_winner_anti_diagonal);
    RUN_TEST(suite, "CheckWinner None", test_game_engine_check_winner_none);
    RUN_TEST(suite, "IsDraw", test_game_engine_is_draw);
    RUN_TEST(suite, "GetBoard", test_game_engine_get_board);
    RUN_TEST(suite, "Equality Operator", test_game_engine_equality);
    
    suite.printSummary();
}

