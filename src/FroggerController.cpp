#include "FroggerController.hpp"

FroggerController::FroggerController(FroggerModel* model, FroggerView* view, sf::Vector2u windowSize)
    : model(model), view(view) {   
    initializeGoalBlocks();
}

void FroggerController::handleEvent(const sf::Event& event) {
    Frog& frog = model->getFrog();
    int originalX = frog.getCurrentX();
    int originalY = frog.getCurrentY();

    if (event.type == sf::Event::KeyPressed) {
        switch (event.key.code) {
            case sf::Keyboard::W: frog.moveUp(); break;
            case sf::Keyboard::Z: frog.moveUp(); break;
            case sf::Keyboard::S: frog.moveDown(); break;
            case sf::Keyboard::A: frog.moveLeft(); break;
            case sf::Keyboard::Q: frog.moveLeft(); break;
            case sf::Keyboard::D: frog.moveRight(); break;
            default: break;
        }
    }
    if (frog.getCurrentX() != originalX || frog.getCurrentY() != originalY) {
        model->incrementScore();
    }
    
}


void FroggerController::update() {
    model->update();
    
    Frog& frog = model->getFrog();
    int frogX = frog.getCurrentX();
    int frogY = frog.getCurrentY();
    
    int laneHeight = model->getLaneHeight();
    int goalLaneY = model->getGoalLaneY();

    // Check if the frog is on the goal lane
    if (frog.getCurrentY() == goalLaneY + 10) {
        // Determine if the frog is on a goal block
        const auto& occupiedGoals = model->getOccupiedGoals();
        for (const auto& [goalBlockX, goalBlockY] : goalBlocks) {

            if (frogX >= goalBlockX && frogX <= goalBlockX + 50 &&
                frogY >= goalBlockY && frogY <= goalBlockY + laneHeight) {

                // Check if the goal is already occupied
                if (std::find(occupiedGoals.begin(), occupiedGoals.end(), std::make_pair(goalBlockX, goalBlockY)) != occupiedGoals.end()) {
                    // Goal already occupied, handle accordingly
                    return;
                }

                // Occupy the goal and reset frog position
                model->occupyGoal(goalBlockX, goalBlockY);
                frog.setPosition(model->getFrogStartingPosition().x, model->getFrogStartingPosition().y);  // Reset frog to starting position
                return;
            }
        }

        // Occupy the goal and reset frog position
        model->occupyGoal(frog.getCurrentX(), frog.getCurrentY());
        frog.setPosition(model->getFrogStartingPosition().x, model->getFrogStartingPosition().y);  // Reset frog to starting position
    }
}

void FroggerController::initializeGoalBlocks() {
    int laneHeight = model->getLaneHeight();

    goalBlocks = {
        {100, 30},
        {260, 30},
        {410, 30},
        {560, 30},
        {710, 30}
    };
}

