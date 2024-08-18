#ifndef MENUSCREEN_HPP
#define MENUSCREEN_HPP

#include <SFML/Graphics.hpp>

class MenuScreen {
public:
    // Constructor
    MenuScreen();

    // Function to display the menu screen and get the selected level
    void display(sf::RenderWindow& window, int& selectedLevel);

private:
    // Private members such as fonts, textures, buttons
};

#endif // MENUSCREEN_HPP
