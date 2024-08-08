#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "LaneObject.hpp"

class Turtle : public LaneObject {
public:
    Turtle(float x, float y, float width, float height, float speed);
    void update() override;
const sf::RectangleShape& getShape() const override; // Implement this method
    const sf::Drawable& getDrawable() const override; // Implement this method
};

#endif // TURTLE_HPP

