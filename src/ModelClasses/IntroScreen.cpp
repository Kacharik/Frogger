#include "IntroScreen.hpp"
#include <SFML/System.hpp> // For sf::Clock

IntroScreen::IntroScreen() {
    // Load a font
    if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) {
        // Handle error
        std::cerr << "Error loading font" << std::endl;
    }

    // Create a text object
    introText.setFont(font);
    introText.setString("Welcome to Frogger!");
    introText.setCharacterSize(48);
    introText.setFillColor(sf::Color::White);

    nameText.setFont(font);
    nameText.setString("Karthik Achari & Meryeme Lacchab");
    nameText.setCharacterSize(30);
    nameText.setFillColor(sf::Color::White);
}

void IntroScreen::display(sf::RenderWindow& window) {
    // Center the text
    sf::FloatRect textRect = introText.getLocalBounds();
    introText.setOrigin(textRect.width / 2, textRect.height / 2);
    introText.setPosition(window.getSize().x / 2, window.getSize().y / 2);

    sf::FloatRect nameRect = nameText.getLocalBounds();
    nameText.setOrigin(nameRect.width / 2, nameRect.height / 2);
    nameText.setPosition(window.getSize().x / 2, window.getSize().y / 3);

    sf::Clock clock;
    bool done = false;
    
    while (window.isOpen() && !done) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }

        if (clock.getElapsedTime().asSeconds() > 2) {
            done = true;
        }

        window.clear(sf::Color(0, 100, 0));
        window.draw(introText);
        window.draw(nameText);
        window.display();
    }
}
