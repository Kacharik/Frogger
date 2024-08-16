#ifndef FROGGERMODEL_HPP
#define FROGGERMODEL_HPP

#include <SFML/System.hpp>
#include <vector>
#include <iostream>
#include "Frog.hpp"
#include "Lane.hpp"
#include "Truck.hpp"
#include "Turtle.hpp"
class FroggerModel {
public:
    FroggerModel(const sf::Vector2u& windowSize);

    Frog& getFrog();
    void update();

    sf::Vector2u getWindowSize() const;
    const std::vector<Lane>& getLanes() const;
    void initializeLanes();
    void initializeFrogPosition();

    int getLaneHeight() const; // New method declaration
    int getGoalLaneY() const;  // New method declaration

    int getLives() const;
    void setLives(int lives);
    void decrementLives();

    int getScore() const;
    void incrementScore();

    void resetFrog();

    void occupyGoal(int x, int y);
    const std::vector<std::pair<int, int>>& getOccupiedGoals() const;
    const sf::Vector2f& getFrogStartingPosition() const;

private:
    

    Frog frog;
    sf::Vector2u windowSize;
    std::vector<Lane> lanes;

    int lives;
    int score;

    std::vector<std::pair<int, int>> occupiedGoals;
    sf::Vector2f frogStartingPosition;
};

#endif // FROGGERMODEL_HPP
