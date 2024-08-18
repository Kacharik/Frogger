#include "Truck.hpp"
Truck::Truck(float x, float y, float width, float height, float speed)
    : LaneObject(x, y, width, height, speed) {
    //here we set up the body of the Truck
    body.setPosition(x, y);
    body.setSize(sf::Vector2f(width, height * 0.6f)); //adjust height to simulate a Truck body
    body.setFillColor(sf::Color::White); //set color for the Truck body
}
/*******************************************UPDATE*************************************************/
void Truck::update() {
    // Move the Truck by a fixed speed value
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
const sf::RectangleShape& Truck::getShape() const {
    return body; //Return the body as the main shape for collision
}
const sf::Drawable& Truck::getDrawable() const {
    return body; // Return the Truck body as the drawable
}
