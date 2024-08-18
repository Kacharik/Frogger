#include "Car.hpp"
Car::Car(float x, float y, float width, float height, float speed)
    : LaneObject(x, y, width, height, speed) {
    //here we set up the body of the car
    body.setPosition(x, y);
    body.setSize(sf::Vector2f(width, height * 0.6f)); //adjust height to simulate a car body
    body.setFillColor(sf::Color::Red); //set color for the car body
}
/*******************************************UPDATE*************************************************/
void Car::update() {
    // Move the car by a fixed speed value
    body.move(speed, 0);
    // Wrap around the screen
    if (speed > 0 && body.getPosition().x > 1450) {
        float newY = body.getPosition().y;
        body.setPosition(-body.getSize().x, newY);
    } else if (speed < 0 && body.getPosition().x + body.getSize().x < 0) {
        float newY = body.getPosition().y;
        body.setPosition(1300, newY);
    }
}
/*******************************************GETTERS*************************************************/
const sf::RectangleShape& Car::getShape() const {
    return body; //Return the body as the main shape for collision
}
const sf::Drawable& Car::getDrawable() const {
    return body; // Return the car body as the drawable
}
