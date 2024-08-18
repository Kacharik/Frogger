#include <SFML/Graphics.hpp>
#include "FroggerModel.hpp"
#include "FroggerView.hpp"
#include "FroggerController.hpp"
#include "Screens/IntroScreen.hpp"
#include "Screens/VictoryScreen.hpp"
#include "Screens/DefeatScreen.hpp"
#include "Screens/MenuScreen.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Frogger Game", sf::Style::Titlebar | sf::Style::Close);
    window.setSize(sf::Vector2u(800, 800));

    /**********************************INTRO SCREEN************************************************/
    IntroScreen intro;
    intro.display(window);

    /**********************************MENU SCREEN************************************************/
    //to select leveles
    int selectedLevel = 0; //default level
    MenuScreen menu;
    menu.display(window, selectedLevel);

    // Initialize the game model with the selected level
    FroggerModel model(window.getSize(), selectedLevel);
    FroggerView view(&model);
    FroggerController controller(&model, &view, window.getSize());

    std::cout << "Initial window size: " << window.getSize().x << "x" << window.getSize().y << std::endl;
   /**********************************GAME STARTED************************************************/
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

        if (model.getHasWon()) {//if won
            VictoryScreen victory;
            victory.display(window);//display the victory screen 
            window.close();
        } else if (model.getLives() <= 0) {//if lost (no lives left)
            DefeatScreen defeat;
            defeat.display(window);//display defeat screen 
            window.close();
        } else {
            window.clear();
            view.render(window);
            window.display();
        }
    }

    return 0;
}
