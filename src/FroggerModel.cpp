#include "FroggerModel.hpp"
#include "Car.hpp"
#include "Turtle.hpp"
#include "Log.hpp"
FroggerModel::FroggerModel(const sf::Vector2u& windowSize)
    : windowSize(windowSize),
      frog((windowSize.x / 2) - 25, windowSize.y - 110 , 40, 40, windowSize.x, windowSize.y),
      lives(3),
      score(0) { // Initialize frog at the center of the bottom row
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
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, false);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, false);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, false);
    lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);
    // Add more lanes as needed

    for(int x = 0; x < 1200; x += 400){
        lanes[7].addObject(new Car(x, 7*50, 50, 50, 0.1f));
        lanes[8].addObject(new Car(x+200, 8*50, 50, 50, 0.1f));
        lanes[9].addObject(new Car(x +400, 9*50, 50, 50, 0.1f));
        lanes[10].addObject(new Car(x+600 , 10*50, 50, 50, 0.1f));
    }


    for(int x = 0; x < 1200; x += 400){
        lanes[2].addObject(new Log(x, 2*50, 50, 50, 0.1f));
        lanes[3].addObject(new Log(x + 200, 3*50, 50, 50, 0.1f));
        lanes[4].addObject(new Log(x + 300, 4*50, 50, 50, 0.1f));
        lanes[5].addObject(new Log(x + 400, 5*50, 50, 50, 0.1f));
    }
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
    int windowWidth = 1300;
    int windowHeight = 1300;
    int totalLanes = lanes.size();

    float cellHeight = static_cast<float>(windowHeight) / totalLanes;
    float frogX = (windowWidth - frog.getWidth()) / 2;
    float frogY = (totalLanes - 1) * cellHeight + (cellHeight - frog.getHeight()) / 2;

frog.setPosition(frogX, frogY);
}
