// Car.hpp
#ifndef CAR_HPP
#define CAR_HPP

#include "LaneObject.hpp"

class Car : public LaneObject {
public:
    Car(float x, float y, float width, float height, float speed);
    void update() override;
};

#endif // CAR_HPP
