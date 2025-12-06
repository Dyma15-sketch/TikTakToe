cmake_minimum_required(VERSION 3.16)
project(TikTakToeApp LANGUAGES CXX)

add_executable(TikTakToeApp
    src/main.cpp
    src/visual.cpp
)

# Include-uri pentru aplicație
target_include_directories(TikTakToeApp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/libTikTakToe/include
)

target_link_libraries(TikTakToeApp PRIVATE TikTakToe)

# SFML detect
find_package(SFML 2.5 COMPONENTS graphics window system OPTIONAL_COMPONENTS)
if (SFML_FOUND)
    target_compile_definitions(TikTakToeApp PRIVATE USE_SFML=1)
    target_link_libraries(TikTakToeApp PRIVATE sfml-graphics sfml-window sfml-system)
endif()

target_compile_features(TikTakToeApp PRIVATE cxx_std_17)

