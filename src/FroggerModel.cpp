#include "FroggerModel.hpp"

FroggerModel::FroggerModel(const sf::Vector2u& windowSize) 
    : windowSize(windowSize),
      frog((windowSize.x / 2) - 25, windowSize.y - 50 , 10, 10) { // Initialize frog at the center of the bottom row
    initializeLanes();
    // Additional initialization if necessary
}

Frog& FroggerModel::getFrog() {
    return frog;
}

void FroggerModel::update() {
    // Update game logic
}

//#################### LANES ##################
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
    //lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);
    // Add more lanes as needed
}
