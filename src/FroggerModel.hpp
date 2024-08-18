#ifndef FROGGERMODEL_HPP
#define FROGGERMODEL_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Lanes/Lane.hpp"
#include "ModelClasses/Frog.hpp"
#include "Levels/Level.hpp"
#include "ModelClasses/Car.hpp"
#include "ModelClasses/Turtle.hpp"
#include "ModelClasses/Log.hpp"
#include "ModelClasses/Truck.hpp"

class FroggerModel {
public:
    // Constructor that takes a window size and a level number
    FroggerModel(const sf::Vector2u& windowSize, int levelNumber);
    
    // Other member functions and variables
    Frog& getFrog();
    void update();
    sf::Vector2u getWindowSize() const;
    const std::vector<Lane>& getLanes() const;
    void initializeLanes();
    void resetFrog();
    int getLives() const;
    void setLives(int newLives);
    void decrementLives();
    int getScore() const;
    void incrementScore();
    void initializeFrogPosition();
    int getLaneHeight() const;
    int getGoalLaneY() const;
    const std::vector<std::pair<int, int>>& getOccupiedGoals() const;
    void occupyGoal(int x, int y);
    const sf::Vector2f& getFrogStartingPosition() const;
    void checkCollisions();
    bool checkWinCondition();
    bool getHasWon() const;

private:
    sf::Vector2u windowSize;
    Frog frog;
    Level currentLevel; // This should be a data member
    std::vector<Lane> lanes;
    std::vector<std::pair<int, int>> occupiedGoals;
    int lives;
    int score;
    bool hasWon;
    sf::Vector2f frogStartingPosition;
};

#endif // FROGGERMODEL_HPP
