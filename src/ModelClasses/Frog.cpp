#include "Frog.hpp"
#include <iostream>
Frog::Frog(int x, int y, int width, int height)
    : Rectangle(x, y, width, height) {}

void Frog::moveUp(){
    std::cout << "Moving Up" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    setPosition(getX(), getY() - 60);
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
}
;
void Frog::moveDown(){
    std::cout << "Moving down" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    setPosition(getX(), getY() + 60);
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveLeft(){
        std::cout << "Moving left" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    setPosition(getX()-60, getY());
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveRight(){
        std::cout << "Moving right" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    setPosition(getX()+60, getY());
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
