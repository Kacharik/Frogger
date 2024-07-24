#ifndef LOG_HPP
#define LOG_HPP

#include "LaneObject.hpp"

class Log : public LaneObject {
public:
    Log(int x, int y, int width, int height, float position, float speed);
};

#endif // LOG_HPP