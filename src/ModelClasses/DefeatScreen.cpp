#include "DefeatScreen.hpp"

void DefeatScreen::display(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        // Handle error
        
        return;
    }

    sf::Text defeatText("Game Over", font, 50);
    defeatText.setPosition(window.getSize().x / 2 - 150, window.getSize().y / 2 - 25);
    defeatText.setFillColor(sf::Color::White);

    window.clear(sf::Color(255, 0, 0)); // Set background color to red
    window.draw(defeatText);
    window.display();

    sf::sleep(sf::seconds(3));  // Display the message for 3 seconds
}
