// Truck.hpp
#ifndef Truck_HPP
#define Truck_HPP

#include "LaneObject.hpp"

class Truck : public LaneObject {
public:
    Truck(float x, float y, float width, float height, float speed);
    void update() override;
    const sf::RectangleShape& getShape() const override;
    const sf::Drawable& getDrawable() const override; // Pure virtual function to get drawable
    
private:
    sf::RectangleShape body; // Main body of the Truck
  
};
#endif // Truck_HPP
