cmake_minimum_required(VERSION 3.16)
project(TikTakToeTests LANGUAGES CXX)

# Create test executable
add_executable(TikTakToeTests
    test_main.cpp
    test_player.cpp
    test_board.cpp
    test_rules.cpp
    test_game_engine.cpp
)

# Include directories
target_include_directories(TikTakToeTests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${PROJECT_SOURCE_DIR}/libTikTakToe/include
)

# Link against the TikTakToe library
target_link_libraries(TikTakToeTests PRIVATE TikTakToe)

# Set C++17 standard
target_compile_features(TikTakToeTests PRIVATE cxx_std_17)

# Add test to CTest (enable_testing() is called in root CMakeLists.txt)
add_test(NAME TikTakToeTests COMMAND TikTakToeTests)

