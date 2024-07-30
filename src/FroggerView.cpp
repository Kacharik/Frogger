#include "FroggerView.hpp"

FroggerView::FroggerView(FroggerModel* model) : model(model) {
    std::cout << "View initialized with window size: " << model->getWindowSize().x << "x" << model->getWindowSize().y << std::endl;
    boardCell.setSize(sf::Vector2f(50.0f, 50.0f));
}

void FroggerView::render(sf::RenderWindow& window) {
    const auto& lanes = model->getLanes();
    for (int i = 0; i < 13; ++i) {
        renderLane(window, lanes[i], i);
        renderLaneObjects(window, lanes[i], i);
    }

    // Example of drawing the frog
    Frog& frog = model->getFrog();

    sf::Vector2u windowSize = window.getSize();
    // Assuming frog size is 50x50
    float frogWidth = (windowSize.x / 28) - 10 ;//40;
    float frogHeight = ((windowSize.y - 40) / 14) - 20;//40;
    
    sf::RectangleShape frogShape(sf::Vector2f(frogWidth, frogHeight));
    
    // Position the frog based on its model coordinates
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
    // std::cout << "Window height: " << windowSize.y << std::endl;
    
    int laneHeight = (windowSize.y - 40) / 13;
    // std::cout << "Calculated lane height: " << laneHeight << std::endl;
    
    boardCell.setSize(sf::Vector2f(windowSize.x, laneHeight));
    
    boardCell.setPosition(0, (laneIndex * laneHeight));
    // std::cout << "Lane " << laneIndex << " position: " << (laneIndex * laneHeight) << std::endl;

    switch (lane.getType()) {
        case LaneType::Road:
            boardCell.setFillColor(sf::Color(105, 105, 105));
            window.draw(boardCell);
            break;
        case LaneType::River:
            boardCell.setFillColor(sf::Color::Blue);
            window.draw(boardCell);
            break;
        case LaneType::Grass:
            boardCell.setFillColor(sf::Color(41, 163, 0));
            window.draw(boardCell);
            break;
        case LaneType::Goal:
            // Draw the green background for the goal lane
            boardCell.setFillColor(sf::Color(41, 163, 0)); // Green
            window.draw(boardCell);

            // Draw 5 yellow blocks within the goal lane
            sf::RectangleShape yellowBlock(sf::Vector2f(50.0f, 50.0f));
            yellowBlock.setFillColor(sf::Color::Yellow);

            for (int i = 0; i < 5; ++i) {
                // Adjust the position to fit the yellow blocks within the lane
                yellowBlock.setPosition(200 + 250*i, laneIndex * laneHeight + 20);
                window.draw(yellowBlock);
            }
            break;
    }
}

void FroggerView::renderLaneObjects(sf::RenderWindow& window, const Lane& lane, int laneIndex) {
    // const auto& objects = lane.getObjects();
    // for (const auto& object : objects) {
    //     // Example logic to render objects within the lane
    //     sf::RectangleShape objectShape(sf::Vector2f(object.getWidth(), object.getHeight())); // Use object dimensions
    //     objectShape.setPosition(object.getX(), laneIndex * 50); // Use object position

    //     // Set color or other properties based on object type or lane properties
    //     switch (lane.getType()) {
    //         case LaneType::Road:
    //             objectShape.setFillColor(sf::Color(105, 105, 105));
    //             break;
    //         case LaneType::River:
    //             objectShape.setFillColor(sf::Color::Blue);
    //             break;
    //         case LaneType::Grass:
    //             objectShape.setFillColor(sf::Color(41, 163, 0));
    //             break;
    //         case LaneType::Goal:
    //             objectShape.setFillColor(sf::Color::Yellow);
    //             break;
    //     }
    //     window.draw(objectShape);
    // }
}
