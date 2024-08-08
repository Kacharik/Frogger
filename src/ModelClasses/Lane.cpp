#include "Lane.hpp"

Lane::Lane(LaneType type, float length, float speed, bool direction)
    : type(type), length(length), speed(speed), direction(direction) {}

LaneType Lane::getType() const {
    return type;
}

const std::vector<LaneObject*>& Lane::getObjects() const {
    return objects;
}

void Lane::addObject(LaneObject* object) {
    objects.push_back(object);
}

Lane::~Lane() {
    // Clean up any dynamically allocated resources if needed
    for (auto obj : objects) {
        delete obj; // Assuming objects are dynamically allocated
    }
}
