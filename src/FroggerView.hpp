#ifndef FROGGERVIEW_HPP
#define FROGGERVIEW_HPP

#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"

class FroggerView {
public:
    FroggerView(FroggerModel* model);
    void render(sf::RenderWindow& window);

private:
    FroggerModel* model;
};

#endif // FROGGERVIEW_HPP
