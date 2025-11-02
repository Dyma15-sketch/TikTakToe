#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>
#include "player.hpp"

enum class PlayerType { None, X, O };

class Player {
private:
    PlayerType type;
    std::shared_ptr<std::string> name; // smart pointer pentru nume 
    std::vector<int> stats; // container STL pentru info. jucator

public:
    // Constructor implicit
    Player() : type(PlayerType::None), name(std::make_shared<std::string>("Unknown")) {}

    // Constructor cu parametri
    Player(PlayerType t, const std::string& playerName = "Player")
        : type(t), name(std::make_shared<std::string>(playerName)) {}

    // Constructor de copiere
    Player(const Player& other)
        : type(other.type), name(std::make_shared<std::string>(*other.name)), stats(other.stats) {}

    // Operator de atribuire
    Player& operator=(const Player& other) {
        if (this != &other) {
            type = other.type;
            name = std::make_shared<std::string>(*other.name);
            stats = other.stats;
        }
        return *this;
    }

    // Operator de comparare (algoritm STL)
    bool operator==(const Player& other) const {
        return type == other.type && *name == *other.name &&
               std::equal(stats.begin(), stats.end(), other.stats.begin(), other.stats.end());
    }

    // Operator de iesire 
    friend std::ostream& operator<<(std::ostream& os, const Player& player) {
        os << "Player: " << *player.name << " (";

        switch (player.type) {
            case PlayerType::X: os << "X"; break;
            case PlayerType::O: os << "O"; break;
            case PlayerType::None: os << "None"; break;
        }
        os << ")";
        if (!player.stats.empty()) {
            os << " | Stats: ";
            std::for_each(player.stats.begin(), player.stats.end(),
                          [&](int val) { os << val << " "; });
        }
        return os;
    }

    // Operator de intrare 
    friend std::istream& operator>>(std::istream& is, Player& player) {
        std::string typeInput, nameInput;
        std::cout << "Enter player type (X/O/None): ";
        is >> typeInput;
        std::cout << "Enter player name: ";
        is >> nameInput;

        std::transform(typeInput.begin(), typeInput.end(), typeInput.begin(), ::toupper);
        if (typeInput == "X") player.type = PlayerType::X;
        else if (typeInput == "O") player.type = PlayerType::O;
        else player.type = PlayerType::None;

        *player.name = nameInput;
        return is;
    }

    
    PlayerType GetType() const { return type; }
    void SetType(PlayerType t) { type = t; }



    std::string GetName() const { return *name; }
    void SetName(const std::string& newName) { *name = newName; }

    // Algoritmi STL pentru gestionarea statisticilor
    void AddStat(int value) {
        stats.push_back(value);
    }

    void SortStats() {
        std::sort(stats.begin(), stats.end());
    }

    void PrintStats() const {
        std::for_each(stats.begin(), stats.end(), [](int val) {
            std::cout << val << " ";
        });
        std::cout << std::endl;
    }
};


