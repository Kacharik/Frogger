#ifndef FROGGERMODEL_HPP
#define FROGGERMODEL_HPP

#include "Frog.hpp"
#include "Lane.hpp"
#include <vector>
#include <SFML/System/Vector2.hpp>

class FroggerModel {
public:
    FroggerModel(const sf::Vector2u& windowSize);

    Frog& getFrog();
    const std::vector<Lane>& getLanes() const;
    void update();

private:
    Frog frog;
    std::vector<Lane> lanes;
    sf::Vector2u windowSize;

    void initializeLanes();
};

#endif // FROGGERMODEL_HPP
