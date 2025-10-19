#pragma once
#include "abstract_visual.hpp"

class Visual : public AbstractVisual {
public:
    void DrawBoard(const Board& board) const override;
    void ShowMessage(const std::string& message) const override;
};
