/**
 * @file player.hpp
 * @brief Player class definition for TikTakToe game
 * @author Ermurachi Dmitri
 * @date 2025
 * @copyright Copyright (c) 2025
 */

#pragma once
#include <iostream>

namespace ttt {

/**
 * @enum PlayerType
 * @brief Enumeration representing the type of player in the game
 * 
 * Defines the possible states for a player: None (empty cell), X, or O
 */
enum class PlayerType { None, X, O };

/**
 * @class Player
 * @brief Represents a player in the TikTakToe game
 * 
 * The Player class encapsulates the player type (X, O, or None) and provides
 * methods to get and set the player type. It supports stream I/O operations
 * for serialization and display purposes.
 */
class Player {
public:
    /**
     * @brief Default constructor
     * 
     * Creates a Player with type None (empty cell)
     */
    Player();
    
    /**
     * @brief Constructor with player type
     * @param t The PlayerType to assign to this player
     * 
     * Creates a Player with the specified type (X, O, or None)
     */
    explicit Player(PlayerType t);
    
    /**
     * @brief Copy constructor
     * @param other The Player object to copy from
     * 
     * Creates a new Player with the same type as the other Player
     */
    Player(const Player& other);
    
    /**
     * @brief Assignment operator
     * @param other The Player object to assign from
     * @return Reference to this Player object
     * 
     * Assigns the type of the other Player to this Player
     */
    Player& operator=(const Player& other);

    /**
     * @brief Equality comparison operator
     * @param other The Player object to compare with
     * @return true if both players have the same type, false otherwise
     * 
     * Compares two Player objects for equality based on their type
     */
    bool operator==(const Player& other) const;

    /**
     * @brief Get the player type
     * @return The PlayerType of this player
     * 
     * Returns the current type of the player (X, O, or None)
     */
    PlayerType GetType() const;
    
    /**
     * @brief Set the player type
     * @param t The PlayerType to set
     * 
     * Changes the type of this player to the specified type
     */
    void SetType(PlayerType t);

    /**
     * @brief Stream output operator
     * @param os The output stream
     * @param player The Player object to output
     * @return Reference to the output stream
     * 
     * Outputs the player type to the stream: 'X' for X, 'O' for O, '-' for None
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
    
    /**
     * @brief Stream input operator
     * @param is The input stream
     * @param player The Player object to read into
     * @return Reference to the input stream
     * 
     * Reads a player type from the stream. Accepts "X", "O", or any other value for None
     */
    friend std::istream& operator>>(std::istream& is, Player& player);

private:
    PlayerType type; ///< The type of the player (X, O, or None)
};

}
