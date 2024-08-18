#ifndef LANE_HPP
#define LANE_HPP

#include <vector>
#include "LaneObject.hpp"

enum class LaneType { Road, River, Grass, Goal };

class Lane {
public:
    Lane(LaneType type, float length, float speed, bool direction);



    LaneType getType() const;
    const std::vector<LaneObject*>& getObjects() const;
    void addObject(LaneObject* object);
    ~Lane();

private:
    LaneType type;
    float length;
    float speed;
    bool direction;
    std::vector<LaneObject*> objects; // Store pointers to LaneObject
};

#endif // LANE_HPP
