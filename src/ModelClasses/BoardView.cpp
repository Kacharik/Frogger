#ifndef BOARDVIEW_HPP
#define BOARDVIEW_HPP

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include "Frog.hpp"

class BoardView : public Fl_Window {
public:
    BoardView(int width, int height, const char* title);

    void draw() override;

    // Optional: Add methods to handle drawing other game elements
};


#endif
