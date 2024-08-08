#include "Turtle.hpp"

Turtle::Turtle(float x, float y, float width, float height, float speed)
    : LaneObject(x, y, width, height, speed) {
    shape.setFillColor(sf::Color(255,165,0)); // Set a distinct color for the turtle
    shape.setSize(sf::Vector2f(width, height)); // Set the size for the turtle
}
void Turtle::update() {
    shape.move(speed, 0); // Move horizontally based on speed
    // Add logic for wrapping around the screen or other behavior
    if (speed > 0 && shape.getPosition().x > 1450) {
        shape.setPosition(-shape.getSize().x, shape.getPosition().y);
    } else if (speed < 0 && shape.getPosition().x + shape.getSize().x < 0) {
        shape.setPosition(1300, shape.getPosition().y);
    }
}
const sf::RectangleShape& Turtle::getShape() const {
    return shape;
}

const sf::Drawable& Turtle::getDrawable() const {
    return shape;
}
