#include "FroggerModel.hpp"

FroggerModel::FroggerModel() : frog(0, 0) { // Initialize frog at position (0, 0)
    // Additional initialization if necessary
}

Frog& FroggerModel::getFrog() {
    return frog;
}

void FroggerModel::update() {
    // Update game logic
}
