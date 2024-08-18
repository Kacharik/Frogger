#include "DefeatScreen.hpp"

void DefeatScreen::display(sf::RenderWindow& window) {
    sf::Font font;

    if (!font.loadFromFile("assets/fonts/mine.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    } else {
        std::cout << "Font loaded successfully" << std::endl;
    }
    

    sf::Text defeatText("Game Over", font, 50);//Game Over
    defeatText.setPosition(window.getSize().x / 2 - 150, window.getSize().y / 2 - 25);//its position
    defeatText.setFillColor(sf::Color::White);

    window.clear(sf::Color(255, 0, 0)); // Set background color to red
    window.draw(defeatText);
    window.display();

    sf::sleep(sf::seconds(3));  // Display the message for 3 seconds
}
