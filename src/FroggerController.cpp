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
    int frogX = frog.getCurrentX() ;
    int frogY = frog.getCurrentY();
    
    int laneHeight = model->getLaneHeight();
    int goalLaneY = model->getGoalLaneY();

    // Check if the frog is on the goal lane
    if (frogY == goalLaneY + 10) {
        // Determine if the frog is on a goal block
        const auto& occupiedGoals = model->getOccupiedGoals();
        for (const auto& [goalBlockX, goalBlockY] : goalBlocks) {

            if (frogX >= goalBlockX - 50 && frogX <= goalBlockX ) {
                    std::cout<<"yoyo2"<< std::endl;
                    std::cout<<goalBlockX;
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
        
        // If the frog is on the goal lane but not within any goal block, handle accordingly
        // Here, you could leave the frog in its position or handle it as a failed attempt
        // For example, you could set a flag, play a sound, or reduce lives.
        
        // Do not respawn the frog unless it was on a goal block
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

