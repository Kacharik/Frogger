#ifndef FROGGERVIEW_HPP
#define FROGGERVIEW_HPP

#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"
#include <iostream>

class FroggerView {
public:
    FroggerView(FroggerModel* model);
    void render(sf::RenderWindow& window);

private:
    FroggerModel* model;
    sf::RectangleShape boardCell; // Example for drawing cells
    void renderLane(sf::RenderWindow& window, const Lane& lane, int laneIndex);
    void renderLaneObjects(sf::RenderWindow& window, const Lane& lane, int laneIndex);
    void renderStatusBar(sf::RenderWindow& window);
};

#endif // FROGGERVIEW_HPP
 