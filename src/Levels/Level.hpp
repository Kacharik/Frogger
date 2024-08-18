// Level.hpp
#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>
#include "../ModelClasses/Lane.hpp"
#include "../ModelClasses/Lane.hpp"
#include "../ModelClasses/Truck.hpp"
#include "../ModelClasses/Turtle.hpp"
#include "../ModelClasses/Car.hpp"
#include "../ModelClasses/Log.hpp"

class Level {
public:
    Level(int number, const sf::Vector2u& windowSize);
    void initializeLanes();

    const std::vector<Lane>& getLanes() const;

private:
    int levelNumber;
    sf::Vector2u windowSize;
    std::vector<Lane> lanes;

    void configureLevel1();
    void configureLevel2();
    // Add more configuration methods as needed
};

#endif // LEVEL_HPP
