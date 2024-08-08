#include "Car.hpp"

Car::Car(float x, float y, float width, float height, float speed)
    : LaneObject(x, y, width, height, speed) {
    
    // Set up the body of the car
    body.setPosition(x, y);
    body.setSize(sf::Vector2f(width, height * 0.6f));  // Adjust height to simulate a car body
    body.setFillColor(sf::Color::Red);  // Set color for the car body

    // Set up the front wheel
    frontWheel.setRadius(width * 0.1f);  // Smaller radius for wheel
    frontWheel.setFillColor(sf::Color::Black);
    frontWheel.setOrigin(frontWheel.getRadius(), frontWheel.getRadius());
    frontWheel.setPosition(x + width * 0.2f, y + height * 0.6f);

    // Set up the rear wheel
    rearWheel.setRadius(width * 0.1f);  // Smaller radius for wheel
    rearWheel.setFillColor(sf::Color::Black);
    rearWheel.setOrigin(rearWheel.getRadius(), rearWheel.getRadius());
    rearWheel.setPosition(x + width * 0.8f, y + height * 0.6f);
}

void Car::update() {
    // Move the car by a fixed speed value
    body.move(speed, 0);

    // Move the wheels with the body
    frontWheel.move(speed, 0);
    rearWheel.move(speed, 0);

    // Wrap around the screen
    if (speed > 0 && body.getPosition().x > 1450) {
        float newY = body.getPosition().y;
        body.setPosition(-body.getSize().x, newY);
        frontWheel.setPosition(-body.getSize().x + body.getSize().x * 0.2f, newY + body.getSize().y);
        rearWheel.setPosition(-body.getSize().x + body.getSize().x * 0.8f, newY + body.getSize().y);
    } else if (speed < 0 && body.getPosition().x + body.getSize().x < 0) {
        float newY = body.getPosition().y;
        body.setPosition(1300, newY);
        frontWheel.setPosition(1300 + body.getSize().x * 0.2f, newY + body.getSize().y);
        rearWheel.setPosition(1300 + body.getSize().x * 0.8f, newY + body.getSize().y);
    }
}
const sf::Drawable& Car::getDrawable() const {
    return body; // Return the car body as the drawable
}

void Car::render(sf::RenderWindow& window) const {
    // Draw each component of the car
    window.draw(body);
    window.draw(frontWheel);
    window.draw(rearWheel);
}
