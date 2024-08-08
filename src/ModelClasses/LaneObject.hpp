#ifndef LaneObject_HPP
#define LaneObject_HPP

#include <SFML/Graphics.hpp>

class LaneObject {
public:
    LaneObject(float x, float y, float width, float height, float speed);
    virtual ~LaneObject() {}
    //position
    void setPosition(float x, float y);
    sf::Vector2f getPosition() const;
    //size
    void setSize(float width, float height);
    sf::Vector2f getSize() const;
    //speed
    void setSpeed(float speed);
    float getSpeed() const;
    //update
    virtual void update() = 0; // Pure virtual function for updating object position
    virtual const sf::RectangleShape& getShape() const = 0; // Pure virtual function to get shape

    sf::RectangleShape shape;

protected:
    float speed;
};

#endif // LaneObject_HPP
