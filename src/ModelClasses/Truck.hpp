#ifndef TRUCK_HPP
#define TRUCK_HPP

#include "LaneObject.hpp"

class Truck : public LaneObject {
public:
    Truck(int x, int y, int width, int height, float position, float speed);
};

#endif // TRUCK_HPP