/*#ifndef HEART_HPP
#define HEART_HPP

#include <SFML/Graphics.hpp>

class Heart {
public:
    Heart(float x, float y, float size);
    Heart(const Heart& other); // Copy constructor
    Heart& operator=(const Heart& other); // Copy assignment operator

    void draw(sf::RenderWindow& window) const;

private:
    sf::CircleShape leftCircle;
    sf::CircleShape rightCircle;
    sf::ConvexShape triangle;
};

#endif // HEART_HPP*/ 
