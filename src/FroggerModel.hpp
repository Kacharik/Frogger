#ifndef FROGGER_MODEL_HPP
#define FROGGER_MODEL_HPP

#include "Frog.hpp"

class FroggerModel {
public:
    FroggerModel();
    Frog& getFrog();
    void update();
private:
    Frog frog;
};

#endif
