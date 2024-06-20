#include "FroggerView.hpp"

FroggerView::FroggerView(FroggerModel* model) : model(model) {}

void FroggerView::render(sf::RenderWindow& window) {
    // Example of drawing the frog
    Frog& frog = model->getFrog();
    
    // Assuming frog size is 50x50
    float frogWidth = 40;
    float frogHeight =40;
    
    sf::RectangleShape frogShape(sf::Vector2f(frogWidth, frogHeight));
    
    // Position the frog at the bottom center of the screen
    float windowWidth = window.getSize().x;
    float windowHeight = window.getSize().y;
    float frogX = (windowWidth / 2) - (frogWidth / 2);
    float frogY = windowHeight - frogHeight;

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
