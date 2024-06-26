#include "Lane.hpp"


Lane::Lane(LaneType type, int length, float speed, bool direction)
    : type(type), length(length), speed(speed), direction(direction) {
    initializeObjects();
}

LaneType Lane::getType() const {
    return type;
}

int Lane::getLength() const {
    return length;
}

float Lane::getSpeed() const {
    return speed;
}

bool Lane::getDirection() const {
    return direction;
}

void Lane::initializeObjects() {
    // Clear any existing objects (if reinitializing)
    objects.clear();

    // Example initialization, replace with your actual logic
    int numObjects = length / 50; // Adjust as needed based on lane length and object size
    int objectWidth = 30;
    int objectHeight = 30;
    float objectSpeed = speed; // Example speed for objects

    for (int i = 0; i < numObjects; ++i) {
        int x = i * 50; // Example positioning logic
        int y = 0; // Example positioning logic
        objects.emplace_back(x, y, objectWidth, objectHeight, x, objectSpeed);
    }
}

const std::vector<LaneObject>& Lane::getObjects() const {
    return objects;
}

void Lane::update(float deltaTime) {
    // Update object positions based on speed and direction
    // Placeholder logic, replace with actual update logic
    for (auto& object : objects) {
        object.update(deltaTime);
        // Update object position
    }
}
