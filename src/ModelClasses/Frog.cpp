#include "Frog.hpp"
#include <iostream>

Frog::Frog(int x, int y, int width, int height, int windowWidth, int windowHeight)
    : Rectangle(x, y, width, height), windowWidth(windowWidth), windowHeight(windowHeight) {
    // Initialize the body shape
    body.setSize(sf::Vector2f(width, height));
    body.setPosition(x, y);
    body.setFillColor(sf::Color::Green); // or any color to distinguish the frog
}

/*********************************************MOVING*****************************************************/
void Frog::moveUp(){
    std::cout << "Moving Up" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newY = getY() - ((windowHeight - 20) / 13 );
    if (inBounds(getX(), newY)) {
        setPosition(getX(), newY);
        body.setPosition(getX(), newY);
    }
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveDown(){
    std::cout << "Moving down" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newY = getY() + ((windowHeight - 20) / 13 );
    if (inBounds(getX(), newY)) {
        setPosition(getX(), newY);
        body.setPosition(getX(), newY);
    }
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveLeft(){
        std::cout << "Moving left" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newX = getX() - 50;
    if (inBounds(newX, getY())) {
        setPosition(newX, getY());
        body.setPosition(newX, getY());
    }
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveRight(){
        std::cout << "Moving right" << std::endl;
    std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newX = getX() + 50;
    if (inBounds(newX, getY())) {
        setPosition(newX, getY());
        body.setPosition(newX, getY());
    }
    std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};


void Frog::move(float offsetX, float offsetY) {
    // Calculate the new position
    float newX = getX() + offsetX;
    float newY = getY() + offsetY;

    // Update the position of the Rectangle and the sf::RectangleShape
    Rectangle::setPosition(newX, newY);
    body.setPosition(newX, newY);
}

/*********************************************BOUNDS*****************************************************/
bool Frog::inBounds(int x, int y) {
    if (x < 0 || x + getWidth() > windowWidth || y < 0 || y + getHeight() > windowHeight - 20) {
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
const sf::RectangleShape& Frog::getShape() const {

    return body;
}
