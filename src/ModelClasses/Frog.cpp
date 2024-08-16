#include "Frog.hpp"
#include <iostream>


Frog::Frog(int x, int y, int width, int height, int windowWidth, int windowHeight)
    : Rectangle(x, y, width, height), windowWidth(windowWidth), windowHeight(windowHeight) {}


void Frog::moveUp(){
    std::cout << "Moving Up" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newY = getY() - ((windowHeight - 20) / 13 );
    if (inBounds(getX(), newY)) {
        setPosition(getX(), newY);
    }
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
}
;
void Frog::moveDown(){
    std::cout << "Moving down" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newY = getY() + ((windowHeight - 20) / 13 );
    if (inBounds(getX(), newY)) {
        setPosition(getX(), newY);
    }
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveLeft(){
        std::cout << "Moving left" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newX = getX() - 50;
    if (inBounds(newX, getY())) {
        setPosition(newX, getY());
    }
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveRight(){
        std::cout << "Moving right" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newX = getX() + 50;
    if (inBounds(newX, getY())) {
        setPosition(newX, getY());
    }
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};

bool Frog::inBounds(int x, int y) {
    if (x < 0 || x + getWidth() > windowWidth || y < 0 || y + getHeight() > windowHeight - 40) {
        return false;
    }
    return true;
}


sf::FloatRect Frog::getFrogBounds() const {
    return sf::FloatRect(getX(), getY(), getWidth(), getHeight());
}

int Frog::getCurrentX() const {
    return getX();
}

int Frog::getCurrentY() const {
    return getY();
}
