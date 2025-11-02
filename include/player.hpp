#pragma once
#include <iostream>

enum class PlayerType {
    None,
    X,
    O
};

class Player {
private:
    PlayerType type;

public:
   
    // Constructor implicit
    Player();

    // Constructor cu parametrii
    Player(PlayerType t);

    // Constructor de copiere
    Player(const Player& other);
    
    //Op. de atribuire
    Player& operator=(const Player& other);
    
    //Op. de comparare
    bool operator==(const Player& other) const;

    // Op. de iesire 
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    //Op. de intrare
    friend std::istream& operator>>(std::istream& is, Player& player);


    
    PlayerType GetType() const;
    void SetType(PlayerType t);
     
    void AddStat(int value);
    void SortStats();
    void PrintStats() const;
};


