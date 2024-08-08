// Log.hpp
#ifndef LOG_HPP
#define LOG_HPP

#include "LaneObject.hpp"

class Log : public LaneObject {
public:
    Log(float x, float y, float width, float height, float speed);
    void update() override;
    const sf::Drawable& getDrawable() const override;
};

#endif // LOG_HPP
