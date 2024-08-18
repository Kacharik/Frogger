// Car.hpp
#ifndef CAR_HPP
#define CAR_HPP

#include "LaneObject.hpp"

class Car : public LaneObject {
public:
    Car(float x, float y, float width, float height, float speed);
    void update() override;
    const sf::RectangleShape& getShape() const override;
    const sf::Drawable& getDrawable() const override; // Pure virtual function to get drawable
private:
    sf::RectangleShape body; // Main body of the car
};
#endif // CAR_HPP
