/**
 * @file test_rules.cpp
 * @brief Unit tests for Rules class
 * @author Ermurachi Dmitri
 * @date 2025
 */

#include "test_framework.hpp"
#include "rules.hpp"
#include "board.hpp"
#include "player.hpp"

using namespace ttt;
using namespace test;

void test_rules_horizontal_win() {
    Board b;
    Player x(PlayerType::X);
    Player o(PlayerType::O);
    
    // Row 0: X X X
    b.PlaceMark(0, 0, x);
    b.PlaceMark(0, 1, x);
    b.PlaceMark(0, 2, x);
    
    ASSERT_TRUE(Rules::CheckWin(b, x));
    ASSERT_FALSE(Rules::CheckWin(b, o));
    
    // Row 1: O O O
    Board b2;
    b2.PlaceMark(1, 0, o);
    b2.PlaceMark(1, 1, o);
    b2.PlaceMark(1, 2, o);
    
    ASSERT_TRUE(Rules::CheckWin(b2, o));
    ASSERT_FALSE(Rules::CheckWin(b2, x));
    
    // Row 2: X X X
    Board b3;
    b3.PlaceMark(2, 0, x);
    b3.PlaceMark(2, 1, x);
    b3.PlaceMark(2, 2, x);
    
    ASSERT_TRUE(Rules::CheckWin(b3, x));
}

void test_rules_vertical_win() {
    Board b;
    Player x(PlayerType::X);
    Player o(PlayerType::O);
    
    // Column 0: X X X
    b.PlaceMark(0, 0, x);
    b.PlaceMark(1, 0, x);
    b.PlaceMark(2, 0, x);
    
    ASSERT_TRUE(Rules::CheckWin(b, x));
    ASSERT_FALSE(Rules::CheckWin(b, o));
    
    // Column 1: O O O
    Board b2;
    b2.PlaceMark(0, 1, o);
    b2.PlaceMark(1, 1, o);
    b2.PlaceMark(2, 1, o);
    
    ASSERT_TRUE(Rules::CheckWin(b2, o));
    
    // Column 2: X X X
    Board b3;
    b3.PlaceMark(0, 2, x);
    b3.PlaceMark(1, 2, x);
    b3.PlaceMark(2, 2, x);
    
    ASSERT_TRUE(Rules::CheckWin(b3, x));
}

void test_rules_diagonal_win() {
    Board b;
    Player x(PlayerType::X);
    Player o(PlayerType::O);
    
    // Main diagonal (top-left to bottom-right): X X X
    b.PlaceMark(0, 0, x);
    b.PlaceMark(1, 1, x);
    b.PlaceMark(2, 2, x);
    
    ASSERT_TRUE(Rules::CheckWin(b, x));
    ASSERT_FALSE(Rules::CheckWin(b, o));
    
    // Anti-diagonal (top-right to bottom-left): O O O
    Board b2;
    b2.PlaceMark(0, 2, o);
    b2.PlaceMark(1, 1, o);
    b2.PlaceMark(2, 0, o);
    
    ASSERT_TRUE(Rules::CheckWin(b2, o));
    ASSERT_FALSE(Rules::CheckWin(b2, x));
}

void test_rules_no_win() {
    Board b;
    Player x(PlayerType::X);
    Player o(PlayerType::O);
    
    // No winning combination
    b.PlaceMark(0, 0, x);
    b.PlaceMark(0, 1, o);
    b.PlaceMark(1, 1, x);
    
    ASSERT_FALSE(Rules::CheckWin(b, x));
    ASSERT_FALSE(Rules::CheckWin(b, o));
}

void test_rules_check_draw() {
    Board b;
    Player x(PlayerType::X);
    Player o(PlayerType::O);
    
    // Empty board is not a draw
    ASSERT_FALSE(Rules::CheckDraw(b));
    
    // Fill board without winner (draw scenario)
    // X O X
    // O X O
    // O X O
    b.PlaceMark(0, 0, x); b.PlaceMark(0, 1, o); b.PlaceMark(0, 2, x);
    b.PlaceMark(1, 0, o); b.PlaceMark(1, 1, x); b.PlaceMark(1, 2, o);
    b.PlaceMark(2, 0, o); b.PlaceMark(2, 1, x); b.PlaceMark(2, 2, o);
    
    ASSERT_TRUE(b.IsFull());
    ASSERT_FALSE(Rules::CheckWin(b, x));
    ASSERT_FALSE(Rules::CheckWin(b, o));
    ASSERT_TRUE(Rules::CheckDraw(b));
}

void test_rules_check_draw_with_winner() {
    Board b;
    Player x(PlayerType::X);
    Player o(PlayerType::O);
    
    // Fill board with winner (not a draw)
    // X X X
    // O O -
    // - - -
    b.PlaceMark(0, 0, x); b.PlaceMark(0, 1, x); b.PlaceMark(0, 2, x);
    b.PlaceMark(1, 0, o); b.PlaceMark(1, 1, o);
    
    ASSERT_TRUE(Rules::CheckWin(b, x));
    ASSERT_FALSE(Rules::CheckDraw(b));
}

void test_rules_check_draw_partial_board() {
    Board b;
    Player x(PlayerType::X);
    Player o(PlayerType::O);
    
    // Partial board is not a draw
    b.PlaceMark(0, 0, x);
    b.PlaceMark(0, 1, o);
    b.PlaceMark(1, 1, x);
    
    ASSERT_FALSE(b.IsFull());
    ASSERT_FALSE(Rules::CheckDraw(b));
}

void run_rules_tests() {
    TestSuite suite("Rules Tests");
    
    std::cout << "Running Rules tests...\n";
    
    RUN_TEST(suite, "Horizontal Win", test_rules_horizontal_win);
    RUN_TEST(suite, "Vertical Win", test_rules_vertical_win);
    RUN_TEST(suite, "Diagonal Win", test_rules_diagonal_win);
    RUN_TEST(suite, "No Win", test_rules_no_win);
    RUN_TEST(suite, "Check Draw", test_rules_check_draw);
    RUN_TEST(suite, "Check Draw with Winner", test_rules_check_draw_with_winner);
    RUN_TEST(suite, "Check Draw Partial Board", test_rules_check_draw_partial_board);
    
    suite.printSummary();
}

