#ifndef FROG_HPP
#define FROG_HPP

#include "Rectangle.hpp"

class Frog : private Rectangle {
private:
    int windowWidth;
    int windowHeight;
    bool inBounds(int x, int y);
    
public:
    Frog(int x, int y, int width, int height, int windowWidth, int windowHeight);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    using Rectangle::getX;
    using Rectangle::getY;
    using Rectangle::getWidth;
    using Rectangle::getHeight;
    using Rectangle::setPosition;

};

#endif