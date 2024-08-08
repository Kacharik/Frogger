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

    sf::Vector2u getWindowSize() const;
    const std::vector<Lane>& getLanes() const;
    void initializeLanes();
    void initializeFrogPosition();

    int getLives() const;
    void setLives(int lives);
    void decrementLives();

    int getScore() const;
    void incrementScore();

private:
    

    Frog frog;
    sf::Vector2u windowSize;
    std::vector<Lane> lanes;

    int lives;
    int score;
};

#endif // FROGGERMODEL_HPP
