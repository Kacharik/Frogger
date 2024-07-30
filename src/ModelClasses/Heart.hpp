#ifndef HEART_HPP
#define HEART_HPP

#include <SFML/Graphics.hpp>

class Heart {
public:
    Heart(float x, float y, float size);

    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape leftCircle;
    sf::CircleShape rightCircle;
    sf::ConvexShape triangle;
};

#endif // HEART_HPP