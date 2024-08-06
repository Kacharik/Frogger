#include "FroggerController.hpp"

FroggerController::FroggerController(FroggerModel* model, FroggerView* view)
    : model(model), view(view) {}

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
}

