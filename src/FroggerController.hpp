#ifndef FROGGER_CONTROLLER_HPP
#define FROGGER_CONTROLLER_HPP

#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"
#include "FroggerView.hpp"

class FroggerController {
public:
    FroggerController(FroggerModel* model, FroggerView* view, sf::Vector2u windowSize);
    void handleEvent(const sf::Event& event);
    void update();
private:
    FroggerModel* model;
    FroggerView* view;
    sf::Vector2u windowSize; 
    struct GoalBlock {
        int left;
        int width;
    };
    std::vector<GoalBlock> goalBlocks;
    void initializeGoalBlocks();
};

#endif

