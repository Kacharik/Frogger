#ifndef FROGGER_MODEL_HPP
#define FROGGER_MODEL_HPP

#include <vector>
#include "Lane.hpp"
#include "Frog.hpp"

class FroggerModel {
public:
    FroggerModel();
    Frog& getFrog();
    void update();
    const std::vector<Lane>& getLanes() const;

private:
    Frog frog;
    std::vector<Lane> lanes;
    void initializeLanes();
};

#endif
