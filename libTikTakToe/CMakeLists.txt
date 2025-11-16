cmake_minimum_required(VERSION 3.16)
project(TikTakToeLib LANGUAGES CXX)

add_library(TikTakToe STATIC
    src/player.cpp
    src/board.cpp
    src/rules.cpp
    src/game_engine.cpp
)

target_include_directories(TikTakToe PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(TikTakToe PUBLIC cxx_std_17)

