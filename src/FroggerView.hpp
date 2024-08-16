#ifndef FROGGERVIEW_HPP
#define FROGGERVIEW_HPP

#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"
#include <iostream>
#include <vector>

class FroggerView {
public:
    FroggerView(FroggerModel* model);
    void render(sf::RenderWindow& window);

private:
    FroggerModel* model;
    sf::RectangleShape boardCell; // Example for drawing cells
    sf::Font font;
    sf::Text scoreText;

    void renderLane(sf::RenderWindow& window, const Lane& lane, int laneIndex);
    void renderLaneObjects(sf::RenderWindow& window, const Lane& lane, int laneIndex);
    void renderStatusBar(sf::RenderWindow& window);
    void renderFrog(sf::RenderWindow& window, const Frog& frog);
    void renderFrog(sf::RenderWindow& window, int x, int y);

    int heartSize = 30; // Size of each heart
    int heartPadding = 10; // Padding between hearts
};

#endif // FROGGERVIEW_HPP
