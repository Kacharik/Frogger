#include "FroggerModel.hpp"
#include "Car.hpp"
#include "Turtle.hpp"
#include "Log.hpp"
FroggerModel::FroggerModel(const sf::Vector2u& windowSize)
    : windowSize(windowSize),
      frog((windowSize.x / 2) - 25, windowSize.y - 60 , 40, 40, windowSize.x, windowSize.y),
      lives(3),
      score(0), 
      frogStartingPosition((windowSize.x / 2) - 25, windowSize.y - 110) { // Initialize frog at the center of the bottom row
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
    // Add more lanes as needed

    for(int x = 0; x < 1200; x += 400){
        lanes[8].addObject(new Car(x, 8*50, 50, 50, 0.1f));
        lanes[9].addObject(new Car(x+200, 9*50, 50, 50, 0.1f));
        lanes[10].addObject(new Car(x +400, 10*50, 50, 50, 0.1f));
        lanes[11].addObject(new Car(x+600 , 11*50, 50, 50, 0.1f));
        lanes[12].addObject(new Car(x+700 , 12*50, 50, 50, 0.1f));
    }


    for(int x = 0; x < 1200; x += 400){
        lanes[2].addObject(new Log(x, 2*50, 110, 40, 0.1f));
        lanes[3].addObject(new Turtle(x + 200, 3*50, 40, 40, 0.1f));
        lanes[4].addObject(new Log(x + 300, 4*50, 110, 40, 0.1f));
        lanes[5].addObject(new Log(x + 400, 5*50, 110, 40, 0.1f));
        lanes[6].addObject(new Turtle(x + 600, 6*50, 40, 40, 0.1f));
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