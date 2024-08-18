#include "FroggerModel.hpp"
#include <iostream>
/***********************************CONSTRUCTOR**************************************/
FroggerModel::FroggerModel(const sf::Vector2u& windowSize, int levelNumber)
    : windowSize(windowSize),
      frog((windowSize.x / 2) - 15, windowSize.y - 70, 40, 40, windowSize.x, windowSize.y),
      lives(3),
      score(0),
      hasWon(false),
      frogStartingPosition((windowSize.x / 2) - 15, windowSize.y - 70),
      currentLevel(levelNumber, windowSize) { //initialize current level
    std::cout << "Model initialized with window size: " << windowSize.x << "x" << windowSize.y << std::endl;
    initializeLanes();
}
/***********************************GETTERS AND SETTERS***************************************/
//frog
Frog& FroggerModel::getFrog() {
    return frog;
}
const sf::Vector2f& FroggerModel::getFrogStartingPosition() const {
    return frogStartingPosition;
}

//window
sf::Vector2u FroggerModel::getWindowSize() const {
    return windowSize;
}
//lanes
const std::vector<Lane>& FroggerModel::getLanes() const {
    return lanes;
}
int FroggerModel::getLaneHeight() const {
    return (windowSize.y - 20) / lanes.size();
}

int FroggerModel::getGoalLaneY() const {
    // The first lane is the goal lane
    return 0;
}
//lives
int FroggerModel::getLives() const {
    return lives;
}

void FroggerModel::setLives(int newLives) {
    lives = newLives;
}
//score
int FroggerModel::getScore() const {
    return score;
}
/***********************************UPDATE***************************************/
void FroggerModel::update() {
    for (auto& lane : lanes) {
        for (auto object : lane.getObjects()) {
            object->update();
        }
    }
    checkCollisions();//call to check each time if there is a collision 
}

//initialise lanes
void FroggerModel::initializeLanes() {
    lanes.clear();
    currentLevel.initializeLanes(); // Initialize lanes from Level class
    lanes = currentLevel.getLanes(); // Set lanes in FroggerModel
}
//reset the frog position if it dies ...
void FroggerModel::resetFrog() {
    initializeFrogPosition();
}


//lives
void FroggerModel::decrementLives() {
    if (lives > 0) {
        --lives;
        if (lives <= 0) {
            std::cout << "Game Over!" << std::endl;
        }
    }
}

void FroggerModel::incrementScore() {
    score++;
}

//frog
void FroggerModel::initializeFrogPosition() {
    frog.setPosition(frogStartingPosition.x, frogStartingPosition.y);
}

//goal
const std::vector<std::pair<int, int>>& FroggerModel::getOccupiedGoals() const {
    return occupiedGoals;
}

void FroggerModel::occupyGoal(int x, int y) {
    occupiedGoals.emplace_back(x, y);
}


/***********************************COLLISION***************************************/
void FroggerModel::checkCollisions() {
    bool onFloatingObject = false; //check if frog is on a log or turtle
    int laneHeight = windowSize.y / lanes.size(); 

    for (int i = 0; i < lanes.size(); ++i) {
        const Lane& lane = lanes[i];
        float laneY = i * laneHeight; //we calculate the Y position of the lane
        //check if the frog is within the current lane's vertical boundaries
        if (frog.getY() >= laneY && frog.getY() < laneY + laneHeight) {
            if (lane.getType() == LaneType::Road) {
                for (const auto& object : lane.getObjects()) {
                    if (frog.getShape().getGlobalBounds().intersects(object->getShape().getGlobalBounds())) {
                        //frog hits a car on the road
                        std::cout << "Frog hit by a car!" << std::endl;
                        resetFrog(); //reset frog position
                        decrementLives(); // Decrement lives
                        return; //exit immediately to prevent further collision checks
                    }
                }
            } else if (lane.getType() == LaneType::River) {
                for (const auto& object : lane.getObjects()) {
                    if (frog.getShape().getGlobalBounds().intersects(object->getShape().getGlobalBounds())) {
                        //frog is on a log or turtle, move with it
                        onFloatingObject = true;
                        frog.move(object->getSpeed(), 0);
                        break;
                    }
                }
                if (!onFloatingObject) {
                    //frog is in the water without an object, reset position
                    std::cout << "Frog fell into the water!" << std::endl;
                    resetFrog(); //reset frog position
                    decrementLives(); //decrement lives
                    return; //exit immediately to prevent further collision checks
                }
            }
            break; //no need to check further lanes once the correct one is found
        }
    }
}
//winning
bool FroggerModel::checkWinCondition() {
    if (occupiedGoals.size() >= 5) {
        hasWon = true;
    }
    return hasWon;
}

bool FroggerModel::getHasWon() const {
    return hasWon;
}
