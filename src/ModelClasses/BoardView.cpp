#include "BoardView.hpp"

BoardView::BoardView(int width, int height, const char* title)
    : Fl_Window(width, height, title) {}

void BoardView::draw() {
    Fl_Window::draw();

    // Draw the Frogger game board (lanes, obstacles, etc.)
    // Implement drawing logic here based on the game's requirements
}