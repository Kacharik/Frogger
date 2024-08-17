#include "VictoryScreen.hpp"

void VictoryScreen::display(sf::RenderWindow& window) {
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        // Handle error
    }
    sf::Text winText("You Win!", font, 50);
    winText.setPosition(window.getSize().x / 2 - 100, window.getSize().y / 2 - 25);
    
    window.clear(sf::Color(144, 238, 144));
    window.draw(winText);
    window.display();
    
    sf::sleep(sf::seconds(3));  // Display win message for 3 seconds
}
