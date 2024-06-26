#ifndef LANE_OBJECT_HPP
#define LANE_OBJECT_HPP

#include "Rectangle.hpp" // Include the Rectangle class definition


class LaneObject : public Rectangle {
public:
    LaneObject(int x, int y, int width, int height, float position, float speed)
        : Rectangle(x, y, width, height), position(position), speed(speed) {}

    float getPosition() const { return position; }
    void setPosition(float pos) { position = pos; }

    float getSpeed() const { return speed; }

    void update(float deltaTime) {
        // Update the position based on speed and deltaTime
        position += speed * deltaTime;
        // Adjust the Rectangle's position accordingly
        Rectangle::setPosition(static_cast<int>(position), getY());
    }

private:
    float position; // Position along the lane
    float speed;    // Speed of the object
};

#endif // LANE_OBJECT_HPP
