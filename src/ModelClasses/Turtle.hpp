#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "LaneObject.hpp"

class Turtle : public LaneObject {
public:
    Turtle(float x, float y, float width, float height, float speed);
    void update() override;
    virtual const sf::Drawable& getDrawable() const = 0;
};

#endif // TURTLE_HPP

