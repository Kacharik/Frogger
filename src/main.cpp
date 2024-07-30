#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"
#include "FroggerView.hpp"
#include "FroggerController.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1450, 950), "Frogger Game");
    window.setSize(sf::Vector2u(1450, 950));
    FroggerModel model(window.getSize());
    FroggerView view(&model);
    FroggerController controller(&model, &view);
    std::cout << "Initial window size: " << window.getSize().x << "x" << window.getSize().y << std::endl;

    

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
