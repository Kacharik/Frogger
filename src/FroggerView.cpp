#include "FroggerView.hpp"

FroggerView::FroggerView(FroggerModel* model) : model(model), boardCell(sf::Vector2f(50.0f, 50.0f)) {
    std::cout << "View initialized with window size: " << model->getWindowSize().x << "x" << model->getWindowSize().y << std::endl;
    // Load the font
    if (!font.loadFromFile("assets/fonts/DejaVuSans.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }
    // Configure the score text
    scoreText.setFont(font);
    scoreText.setCharacterSize(24); // Font size
    scoreText.setFillColor(sf::Color::White); // Text color
}

void FroggerView::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    const auto& lanes = model->getLanes();
    for (int i = 0; i < 13; ++i) {
        renderLane(window, lanes[i], i);
        renderLaneObjects(window, lanes[i], i);
    }

    renderStatusBar(window);

    // Render the frogs on the occupied goal blocks
    const auto& occupiedGoals = model->getOccupiedGoals();
    for (const auto& goal : occupiedGoals) {
        renderFrog(window, goal.first - 25, goal.second - 25);
    }
    // Render the current frog
    renderFrog(window, model->getFrog());
}

void FroggerView::renderLane(sf::RenderWindow& window, const Lane& lane, int laneIndex) {
    sf::Vector2u windowSize = window.getSize();
    
    int laneHeight = (windowSize.y - 20) / 13;
    
    boardCell.setSize(sf::Vector2f(windowSize.x, laneHeight));
    boardCell.setPosition(0, (laneIndex * laneHeight));

    switch (lane.getType()) {
        case LaneType::Road:
            boardCell.setFillColor(sf::Color(105, 105, 105));
            window.draw(boardCell);
            break;
        case LaneType::River:
            boardCell.setFillColor(sf::Color(100,149,237));
            window.draw(boardCell);
            break;
        case LaneType::Grass:
            boardCell.setFillColor(sf::Color(198, 115, 255));
            window.draw(boardCell);
            break;
        case LaneType::Goal:
            // Draw the green background for the goal lane
            boardCell.setFillColor(sf::Color(4, 99, 7)); // Green
            window.draw(boardCell);

            // Draw 5 yellow blocks within the goal lane
            sf::RectangleShape yellowBlock(sf::Vector2f(50, laneHeight));
            yellowBlock.setFillColor(sf::Color(255, 215, 0));

            for (int i = 0; i < 5; ++i) {
                // Adjust the position to fit the yellow blocks within the lane
                yellowBlock.setPosition(80 + 150 * i, laneIndex * laneHeight );
                window.draw(yellowBlock);
            }
            break;
    }
}

void FroggerView::renderLaneObjects(sf::RenderWindow& window, const Lane& lane, int laneIndex) {
    const auto& objects = lane.getObjects();
    for (const auto& object : objects) {
        // Draw each object using its specific shape
        window.draw(object->getDrawable());
    }
}

void FroggerView::renderStatusBar(sf::RenderWindow& window) {
    // Get window size
    sf::Vector2u windowSize = window.getSize();

    // Positioning of squares (bottom left corner)
    float startX = 10;
    float startY = windowSize.y - 20; // Positioning from the bottom of the window

    // Number of squares to display based on lives
    int numLives = model->getLives();

    // Draw squares
    for (int i = 0; i < numLives; ++i) {
        // Position for each square
        float x = startX + i * (20 + 10); // 50 is the size of the square, 10 is the padding
        float y = startY;

        // Create and position the square
        sf::RectangleShape square(sf::Vector2f(18.0f, 18.0f));
        square.setFillColor(sf::Color::Red);
        square.setPosition(x, y);

        // Draw the square
        window.draw(square);
    }

    // Set the score text
    std::string scoreString = "Score: " + std::to_string(model->getScore());
    scoreText.setString(scoreString);
    scoreText.setCharacterSize(18); 

    // Position the score text in the bottom right corner
    scoreText.setPosition(model->getWindowSize().x - scoreText.getGlobalBounds().width - 20, model->getWindowSize().y - scoreText.getGlobalBounds().height - 10);

    // Draw the score text on the window
    window.draw(scoreText);
}

void FroggerView::renderFrog(sf::RenderWindow& window, const Frog& frog) {
    sf::Vector2u windowSize = window.getSize();
    // Assuming frog size is 50x50
    float frogWidth = (windowSize.x / 20);
    float frogHeight = ((windowSize.y - 20) / 13) - 20;

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

void FroggerView::renderFrog(sf::RenderWindow& window, int x, int y) {
    sf::Vector2u windowSize = window.getSize();
    // Assuming frog size is 50x50
    float frogWidth = (windowSize.x / 20);
    float frogHeight = ((windowSize.y - 20) / 13) - 20;

    sf::RectangleShape frogShape(sf::Vector2f(frogWidth, frogHeight));

    // Position the frog based on its coordinates
    frogShape.setPosition(x, y);
    frogShape.setFillColor(sf::Color::Green);
    window.draw(frogShape);

    // Draw eyes
    sf::CircleShape eye;
    eye.setRadius(5);
    eye.setFillColor(sf::Color::White);

    // Left eye
    eye.setPosition(x + 7, y + 7);
    window.draw(eye);

    // Right eye
    eye.setPosition(x + 27, y + 7);
    window.draw(eye);

    // Draw pupils
    sf::CircleShape pupil;
    pupil.setRadius(2);
    pupil.setFillColor(sf::Color::Black);

    // Left pupil
    pupil.setPosition(x + 10, y + 10);
    window.draw(pupil);

    // Right pupil
    pupil.setPosition(x + 30, y + 10);
    window.draw(pupil);

    // Draw mouth
    sf::RectangleShape mouth(sf::Vector2f(20, 3));
    mouth.setFillColor(sf::Color::Red);
    mouth.setPosition(x + 10, y + 30); // Centered horizontally, near the bottom
    window.draw(mouth);
}
