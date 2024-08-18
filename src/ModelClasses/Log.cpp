// Log.cpp
#include "Log.hpp"
//same like cars and turtles...
Log::Log(float x, float y, float width, float height, float speed)
    : LaneObject(x, y, width, height, speed) {
    shape.setFillColor(sf::Color(139, 69, 19)); 
}
/***********************************UPDATE*******************************************/
void Log::update() {
    shape.move(speed, 0); //move horizontally based on speed
    if (speed > 0 && shape.getPosition().x > 1450) {
        shape.setPosition(-shape.getSize().x, shape.getPosition().y);
    } else if (speed < 0 && shape.getPosition().x + shape.getSize().x < 0) {
        shape.setPosition(1300, shape.getPosition().y);
    }
}
/***********************************GETTERS*******************************************/
const sf::RectangleShape& Log::getShape() const {
    return shape;
}
const sf::Drawable& Log::getDrawable() const {
    return shape;
}
