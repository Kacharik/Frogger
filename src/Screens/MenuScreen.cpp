#include "MenuScreen.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

MenuScreen::MenuScreen() {
}
/********************************DISPLAY****************************************/
void MenuScreen::display(sf::RenderWindow& window, int& selectedLevel) {
    sf::Text menuText;
    sf::Font font;
    if (!font.loadFromFile("assets/fonts/mine.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    } else {
        std::cout << "Font loaded successfully" << std::endl;
    }
    menuText.setFont(font);
    menuText.setString("Select Level:\n1. Level 1\n2. Level 2\n3. Level 3");
    menuText.setCharacterSize(24);
    menuText.setFillColor(sf::Color::White);

    window.clear();
    window.draw(menuText);
    window.display();

 /********************************INPUT HANDLING****************************************/
    sf::Event event;
    while (window.waitEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Num1) {
                selectedLevel = 1;
                break;
            } else if (event.key.code == sf::Keyboard::Num2) {
                selectedLevel = 2;
                break;
            } else if (event.key.code == sf::Keyboard::Num3) {
                selectedLevel = 3;
                break;
            }
        }
    }
}
