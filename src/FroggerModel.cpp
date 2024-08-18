#include "FroggerModel.hpp"
#include <iostream>

FroggerModel::FroggerModel(const sf::Vector2u& windowSize, int levelNumber)
    : windowSize(windowSize),
      frog((windowSize.x / 2) - 15, windowSize.y - 70, 40, 40, windowSize.x, windowSize.y),
      lives(3),
      score(0),
      hasWon(false),
      frogStartingPosition((windowSize.x / 2) - 15, windowSize.y - 70),
      currentLevel(levelNumber, windowSize) { // Initialize current level
    std::cout << "Model initialized with window size: " << windowSize.x << "x" << windowSize.y << std::endl;
    initializeLanes();
}

Frog& FroggerModel::getFrog() {
    return frog;
}

void FroggerModel::update() {
    for (auto& lane : lanes) {
        for (auto object : lane.getObjects()) {
            object->update();
        }
    }
    checkCollisions();
}

sf::Vector2u FroggerModel::getWindowSize() const {
    return windowSize;
}

const std::vector<Lane>& FroggerModel::getLanes() const {
    return lanes;
}

void FroggerModel::initializeLanes() {
    lanes.clear();
    currentLevel.initializeLanes(); // Initialize lanes from Level class
    lanes = currentLevel.getLanes(); // Set lanes in FroggerModel
}

void FroggerModel::resetFrog() {
    initializeFrogPosition();
}

int FroggerModel::getLives() const {
    return lives;
}

void FroggerModel::setLives(int newLives) {
    lives = newLives;
}

void FroggerModel::decrementLives() {
    if (lives > 0) {
        --lives;
        if (lives <= 0) {
            // Handle game over condition
            std::cout << "Game Over!" << std::endl;
        }
    }
}

int FroggerModel::getScore() const {
    return score;
}

void FroggerModel::incrementScore() {
    score++;
}

void FroggerModel::initializeFrogPosition() {
    frog.setPosition(frogStartingPosition.x, frogStartingPosition.y);
}

int FroggerModel::getLaneHeight() const {
    return (windowSize.y - 20) / lanes.size();
}

int FroggerModel::getGoalLaneY() const {
    // The first lane is the goal lane
    return 0;
}

const std::vector<std::pair<int, int>>& FroggerModel::getOccupiedGoals() const {
    return occupiedGoals;
}

void FroggerModel::occupyGoal(int x, int y) {
    occupiedGoals.emplace_back(x, y);
}

const sf::Vector2f& FroggerModel::getFrogStartingPosition() const {
    return frogStartingPosition;
}

void FroggerModel::checkCollisions() {
    bool onFloatingObject = false; // Check if frog is on a log or turtle
    int laneHeight = windowSize.y / lanes.size(); // Assuming uniform lane height

    for (int i = 0; i < lanes.size(); ++i) {
        const Lane& lane = lanes[i];
        float laneY = i * laneHeight; // Calculate the Y position of the lane

        // Check if the frog is within the current lane's vertical boundaries
        if (frog.getY() >= laneY && frog.getY() < laneY + laneHeight) {
            if (lane.getType() == LaneType::Road) {
                for (const auto& object : lane.getObjects()) {
                    if (frog.getShape().getGlobalBounds().intersects(object->getShape().getGlobalBounds())) {
                        // Frog hits a car on the road
                        std::cout << "Frog hit by a car!" << std::endl;
                        resetFrog(); // Reset frog position
                        decrementLives(); // Decrement lives
                        return; // Exit immediately to prevent further collision checks
                    }
                }
            } else if (lane.getType() == LaneType::River) {
                for (const auto& object : lane.getObjects()) {
                    if (frog.getShape().getGlobalBounds().intersects(object->getShape().getGlobalBounds())) {
                        // Frog is on a log or turtle, move with it
                        onFloatingObject = true;
                        frog.move(object->getSpeed(), 0);
                        break;
                    }
                }
                if (!onFloatingObject) {
                    // Frog is in the water without an object, reset position
                    std::cout << "Frog fell into the water!" << std::endl;
                    resetFrog(); // Reset frog position
                    decrementLives(); // Decrement lives
                    return; // Exit immediately to prevent further collision checks
                }
            }
            break; // No need to check further lanes once the correct one is found
        }
    }
}

bool FroggerModel::checkWinCondition() {
    if (occupiedGoals.size() >= 5) {
        hasWon = true;
    }
    return hasWon;
}

bool FroggerModel::getHasWon() const {
    return hasWon;
}
