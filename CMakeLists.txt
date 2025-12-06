cmake_minimum_required(VERSION 3.16)
project(TikTakToeProject LANGUAGES CXX)

add_subdirectory(libTikTakToe)
add_subdirectory(app)

# Add tests if building tests
option(BUILD_TESTS "Build unit tests" ON)
if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()