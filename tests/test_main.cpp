/**
 * @file test_main.cpp
 * @brief Main test runner for all unit tests
 * @author Ermurachi Dmitri
 * @date 2025
 */

#include "test_framework.hpp"
#include <iostream>

// Forward declarations
void run_player_tests();
void run_board_tests();
void run_rules_tests();
void run_game_engine_tests();

int main() {
    std::cout << "========================================\n";
    std::cout << "   TikTakToe Unit Tests\n";
    std::cout << "========================================\n\n";
    
    int totalPassed = 0;
    int totalFailed = 0;
    
    // Run all test suites
    run_player_tests();
    run_board_tests();
    run_rules_tests();
    run_game_engine_tests();
    
    std::cout << "========================================\n";
    std::cout << "   Test Summary\n";
    std::cout << "========================================\n";
    
    // Note: Individual suite summaries are printed by each suite
    // This is a placeholder for overall summary if needed
    
    std::cout << "\nAll tests completed!\n";
    
    return 0;
}

