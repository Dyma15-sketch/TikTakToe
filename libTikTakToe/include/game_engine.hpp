/**
 * @file game_engine.hpp
 * @brief GameEngine class definition for TikTakToe game
 * @author Ermurachi Dmitri
 * @date 2025
 * @copyright Copyright (c) 2025
 */

#pragma once
#include "board.hpp"
#include "player.hpp"
#include <iostream>

namespace ttt {

/**
 * @class GameEngine
 * @brief Main game engine that manages game state and logic
 * 
 * The GameEngine class coordinates the game board, current player, and game flow.
 * It handles moves, turn switching, winner checking, and draw detection.
 * This is the primary interface for managing a TikTakToe game session.
 */
class GameEngine {
public:
    /**
     * @brief Default constructor
     * 
     * Initializes a new game with an empty board and X as the starting player
     */
    GameEngine();
    
    /**
     * @brief Constructor with custom board and starting player
     * @param b The initial board state
     * @param startingPlayer The player who will make the first move
     * 
     * Creates a game engine with a pre-configured board and starting player
     */
    GameEngine(const Board& b, const Player& startingPlayer);
    
    /**
     * @brief Copy constructor
     * @param other The GameEngine object to copy from
     * 
     * Creates a copy of the game engine with the same board and current player
     */
    GameEngine(const GameEngine& other) = default;
    
    /**
     * @brief Assignment operator
     * @param other The GameEngine object to assign from
     * @return Reference to this GameEngine object
     * 
     * Assigns the board and current player from another game engine
     */
    GameEngine& operator=(const GameEngine& other) = default;

    /**
     * @brief Equality comparison operator
     * @param other The GameEngine object to compare with
     * @return true if both engines have the same board and current player, false otherwise
     * 
     * Compares two game engines for equality
     */
    bool operator==(const GameEngine& other) const;
    
    /**
     * @brief Stream output operator
     * @param os The output stream
     * @param engine The GameEngine object to output
     * @return Reference to the output stream
     * 
     * Outputs the current game state including the current player and board
     */
    friend std::ostream& operator<<(std::ostream& os, const GameEngine& engine);
    
    /**
     * @brief Stream input operator
     * @param is The input stream
     * @param engine The GameEngine object to read into
     * @return Reference to the input stream
     * 
     * Reads a game state from the stream (board and current player)
     */
    friend std::istream& operator>>(std::istream& is, GameEngine& engine);

    /**
     * @brief Initialize or reset the game
     * 
     * Resets the board to empty and sets the current player to X
     */
    void Init();
    
    /**
     * @brief Make a move on the board
     * @param row The row index (0-2) where to place the mark
     * @param col The column index (0-2) where to place the mark
     * @return true if the move was successful, false if the cell is occupied or coordinates are invalid
     * 
     * Places the current player's mark at the specified position and switches turns.
     * Returns false if the move cannot be made (cell occupied or invalid coordinates).
     */
    bool MakeMove(int row, int col);
    
    /**
     * @brief Get the current player
     * @return The Player whose turn it is
     * 
     * Returns the player who should make the next move
     */
    Player GetCurrentPlayer() const;
    
    /**
     * @brief Switch to the next player's turn
     * 
     * Alternates between X and O players
     */
    void SwitchTurn();
    
    /**
     * @brief Check if there is a winner
     * @return The winning Player, or PlayerType::None if no winner yet
     * 
     * Checks the board for a winning condition and returns the winning player.
     * Returns a Player with type None if no one has won yet.
     */
    Player CheckWinner();
    
    /**
     * @brief Check if the game is a draw
     * @return true if the board is full and no one has won, false otherwise
     * 
     * Determines if the game has ended in a draw (board full with no winner)
     */
    bool IsDraw() const;
    
    /**
     * @brief Get the current board state
     * @return A copy of the current board
     * 
     * Returns the current state of the game board
     */
    Board GetBoard() const;

private:
    Board board; ///< The 3x3 game board
    Player currentPlayer; ///< The player whose turn it is (X or O)
};

}
