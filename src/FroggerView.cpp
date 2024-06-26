#include "FroggerView.hpp"

FroggerView::FroggerView(FroggerModel* model) : model(model) {
    boardCell.setSize(sf::Vector2f(50.0f, 50.0f)); 
}

void FroggerView::render(sf::RenderWindow& window) {

    const auto& lanes = model->getLanes();
    for (int i = 0; i < lanes.size(); ++i) {
        renderLane(window, lanes[i], i);
    }

    // Example of drawing the frog
    Frog& frog = model->getFrog();
    
    // Assuming frog size is 50x50
    float frogWidth = 40;
    float frogHeight =40;
    
    sf::RectangleShape frogShape(sf::Vector2f(frogWidth, frogHeight));
    
    // Position the frog at the bottom center of the screen
    float frogX = frog.getX();
    float frogY = frog.getY();
    frogShape.setPosition(frogX, frogY);
    frogShape.setFillColor(sf::Color::Green);
    window.draw(frogShape);

        // Draw eyes
    sf::CircleShape eye;
    eye.setRadius(5);
    eye.setFillColor(sf::Color::White);

    // Left eye
    eye.setPosition(frogX + 7, frogY + 7);
    window.draw(eye);

    // Right eye
    eye.setPosition(frogX + 27, frogY + 7);
    window.draw(eye);

    // Draw pupils
    sf::CircleShape pupil;
    pupil.setRadius(2);
    pupil.setFillColor(sf::Color::Black);

    // Left pupil
    pupil.setPosition(frogX + 10, frogY + 10);
    window.draw(pupil);

    // Right pupil
    pupil.setPosition(frogX + 30, frogY + 10);
    window.draw(pupil);

    // Draw mouth
    sf::RectangleShape mouth(sf::Vector2f(20, 3));
    mouth.setFillColor(sf::Color::Red);
    mouth.setPosition(frogX + 10, frogY + 30); // Centered horizontally, near the bottom
    window.draw(mouth);


}

void FroggerView::renderLane(sf::RenderWindow& window, const Lane& lane, int laneIndex) {
    sf::Vector2u windowSize = window.getSize();
    boardCell.setSize(sf::Vector2f(windowSize.x, windowSize.y / 13));
    
    boardCell.setPosition(0, laneIndex * 45); // Example position

        switch (lane.getType()) {
            case LaneType::Road:
                boardCell.setFillColor(sf::Color(105, 105, 105));
                break;
            case LaneType::River:
                boardCell.setFillColor(sf::Color::Blue);
                break;
            case LaneType::Grass:
                boardCell.setFillColor(sf::Color(41, 163, 0));
                break;
            case LaneType::Goal:
                boardCell.setFillColor(sf::Color::Yellow);
                break;
        }
        window.draw(boardCell);
}


void FroggerView::renderLaneObjects(sf::RenderWindow& window, const Lane& lane, int laneIndex) {
    const auto& objects = lane.getObjects();
    for (const auto& object : objects) {
        // Example logic to render objects within the lane
        sf::RectangleShape objectShape(sf::Vector2f(object.getWidth(), object.getHeight())); // Use object dimensions
        objectShape.setPosition(object.getX(), laneIndex * 50); // Use object position

        // Set color or other properties based on object type or lane properties
        switch (lane.getType()) {
            case LaneType::Road:
                objectShape.setFillColor(sf::Color::White);
                break;
            case LaneType::River:
                objectShape.setFillColor(sf::Color::Cyan);
                break;
            case LaneType::Grass:
                objectShape.setFillColor(sf::Color::Green);
                break;
            case LaneType::Goal:
                objectShape.setFillColor(sf::Color::Yellow);
                break;
        }

        window.draw(objectShape);
    }
}