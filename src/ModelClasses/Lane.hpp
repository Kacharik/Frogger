#ifndef LANE_HPP
#define LANE_HPP

#include <vector>
#include "LaneObject.hpp"

enum class LaneType {
    Road,
    River,
    Grass,
    Goal
};


class Lane {
public:
    Lane(LaneType type, int length, float speed, bool direction);

    LaneType getType() const;
    int getLength() const;
    float getSpeed() const;
    bool getDirection() const;
    const std::vector<LaneObject>& getObjects() const;

    void update(float deltaTime);

private:
    LaneType type;
    int length;
    float speed;
    bool direction; // true is left to right, false is opposite
    std::vector<LaneObject> objects;
    
    void initializeObjects();
};


#endif 