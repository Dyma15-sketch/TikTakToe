/**
 * @file rules.hpp
 * @brief Rules class definition for TikTakToe game
 * @author Ermurachi Dmitri
 * @date 2025
 * @copyright Copyright (c) 2025
 */

#pragma once
#include <iostream>
#include "board.hpp"
#include "player.hpp"

namespace ttt {

/**
 * @class Rules
 * @brief Static utility class for checking game rules and win conditions
 * 
 * The Rules class provides static methods to check win conditions and draw states
 * according to TikTakToe game rules. A player wins by having three marks in a row,
 * column, or diagonal. A draw occurs when the board is full with no winner.
 */
class Rules {
public:
    /**
     * @brief Default constructor
     * 
     * Creates a Rules object (all instances are equivalent)
     */
    Rules() = default;
    
    /**
     * @brief Copy constructor
     * @param other The Rules object to copy from
     * 
     * Creates a copy of the Rules object
     */
    Rules(const Rules& other) = default;
    
    /**
     * @brief Assignment operator
     * @param other The Rules object to assign from
     * @return Reference to this Rules object
     * 
     * Assigns from another Rules object (all Rules objects are equivalent)
     */
    Rules& operator=(const Rules& other) = default;
    
    /**
     * @brief Equality comparison operator
     * @param other The Rules object to compare with
     * @return Always returns true (all Rules objects are equivalent)
     * 
     * All Rules objects are considered equal since they represent the same game rules
     */
    bool operator==(const Rules& other) const { return true; }

    /**
     * @brief Check if a player has won
     * @param board The board to check
     * @param player The player to check for a win
     * @return true if the player has three marks in a row, column, or diagonal, false otherwise
     * 
     * Checks all possible winning combinations:
     * - Three in a row (horizontal)
     * - Three in a column (vertical)
     * - Three in a diagonal (both main and anti-diagonal)
     */
    static bool CheckWin(const Board& board, const Player& player);
    
    /**
     * @brief Check if the game is a draw
     * @param board The board to check
     * @return true if the board is full and no player has won, false otherwise
     * 
     * A draw occurs when all cells are occupied and neither player has won
     */
    static bool CheckDraw(const Board& board);

    /**
     * @brief Stream output operator
     * @param os The output stream
     * @param rules The Rules object to output
     * @return Reference to the output stream
     * 
     * Outputs a description of the TikTakToe rules
     */
    friend std::ostream& operator<<(std::ostream& os, const Rules& rules) {
        os << "TicTacToe rules\n";
        return os;
    }
    
    /**
     * @brief Stream input operator
     * @param is The input stream
     * @param r The Rules object to read into
     * @return Reference to the input stream
     * 
     * No-op input operator (Rules objects don't have state to read)
     */
    friend std::istream& operator>>(std::istream& is, Rules& r) {
        (void)is; (void)r; return is;
    }
};

}
