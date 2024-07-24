#ifndef CAR_HPP
#define CAR_HPP

#include "LaneObject.hpp"

class Car : public LaneObject {
public:
    Car(int x, int y, int width, int height, float position, float speed);
};

#endif // CAR_HPP