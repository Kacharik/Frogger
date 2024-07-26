#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"
#include "FroggerView.hpp"
#include "FroggerController.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(1300, 1300), "Frogger Game");
    FroggerModel model(window.getSize());
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
