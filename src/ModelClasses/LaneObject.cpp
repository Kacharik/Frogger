#include "LaneObject.hpp"

// Constructor
LaneObject::LaneObject(int x, int y, int width, int height, float position, float speed)
    : Rectangle(x, y, width, height), position(position), speed(speed) {}

float LaneObject::getPosition() const {
    return position;
}

void LaneObject::setPosition(float pos) {
    position = pos;
    // Also update the position of the underlying Rectangle
    Rectangle::setPosition(static_cast<int>(position), getY());
}

float LaneObject::getSpeed() const {
    return speed;
}

void LaneObject::update(float deltaTime) {
    position += speed * deltaTime;
    // Update the position of the underlying Rectangle
    Rectangle::setPosition(static_cast<int>(position), getY());
}
