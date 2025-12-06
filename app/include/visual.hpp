/**
 * @file visual.hpp
 * @brief Visual class definition for TikTakToe game display
 * @author Ermurachi Dmitri
 * @date 2025
 * @copyright Copyright (c) 2025
 */

#pragma once
#include "board.hpp"
#include <string>

namespace ttt {

/**
 * @class Visual
 * @brief Handles visual representation and display of the game
 * 
 * The Visual class provides methods to display the game board and messages
 * in different formats. It supports both console-based text output and
 * SFML-based graphical rendering (when SFML is available).
 */
class Visual {
public:
    /**
     * @brief Default constructor
     * 
     * Creates a Visual object for rendering game displays
     */
    Visual() = default;
    
    /**
     * @brief Draw the board to the console
     * @param board The Board object to display
     * 
     * Outputs the board state to the standard output stream in a formatted
     * text representation suitable for console display
     */
    void DrawBoardConsole(const Board& board) const;
    
    /**
     * @brief Display a message to the console
     * @param message The message string to display
     * 
     * Outputs a message to the standard output stream followed by a newline
     */
    void ShowMessage(const std::string& message) const;
    
    /**
     * @brief Draw the board using SFML graphics
     * @param board The Board object to display
     * 
     * Renders the board in a graphical window using SFML (if available).
     * Opens a window displaying the board with X and O marks. The window
     * remains open until the user closes it.
     * 
     * @note This method requires SFML to be linked. If SFML is not available,
     *       it will output an error message to stderr.
     */
    void DrawBoardSFML(const Board& board) const;
};

}
