#pragma once
#include "board.hpp"
#include <string>

namespace ttt {

class Visual {
public:
    Visual() = default;
    
    void DrawBoardConsole(const Board& board) const;
    void ShowMessage(const std::string& message) const;
    
    void DrawBoardSFML(const Board& board) const;
};

} 
