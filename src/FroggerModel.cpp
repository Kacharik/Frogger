#include "FroggerModel.hpp"

FroggerModel::FroggerModel() : frog(480, 600 - 50 - 40, 10, 10) { // Initialize frog at position (0, 0)
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
    lanes.emplace_back(LaneType::Goal, 1000, 3.0f, true);
    lanes.emplace_back(LaneType::River, 1000, 3.0f, false);
    lanes.emplace_back(LaneType::River, 1000, 3.0f, true);
    lanes.emplace_back(LaneType::Grass, 1000, 3.0f, false);
    lanes.emplace_back(LaneType::River, 1000, 3.0f, true);
    lanes.emplace_back(LaneType::River, 1000, 3.0f, false);
    lanes.emplace_back(LaneType::Grass, 1000, 0.0f, true);
    lanes.emplace_back(LaneType::Road, 1000, 5.0f, false);
    lanes.emplace_back(LaneType::Road, 1000, 5.0f, false);
    lanes.emplace_back(LaneType::Grass, 1000, 0.0f, true);
    lanes.emplace_back(LaneType::Road, 1000, 5.0f, true);
    lanes.emplace_back(LaneType::Road, 1000, 5.0f, true);
    lanes.emplace_back(LaneType::Grass, 1000, 0.0f, true);
    lanes.emplace_back(LaneType::Grass, 1000, 0.0f, true);
    // Add more lanes as needed
}