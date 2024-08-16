#include "FroggerModel.hpp"
#include "Car.hpp"
#include "Turtle.hpp"
#include "Log.hpp"
FroggerModel::FroggerModel(const sf::Vector2u& windowSize)
    : windowSize(windowSize),
      frog((windowSize.x / 2) - 15, windowSize.y - 70 , 40, 40, windowSize.x, windowSize.y),
      lives(3),
      score(0), 
      frogStartingPosition((windowSize.x / 2) - 15, windowSize.y - 70) { // Initialize frog at the center of the bottom row
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
}

sf::Vector2u FroggerModel::getWindowSize() const {
    return windowSize;
}

const std::vector<Lane>& FroggerModel::getLanes() const {
    return lanes;
}

void FroggerModel::initializeLanes() {
    //int laneHeight = getLaneHeight();             THIS GIVES FLOATING POINT EXCEPTION

    // Initialize lanes with different types, lengths, speeds, and directions
    lanes.emplace_back(LaneType::Goal, windowSize.x, 0.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);


    for(int x = 0; x < 1200; x += 550){
        lanes[7].addObject(new Car(x, 7*60, 50, 60, 0.04f));
        lanes[8].addObject(new Car(x+200, 8*60 , 50, 60, 0.04f));
        lanes[9].addObject(new Car(x +400, 9*60 , 50, 60, 0.04f));
        lanes[10].addObject(new Car(x+600 , 10*60 , 50, 60, 0.04f));
        lanes[11].addObject(new Car(x+700 , 11*60 , 50, 60, 0.04f));
    }

    for(int x = 0; x < 1200; x += 550){
        lanes[1].addObject(new Log(x, 1*60 + 5, 110, 60, 0.04f));
        lanes[2].addObject(new Turtle(x + 200, 2*60 + 5, 50, 60, 0.04f));
        lanes[3].addObject(new Log(x + 300, 3*60 + 5, 110, 60, 0.04f));
        lanes[4].addObject(new Log(x + 400, 4*60 + 5, 110, 60, 0.04f));
        lanes[5].addObject(new Turtle(x + 600, 5*60 + 5, 50, 60, 0.04f));
    }
}

void FroggerModel::resetFrog() {
    frog = Frog((windowSize.x / 2) - 25, windowSize.y - 110 , 40, 40, windowSize.x, windowSize.y);
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
    }
}

int FroggerModel::getScore() const {
    return score;
}

void FroggerModel::incrementScore() {
    score++;
}

void FroggerModel::initializeFrogPosition() {
    int windowWidth = 800;
    int windowHeight = 800;
    int totalLanes = lanes.size();

    float cellHeight = static_cast<float>(windowHeight) / totalLanes;
    float frogX = (windowWidth - frog.getWidth()) / 2;
    float frogY = (totalLanes - 1) * cellHeight + (cellHeight - frog.getHeight()) / 2;

frog.setPosition(frogX, frogY);
}

int FroggerModel::getLaneHeight() const {
    return (windowSize.y - 20) / lanes.size();
}

int FroggerModel::getGoalLaneY() const {
    // Assuming the first lane is the goal lane

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