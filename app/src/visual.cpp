#include "visual.hpp"
#include <iostream>

#ifdef USE_SFML

#include <SFML/Graphics.hpp>
#endif

namespace ttt {

void Visual::DrawBoardConsole(const Board& board) const {
    std::cout << board << std::endl;
}

void Visual::ShowMessage(const std::string& message) const {
    std::cout << message << std::endl;
}

void Visual::DrawBoardSFML(const Board& board) const {
#ifdef USE_SFML
    const int cellSize = 100;
    const int gap = 10;
    sf::RenderWindow window(sf::VideoMode(cellSize*3 + gap*4, cellSize*3 + gap*4), "TicTacToe - SFML");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
       
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color::White);

        
        for (int r = 0; r < 3; ++r) {
            for (int c = 0; c < 3; ++c) {
                sf::RectangleShape rect(sf::Vector2f(cellSize, cellSize));
                rect.setPosition(gap + c*(cellSize+gap), gap + r*(cellSize+gap));
                rect.setOutlineColor(sf::Color::Black);
                rect.setOutlineThickness(2.f);
                rect.setFillColor(sf::Color(220,220,220));
                window.draw(rect);

                
                auto cell = board.GetCell(r,c);
                if (cell.GetType() == PlayerType::X || cell.GetType() == PlayerType::O) {
                    sf::Text txt;
                    txt.setFont(font);
                    txt.setString(cell.GetType() == PlayerType::X ? "X" : "O");
                    txt.setCharacterSize(48);
                    txt.setFillColor(sf::Color::Black);
                    txt.setPosition(gap + c*(cellSize+gap) + cellSize/3, gap + r*(cellSize+gap) + cellSize/6);
                    window.draw(txt);
                }
            }
        }

        window.display();
    }
#else
    (void)board;
    std::cerr << "SFML support not enabled. Compile with SFML to enable DrawBoardSFML.\n";
#endif
}

}

