/**
 * @file board.hpp
 * @brief Board class definition for TikTakToe game
 * @author Ermurachi Dmitri
 * @date 2025
 * @copyright Copyright (c) 2025
 */

#pragma once
#include <vector>
#include <memory>
#include <ostream>
#include "player.hpp"

namespace ttt {

/**
 * @class Board
 * @brief Represents the 3x3 game board for TikTakToe
 * 
 * The Board class manages a 3x3 grid of cells, each containing a Player object.
 * It provides methods to place marks, check cell contents, reset the board,
 * and determine if the board is full. The board uses shared pointers to
 * manage Player objects efficiently.
 */
class Board {
public:
    /**
     * @brief Default constructor
     * 
     * Creates an empty board with all cells set to PlayerType::None
     */
    Board();
    
    /**
     * @brief Constructor with initial player
     * @param initialPlayer The Player to initialize all cells with
     * 
     * Creates a board with all cells set to the specified player type
     */
    explicit Board(const Player& initialPlayer);
    
    /**
     * @brief Copy constructor
     * @param other The Board object to copy from
     * 
     * Creates a deep copy of the board with independent Player objects
     */
    Board(const Board& other);
    
    /**
     * @brief Assignment operator
     * @param other The Board object to assign from
     * @return Reference to this Board object
     * 
     * Performs a deep copy assignment, copying all cell values
     */
    Board& operator=(const Board& other);
    
    /**
     * @brief Equality comparison operator
     * @param other The Board object to compare with
     * @return true if both boards have identical cell values, false otherwise
     * 
     * Compares two boards cell by cell for equality
     */
    bool operator==(const Board& other) const;

    /**
     * @brief Stream output operator
     * @param os The output stream
     * @param board The Board object to output
     * @return Reference to the output stream
     * 
     * Outputs the board in a formatted 3x3 grid with separators
     */
    friend std::ostream& operator<<(std::ostream& os, const Board& board);
    
    /**
     * @brief Stream input operator
     * @param is The input stream
     * @param board The Board object to read into
     * @return Reference to the input stream
     * 
     * Reads a board state from the stream, cell by cell
     */
    friend std::istream& operator>>(std::istream& is, Board& board);

    /**
     * @brief Place a mark on the board
     * @param row The row index (0-2)
     * @param col The column index (0-2)
     * @param player The Player to place
     * @return true if the mark was placed successfully, false if the cell is occupied or coordinates are invalid
     * 
     * Attempts to place a player's mark at the specified position.
     * Returns false if the cell is already occupied or if coordinates are out of bounds.
     */
    bool PlaceMark(int row, int col, const Player& player);
    
    /**
     * @brief Get the player at a specific cell
     * @param row The row index (0-2)
     * @param col The column index (0-2)
     * @return The Player at the specified cell, or PlayerType::None if coordinates are invalid
     * 
     * Retrieves the player occupying the cell at the given coordinates.
     * Returns a Player with type None if coordinates are out of bounds.
     */
    Player GetCell(int row, int col) const;
    
    /**
     * @brief Check if the board is full
     * @return true if all cells are occupied, false otherwise
     * 
     * Determines whether every cell on the board contains a non-None player
     */
    bool IsFull() const;
    
    /**
     * @brief Reset the board to empty state
     * 
     * Clears all cells and sets them to PlayerType::None
     */
    void Reset();

private:
    std::vector<std::vector<std::shared_ptr<Player>>> cells; ///< 3x3 grid of cells, each containing a shared pointer to a Player
};

}
