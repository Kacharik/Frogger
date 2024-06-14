#ifndef FROG_HPP
#define FROG_HPP

#include "Rectangle.hpp"

class Frog : private Rectangle {
private:

public:
    Frog(int x, int y, int width, int height);

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