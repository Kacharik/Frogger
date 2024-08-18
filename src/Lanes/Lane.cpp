#include "Lane.hpp"
//each lane has a type , a lenth , speed , and direction
Lane::Lane(LaneType type, float length, float speed, bool direction)
    : type(type), length(length), speed(speed), direction(direction) {}

LaneType Lane::getType() const {
    return type;
}

const std::vector<LaneObject*>& Lane::getObjects() const {
    return objects;
}
//to add objects on the lanes as cars etc ...
void Lane::addObject(LaneObject* object) {
    objects.push_back(object);
}

Lane::~Lane() {
    // Clean up any dynamically allocated resources if needed
    for (auto obj : objects) {
        delete obj; // Assuming objects are dynamically allocated
    }
}
