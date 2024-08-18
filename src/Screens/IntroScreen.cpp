#include "IntroScreen.hpp"
#include <SFML/System.hpp> // For sf::Clock

IntroScreen::IntroScreen() {
    // Load a font
    if (!font.loadFromFile("assets/fonts/mine.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    } else {
        std::cout << "Font loaded successfully" << std::endl;
    }
/*********************************************THE TEXTS*******************************************************/
    introText.setFont(font);//the font 
    introText.setString("Welcome to Frogger!");//Welcome to Frogger!
    introText.setCharacterSize(48);//its size
    introText.setFillColor(sf::Color::White);//its color

    nameText.setFont(font);
    nameText.setString("Karthik Achari & Meryeme Lachhab");
    nameText.setCharacterSize(30);
    nameText.setFillColor(sf::Color::White);
}
/**********************************************DISPLAY******************************************************/
void IntroScreen::display(sf::RenderWindow& window) {
    //Center the texts
    sf::FloatRect textRect = introText.getLocalBounds();
    introText.setOrigin(textRect.width / 2, textRect.height / 2);
    introText.setPosition(window.getSize().x / 2, window.getSize().y / 2);
    sf::FloatRect nameRect = nameText.getLocalBounds();
    nameText.setOrigin(nameRect.width / 2, nameRect.height / 2);
    nameText.setPosition(window.getSize().x / 2, window.getSize().y / 3);
    //displaying
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