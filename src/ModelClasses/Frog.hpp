#ifndef FROG_HPP
#define FROG_HPP

#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>

class Frog : private Rectangle {
private:
    int windowWidth;
    int windowHeight;

public:
    Frog(int x, int y, int width, int height, int windowWidth, int windowHeight);

    int getCurrentX() const;
    int getCurrentY() const;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    using Rectangle::getX;
    using Rectangle::getY;
    using Rectangle::getWidth;
    using Rectangle::getHeight;
    using Rectangle::setPosition;
    sf::FloatRect getFrogBounds() const;
    bool inBounds(int x, int y);

};

#endif