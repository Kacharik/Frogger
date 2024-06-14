#include "Frog.hpp"

Frog::Frog(int x, int y, int width, int height)
    : Rectangle(x, y, width, height) {}

void Frog::moveUp(){
    setPosition(getX(), getY() - 1);
};
void Frog::moveDown(){
    setPosition(getX(), getY() + 1);
};
void Frog::moveLeft(){
    setPosition(getX() - 1, getY());
};
void Frog::moveRight(){
    setPosition(getX() + 1, getY());
};