#pragma once
#include "Board.hpp"
#include <iostream>

class AbstractVisual {
public:
    virtual void DrawBoard(const Board& board) const = 0;
    virtual void ShowMessage(const std::string& message) const = 0;
};
