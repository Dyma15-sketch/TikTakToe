/**
 * @file test_player.cpp
 * @brief Unit tests for Player class
 * @author Ermurachi Dmitri
 * @date 2025
 */

#include "test_framework.hpp"
#include "player.hpp"
#include <sstream>

using namespace ttt;
using namespace test;

void test_player_default_constructor() {
    Player p;
    ASSERT_TRUE(p.GetType() == PlayerType::None);
}

void test_player_constructor_with_type() {
    Player p1(PlayerType::X);
    ASSERT_TRUE(p1.GetType() == PlayerType::X);
    
    Player p2(PlayerType::O);
    ASSERT_TRUE(p2.GetType() == PlayerType::O);
    
    Player p3(PlayerType::None);
    ASSERT_TRUE(p3.GetType() == PlayerType::None);
}

void test_player_copy_constructor() {
    Player original(PlayerType::X);
    Player copy(original);
    
    ASSERT_TRUE(copy.GetType() == PlayerType::X);
    ASSERT_TRUE(original.GetType() == PlayerType::X);
    ASSERT_TRUE(copy == original);
}

void test_player_assignment() {
    Player p1(PlayerType::X);
    Player p2(PlayerType::O);
    
    ASSERT_TRUE(p1.GetType() == PlayerType::X);
    ASSERT_TRUE(p2.GetType() == PlayerType::O);
    
    p2 = p1;
    ASSERT_TRUE(p2.GetType() == PlayerType::X);
    ASSERT_TRUE(p1 == p2);
}

void test_player_equality() {
    Player p1(PlayerType::X);
    Player p2(PlayerType::X);
    Player p3(PlayerType::O);
    Player p4(PlayerType::None);
    
    ASSERT_TRUE(p1 == p2);
    ASSERT_FALSE(p1 == p3);
    ASSERT_FALSE(p1 == p4);
    ASSERT_FALSE(p3 == p4);
}

void test_player_get_type() {
    Player p1(PlayerType::X);
    Player p2(PlayerType::O);
    Player p3;
    
    ASSERT_TRUE(p1.GetType() == PlayerType::X);
    ASSERT_TRUE(p2.GetType() == PlayerType::O);
    ASSERT_TRUE(p3.GetType() == PlayerType::None);
}

void test_player_set_type() {
    Player p;
    
    p.SetType(PlayerType::X);
    ASSERT_TRUE(p.GetType() == PlayerType::X);
    
    p.SetType(PlayerType::O);
    ASSERT_TRUE(p.GetType() == PlayerType::O);
    
    p.SetType(PlayerType::None);
    ASSERT_TRUE(p.GetType() == PlayerType::None);
}

void test_player_stream_output() {
    Player p1(PlayerType::X);
    Player p2(PlayerType::O);
    Player p3(PlayerType::None);
    
    std::ostringstream oss1, oss2, oss3;
    oss1 << p1;
    oss2 << p2;
    oss3 << p3;
    
    ASSERT_EQ_STR("X", oss1.str());
    ASSERT_EQ_STR("O", oss2.str());
    ASSERT_EQ_STR("-", oss3.str());
}

void test_player_stream_input() {
    Player p;
    
    std::istringstream iss1("X");
    iss1 >> p;
    ASSERT_TRUE(p.GetType() == PlayerType::X);
    
    std::istringstream iss2("O");
    iss2 >> p;
    ASSERT_TRUE(p.GetType() == PlayerType::O);
    
    std::istringstream iss3("x");  // lowercase
    iss3 >> p;
    ASSERT_TRUE(p.GetType() == PlayerType::X);
    
    std::istringstream iss4("o");  // lowercase
    iss4 >> p;
    ASSERT_TRUE(p.GetType() == PlayerType::O);
    
    std::istringstream iss5("invalid");
    iss5 >> p;
    ASSERT_TRUE(p.GetType() == PlayerType::None);
}

void run_player_tests() {
    TestSuite suite("Player Tests");
    
    std::cout << "Running Player tests...\n";
    
    RUN_TEST(suite, "Default Constructor", test_player_default_constructor);
    RUN_TEST(suite, "Constructor with Type", test_player_constructor_with_type);
    RUN_TEST(suite, "Copy Constructor", test_player_copy_constructor);
    RUN_TEST(suite, "Assignment Operator", test_player_assignment);
    RUN_TEST(suite, "Equality Operator", test_player_equality);
    RUN_TEST(suite, "GetType", test_player_get_type);
    RUN_TEST(suite, "SetType", test_player_set_type);
    RUN_TEST(suite, "Stream Output", test_player_stream_output);
    RUN_TEST(suite, "Stream Input", test_player_stream_input);
    
    suite.printSummary();
}

