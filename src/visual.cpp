#include "Visual.hpp"
#include <iostream>

void Visual::DrawBoard(const Board& board) const {
    std::cout << board;
}

void Visual::ShowMessage(const std::string& message) const {
    std::cout << message << std::endl;
}

