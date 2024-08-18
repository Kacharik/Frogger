#include "FroggerController.hpp"
//constructor
FroggerController::FroggerController(FroggerModel* model, FroggerView* view, sf::Vector2u windowSize)
    : model(model), view(view) {   
    initializeGoalBlocks();
}
/**********************************HANDLE EVENT**************************************/
void FroggerController::handleEvent(const sf::Event& event) {
    Frog& frog = model->getFrog();// get frog 
    //get current position
    int originalX = frog.getCurrentX();
    int originalY = frog.getCurrentY();
    //call each method to handle diff keys pressed 
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

/**********************************UPDATE**************************************/
void FroggerController::update() {
    model->update();
    Frog& frog = model->getFrog();
    int frogX = frog.getCurrentX();
    int frogY = frog.getCurrentY();
    
    int laneHeight = model->getLaneHeight();
    int goalLaneY = model->getGoalLaneY();

    //check if the frog is on the goal lane
    if (frogY == goalLaneY + 10) {
        bool onGoalBlock = false;
        //determine if the frog is on a goal block
        const auto& occupiedGoals = model->getOccupiedGoals();
        for (const auto& [goalBlockX, goalBlockY] : goalBlocks) {
            if (frogX >= goalBlockX - 50 && frogX <= goalBlockX) {
                onGoalBlock = true;
                if (std::find(occupiedGoals.begin(), occupiedGoals.end(), std::make_pair(goalBlockX, goalBlockY)) != occupiedGoals.end()) {
                    //goal already occupied
                    return;
                }

                //occupy the goal and reset frog position
                model->occupyGoal(goalBlockX, goalBlockY);
                frog.setPosition(model->getFrogStartingPosition().x, model->getFrogStartingPosition().y);  // Reset frog to starting position
                
                // Check win condition
                if (model->checkWinCondition()) {
                    model->updateBestScore(); 
                    std::cout << "You win!" << std::endl;
                }
                return;
            }
        }
        if (!onGoalBlock) {
            std::cout << "Frog missed the goal block! Decrementing lives." << std::endl;
            model->decrementLives(); //decrement lives when the frog is not on a goal block
            frog.setPosition(model->getFrogStartingPosition().x, model->getFrogStartingPosition().y);
        }
    }
}
/**********************************GOAL BLOCKS**************************************/
void FroggerController::initializeGoalBlocks() {
    int laneHeight = model->getLaneHeight();

    goalBlocks = {
        {110, 30},
        {260, 30},
        {410, 30},
        {560, 30},
        {710, 30}
    };
}

