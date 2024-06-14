#include "Rectangle.hpp"

Rectangle::Rectangle(int x, int y, int width, int height)
    : x(x), y(y), width(width), height(height) {}

int Rectangle::getX() const { return x; }
int Rectangle::getY() const { return y; }
int Rectangle::getWidth() const { return width; }
int Rectangle::getHeight() const { return height; }

void Rectangle::setPosition(int x, int y) {
    this->x = x;
    this->y = y;
}


void Rectangle::setSize(int width, int height) {
    this->width = width;
    this->height = height;
}

int Rectangle::getLeft() const { return x; }
int Rectangle::getRight() const { return x + width; }
int Rectangle::getTop() const { return y; }
int Rectangle::getBottom() const { return y + height; }

bool Rectangle::intersects(const Rectangle& other) const {
    return !(getRight() <= other.getLeft() ||
             getLeft() >= other.getRight() ||
             getBottom() <= other.getTop() ||
             getTop() >= other.getBottom());
}