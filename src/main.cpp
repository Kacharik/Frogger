#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"
#include "FroggerView.hpp"
#include "FroggerController.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1450, 950), "Frogger Game");

    // Confirm the window size
    sf::Vector2u windowSize = window.getSize();
    std::cout << "Initial window size: " << windowSize.x << "x" << windowSize.y << std::endl;

    // Ensure the window size is properly passed to the model
    FroggerModel model(windowSize);
    FroggerView view(&model);
    FroggerController controller(&model, &view);

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
