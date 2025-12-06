/**
 * @file test_board.cpp
 * @brief Unit tests for Board class
 * @author Ermurachi Dmitri
 * @date 2025
 */

#include "test_framework.hpp"
#include "board.hpp"
#include "player.hpp"
#include <sstream>

using namespace ttt;
using namespace test;

void test_board_default_constructor() {
    Board b;
    
    // All cells should be None
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_TRUE(b.GetCell(i, j).GetType() == PlayerType::None);
        }
    }
    
    ASSERT_FALSE(b.IsFull());
}

void test_board_constructor_with_initial_player() {
    Player initial(PlayerType::X);
    Board b(initial);
    
    // All cells should be X
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_TRUE(b.GetCell(i, j).GetType() == PlayerType::X);
        }
    }
    
    ASSERT_TRUE(b.IsFull());
}

void test_board_copy_constructor() {
    Board b1;
    Player p(PlayerType::X);
    b1.PlaceMark(0, 0, p);
    
    Board b2(b1);
    
    // Both boards should have the same state
    ASSERT_TRUE(b1.GetCell(0, 0).GetType() == PlayerType::X);
    ASSERT_TRUE(b2.GetCell(0, 0).GetType() == PlayerType::X);
    ASSERT_TRUE(b1 == b2);
    
    // Modifying one should not affect the other
    Player p2(PlayerType::O);
    b2.PlaceMark(1, 1, p2);
    ASSERT_FALSE(b1 == b2);
}

void test_board_assignment() {
    Board b1, b2;
    Player p(PlayerType::X);
    b1.PlaceMark(0, 0, p);
    
    b2 = b1;
    ASSERT_TRUE(b1 == b2);
    
    Player p2(PlayerType::O);
    b2.PlaceMark(1, 1, p2);
    ASSERT_FALSE(b1 == b2);
}

void test_board_place_mark() {
    Board b;
    Player p1(PlayerType::X);
    Player p2(PlayerType::O);
    
    // Valid placement
    ASSERT_TRUE(b.PlaceMark(0, 0, p1));
    ASSERT_TRUE(b.GetCell(0, 0).GetType() == PlayerType::X);
    
    // Cannot place in occupied cell
    ASSERT_FALSE(b.PlaceMark(0, 0, p2));
    
    // Valid placement in different cell
    ASSERT_TRUE(b.PlaceMark(1, 1, p2));
    ASSERT_TRUE(b.GetCell(1, 1).GetType() == PlayerType::O);
    
    // Invalid coordinates
    ASSERT_FALSE(b.PlaceMark(-1, 0, p1));
    ASSERT_FALSE(b.PlaceMark(0, -1, p1));
    ASSERT_FALSE(b.PlaceMark(3, 0, p1));
    ASSERT_FALSE(b.PlaceMark(0, 3, p1));
}

void test_board_get_cell() {
    Board b;
    Player p(PlayerType::X);
    
    b.PlaceMark(1, 2, p);
    ASSERT_TRUE(b.GetCell(1, 2).GetType() == PlayerType::X);
    
    // Invalid coordinates should return None
    ASSERT_TRUE(b.GetCell(-1, 0).GetType() == PlayerType::None);
    ASSERT_TRUE(b.GetCell(0, -1).GetType() == PlayerType::None);
    ASSERT_TRUE(b.GetCell(3, 0).GetType() == PlayerType::None);
    ASSERT_TRUE(b.GetCell(0, 3).GetType() == PlayerType::None);
}

void test_board_is_full() {
    Board b;
    Player p1(PlayerType::X);
    Player p2(PlayerType::O);
    
    ASSERT_FALSE(b.IsFull());
    
    // Fill the board
    int count = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (count % 2 == 0) {
                b.PlaceMark(i, j, p1);
            } else {
                b.PlaceMark(i, j, p2);
            }
            count++;
        }
    }
    
    ASSERT_TRUE(b.IsFull());
}

void test_board_reset() {
    Board b;
    Player p(PlayerType::X);
    
    // Fill some cells
    b.PlaceMark(0, 0, p);
    b.PlaceMark(1, 1, p);
    b.PlaceMark(2, 2, p);
    
    ASSERT_FALSE(b.GetCell(0, 0).GetType() == PlayerType::None);
    
    b.Reset();
    
    // All cells should be None after reset
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            ASSERT_TRUE(b.GetCell(i, j).GetType() == PlayerType::None);
        }
    }
    
    ASSERT_FALSE(b.IsFull());
}

void test_board_equality() {
    Board b1, b2;
    Player p(PlayerType::X);
    
    ASSERT_TRUE(b1 == b2);
    
    b1.PlaceMark(0, 0, p);
    ASSERT_FALSE(b1 == b2);
    
    b2.PlaceMark(0, 0, p);
    ASSERT_TRUE(b1 == b2);
}

void test_board_stream_output() {
    Board b;
    Player p1(PlayerType::X);
    Player p2(PlayerType::O);
    
    b.PlaceMark(0, 0, p1);
    b.PlaceMark(0, 1, p2);
    b.PlaceMark(1, 1, p1);
    
    std::ostringstream oss;
    oss << b;
    std::string output = oss.str();
    
    // Check that output contains X and O
    ASSERT_TRUE(output.find('X') != std::string::npos);
    ASSERT_TRUE(output.find('O') != std::string::npos);
}

void run_board_tests() {
    TestSuite suite("Board Tests");
    
    std::cout << "Running Board tests...\n";
    
    RUN_TEST(suite, "Default Constructor", test_board_default_constructor);
    RUN_TEST(suite, "Constructor with Initial Player", test_board_constructor_with_initial_player);
    RUN_TEST(suite, "Copy Constructor", test_board_copy_constructor);
    RUN_TEST(suite, "Assignment Operator", test_board_assignment);
    RUN_TEST(suite, "PlaceMark", test_board_place_mark);
    RUN_TEST(suite, "GetCell", test_board_get_cell);
    RUN_TEST(suite, "IsFull", test_board_is_full);
    RUN_TEST(suite, "Reset", test_board_reset);
    RUN_TEST(suite, "Equality Operator", test_board_equality);
    RUN_TEST(suite, "Stream Output", test_board_stream_output);
    
    suite.printSummary();
}

