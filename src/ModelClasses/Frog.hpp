#ifndef FROG_HPP
#define FROG_HPP

#include "Rectangle.hpp"
#include <SFML/Graphics.hpp>

class Frog : protected Rectangle {

private:
    int windowWidth;
    int windowHeight;
    sf::RectangleShape body;

public:
    Frog(int x, int y, int width, int height, int windowWidth, int windowHeight);
    
    int getCurrentX() const;
    int getCurrentY() const;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void move(float offsetX, float offsetY);
    const sf::RectangleShape& getShape() const ;
    using Rectangle::getX;
    using Rectangle::getY;
    using Rectangle::getWidth;
    using Rectangle::getHeight;
    using Rectangle::setPosition;

    sf::FloatRect getFrogBounds() const;
    bool inBounds(int x, int y);

};

#endif
