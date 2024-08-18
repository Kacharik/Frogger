#ifndef INTROSCREEN_HPP
#define INTROSCREEN_HPP

#include <SFML/Graphics.hpp>
#include <iostream>

class IntroScreen {
public:
    IntroScreen();
    void display(sf::RenderWindow& window);

private:
    sf::Font font;
    sf::Text introText;
    sf::Text nameText;
};

#endif // INTROSCREEN_HPP