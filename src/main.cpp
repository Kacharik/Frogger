#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"
#include "FroggerView.hpp"
#include "FroggerController.hpp"
#include "IntroScreen.hpp"
#include "VictoryScreen.hpp"
#include "DefeatScreen.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Frogger Game", sf::Style::Titlebar | sf::Style::Close);
    window.setSize(sf::Vector2u(800, 800));
    FroggerModel model(window.getSize());
    FroggerView view(&model);
    FroggerController controller(&model, &view, window.getSize());
    std::cout << "Initial window size: " << window.getSize().x << "x" << window.getSize().y << std::endl;

    IntroScreen intro;
    intro.display(window);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::Resized) {
                std::cout << "Window resized to: " << event.size.width << "x" << event.size.height << std::endl;
            } else if (event.type == sf::Event::GainedFocus) {
                std::cout << "Window gained focus" << std::endl;
            } else if (event.type == sf::Event::LostFocus) {
                std::cout << "Window lost focus" << std::endl;
            }
            controller.handleEvent(event);
        }

        controller.update();

        if (model.getHasWon()) {
            // Display win message and close the window after the victory screen
            VictoryScreen victory;
            victory.display(window);
            window.close();  // Close the window after displaying the win message
        } else if (model.getLives() <= 0) {
            // Display defeat message and close the window after the defeat screen
            DefeatScreen defeat;
            defeat.display(window);
            window.close();  // Close the window after displaying the defeat message
        } else {
            window.clear();
            view.render(window);
            window.display();
        }
    }

    return 0;
}
