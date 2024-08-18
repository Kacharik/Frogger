#include "LaneObject.hpp"

LaneObject::LaneObject(float x, float y, float width, float height, float speed)
    : speed(speed) {
    shape.setPosition(x, y);
    shape.setSize(sf::Vector2f(width, height));
}
//position
void LaneObject::setPosition(float x, float y) {
    shape.setPosition(x, y);
}
sf::Vector2f LaneObject::getPosition() const {
    return shape.getPosition();
}
//size
void LaneObject::setSize(float width, float height) {
    shape.setSize(sf::Vector2f(width, height));
}
sf::Vector2f LaneObject::getSize() const {
    return shape.getSize();
}
//speed
void LaneObject::setSpeed(float speed) {
    this->speed = speed;
}
float LaneObject::getSpeed() const {
    return speed;
}
