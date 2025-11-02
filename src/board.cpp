#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <iterator>
#include <string>
#include "Player.hpp"

class Board {
private:
    std::vector<std::vector<std::shared_ptr<Player>>> cells;
public:
    // Constructor implicit
    Board() {
        Reset();
    }

    // Constructor cu parametru (umple tabla cu un anumit jucator)
    Board(const Player& initialPlayer) {
        cells.resize(3, std::vector<std::shared_ptr<Player>>(3, std::make_shared<Player>(initialPlayer)));
    }

    // Constructor de copiere
    Board(const Board& other) {
        cells.resize(3, std::vector<std::shared_ptr<Player>>(3));
        for (size_t i = 0; i < 3; ++i)
            for (size_t j = 0; j < 3; ++j)
                cells[i][j] = std::make_shared<Player>(*other.cells[i][j]);
    }

    // Operator de atribuire
    Board& operator=(const Board& other) {
        if (this != &other) {
            for (size_t i = 0; i < 3; ++i)
                for (size_t j = 0; j < 3; ++j)
                    *cells[i][j] = *other.cells[i][j];
        }
        return *this;
    }

    // Operator de comparare (algoritmi STL)
    bool operator==(const Board& other) const {
        return std::equal(cells.begin(), cells.end(), other.cells.begin(),
            [](const auto& rowA, const auto& rowB) {
                return std::equal(rowA.begin(), rowA.end(), rowB.begin(),
                    [](const auto& cellA, const auto& cellB) {
                        return *cellA == *cellB;
                    });
            });
    }

    // Operator de iesire 
    friend std::ostream& operator<<(std::ostream& os, const Board& board) {
        for (size_t i = 0; i < 3; ++i) {
            for (size_t j = 0; j < 3; ++j) {
                os << *board.cells[i][j];
                if (j < 2) os << " | ";
            }
            os << "\n";
            if (i < 2) os << "--+---+--\n";
        }
        return os;
    }

    // Operator de intrare 
    friend std::istream& operator>>(std::istream& is, Board& board) {
        std::cout << "Introduceți tabla (3x3) folosind X, O sau None:\n";
        for (size_t i = 0; i < 3; ++i)
            for (size_t j = 0; j < 3; ++j)
                is >> *board.cells[i][j];
        return is;
    }

    // Plaseaza o marca pe o celula
    bool PlaceMark(int row, int col, const Player& player) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3)
            return false;

        if (cells[row][col]->GetType() == PlayerType::None) {
            *cells[row][col] = player;
            return true;
        }
        return false;
    }

    // Obtine o celula
    Player GetCell(int row, int col) const {
        if (row < 0 || row >= 3 || col < 0 || col >= 3)
            return Player(PlayerType::None);
        return *cells[row][col];
    }

    // Verifica daca tabla e plina (algoritm STL)
    bool IsFull() const {
        return std::all_of(cells.begin(), cells.end(),
            [](const auto& row) {
                return std::all_of(row.begin(), row.end(),
                    [](const auto& cell) {
                        return cell->GetType() != PlayerType::None;
                    });
            });
    }

    // Reseteaza tabla
    void Reset() {
        cells.resize(3, std::vector<std::shared_ptr<Player>>(3));
        for (auto& row : cells)
            std::generate(row.begin(), row.end(), []() {
                return std::make_shared<Player>(PlayerType::None);
            });
    }
};



