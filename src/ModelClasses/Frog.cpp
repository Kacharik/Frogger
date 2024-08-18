#include "Frog.hpp"
#include <iostream>

Frog::Frog(int x, int y, int width, int height, int windowWidth, int windowHeight)
    : Rectangle(x, y, width, height), windowWidth(windowWidth), windowHeight(windowHeight) {
    //initialize the body shape
    body.setSize(sf::Vector2f(width, height));
    body.setPosition(x, y);
    body.setFillColor(sf::Color::Green);
}
/*********************************************MOVING*****************************************************/
void Frog::moveUp(){
    //std::cout << "Moving Up" << std::endl; FOR DEBUGGING
    //std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newY = getY() - ((windowHeight - 20) / 13 );//value (windowHeight - 20) / 13 represents the height of a single lane
    //so the frog will be moved only by one lane 
    if (inBounds(getX(), newY)) {//if the new position is in the window
        setPosition(getX(), newY);//update the logical position of the frog 
        body.setPosition(getX(), newY);//update the visual position of the frog 
    }
    //std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveDown(){
    //std::cout << "Moving down" << std::endl; FOR DEBUGGING
    //std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newY = getY() + ((windowHeight - 20) / 13 );
    if (inBounds(getX(), newY)) {
        setPosition(getX(), newY);
        body.setPosition(getX(), newY);
    }
    //std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveLeft(){
    //std::cout << "Moving left" << std::endl;FOR DEBUGGING
    //std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newX = getX() - 50;
    if (inBounds(newX, getY())) {
        setPosition(newX, getY());
        body.setPosition(newX, getY());
    }
    //std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
void Frog::moveRight(){
    //std::cout << "Moving right" << std::endl;FOR DEBUGGING
    //std::cout << "Current Position: (" << getX() << ", " << getY() << ")" << std::endl;
    int newX = getX() + 50;
    if (inBounds(newX, getY())) {
        setPosition(newX, getY());
        body.setPosition(newX, getY());
    }
    //std::cout << "New Position: (" << getX() << ", " << getY() << ")" << std::endl;
};
//so can the frog float on the floating objects (log and turtle)
void Frog::move(float offsetX, float offsetY) {
    // Accumulate movement to ensure even small changes affect the position
    static float accumulatedOffsetX = 0;
    static float accumulatedOffsetY = 0;

    accumulatedOffsetX += offsetX;
    accumulatedOffsetY += offsetY;

    // Apply movement only if accumulated offset is significant
    if (std::abs(accumulatedOffsetX) >= 1.0f || std::abs(accumulatedOffsetY) >= 1.0f) {
        float newX = getX() + accumulatedOffsetX;
        float newY = getY() + accumulatedOffsetY;

        // Update the position of the Rectangle and the sf::RectangleShape
        Rectangle::setPosition(newX, newY);
        body.setPosition(newX, newY);

        // Reset accumulations
        accumulatedOffsetX = 0;
        accumulatedOffsetY = 0;
    }
}

/*********************************************GETTERS*****************************************************/
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
