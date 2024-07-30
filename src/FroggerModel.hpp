#ifndef FROGGERMODEL_HPP
#define FROGGERMODEL_HPP

#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include "Frog.hpp"
#include "Lane.hpp"

class FroggerModel {
public:
    FroggerModel(const sf::Vector2u& windowSize);
    Frog& getFrog();
    void update();
    
    // Add a getter for windowSize
    sf::Vector2u getWindowSize() const;

    const std::vector<Lane>& getLanes() const;

private:
    void initializeLanes();

    Frog frog;
    sf::Vector2u windowSize;
    std::vector<Lane> lanes;
};

#endif // FROGGERMODEL_HPP
