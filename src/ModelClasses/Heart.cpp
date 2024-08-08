/*#include "Heart.hpp"

Heart::Heart(float x, float y, float size) {
    float radius = size / 2;

    // Configure the left circle
    leftCircle.setRadius(radius);
    leftCircle.setFillColor(sf::Color::Red);
    leftCircle.setPosition(x - radius, y);

    // Configure the right circle
    rightCircle.setRadius(radius);
    rightCircle.setFillColor(sf::Color::Red);
    rightCircle.setPosition(x + radius, y);

    // Configure the triangle
    triangle.setPointCount(3);
    triangle.setFillColor(sf::Color::Red);
    triangle.setPoint(0, sf::Vector2f(x - radius, y + radius));
    triangle.setPoint(1, sf::Vector2f(x + 3 * radius, y + radius));
    triangle.setPoint(2, sf::Vector2f(x + radius, y + 2 * size));
}

// Copy constructor
Heart::Heart(const Heart& other) {
    leftCircle = other.leftCircle;
    rightCircle = other.rightCircle;
    triangle = other.triangle;
}

// Copy assignment operator
Heart& Heart::operator=(const Heart& other) {
    if (this != &other) {
        leftCircle = other.leftCircle;
        rightCircle = other.rightCircle;
        triangle = other.triangle;
    }
    return *this;
}


void Heart::draw(sf::RenderWindow& window) const{
    window.draw(leftCircle);
    window.draw(rightCircle);
    window.draw(triangle);
}

*/
