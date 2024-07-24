#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"
#include "FroggerView.hpp"
#include "FroggerController.hpp"

int main() {
    FroggerModel model;
    FroggerView view(&model);
    FroggerController controller(&model, &view);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Frogger Game");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            controller.handleEvent(event);
        }

        controller.update();

        window.clear();
        view.render(window);
        window.display();
    }

    return 0;
}
