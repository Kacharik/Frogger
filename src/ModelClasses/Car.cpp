// Car.cpp
#include "Car.hpp"

Car::Car(float x, float y, float width, float height, float speed)
    : LaneObject(x, y, width, height, speed) {
    shape.setFillColor(sf::Color::Red); // Example color
}

void Car::update() {
    shape.move(speed, 0); // Move horizontally based on speed
    // Add logic for wrapping around the screen or other behavior
    if (speed > 0 && shape.getPosition().x > 1300) {
        shape.setPosition(-shape.getSize().x, shape.getPosition().y);
    } else if (speed < 0 && shape.getPosition().x + shape.getSize().x < 0) {
        shape.setPosition(1300, shape.getPosition().y);
    }
}
