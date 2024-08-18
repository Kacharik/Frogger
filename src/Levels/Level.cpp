#include "Level.hpp"
#include <iostream>

Level::Level(int number, const sf::Vector2u& windowSize)
    : levelNumber(number), windowSize(windowSize) {
    initializeLanes();
}

void Level::initializeLanes() {
    lanes.clear(); // Clear any existing lanes
    switch (levelNumber) {
        case 1:
            configureLevel1();
            break;
        case 2:
            configureLevel2();
            break;
        case 3:
            configureLevel3();
            break;
        // Add cases for more levels as needed
        default:
            configureLevel1(); // Fallback to level 1
            break;
    }
}

const std::vector<Lane>& Level::getLanes() const {
    return lanes;
}

void Level::configureLevel1() {
    std::cout << "Configuring Level 1" << std::endl;
    lanes.emplace_back(LaneType::Goal, windowSize.x, 0.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);

    for (int x = 0; x < 1200; x += 550) {
        lanes[7].addObject(new Car(x, 7 * 60, 50, 60, 0.04f));
        lanes[8].addObject(new Car(x + 200, 8 * 60, 50, 60, 0.04f));
        lanes[9].addObject(new Car(x + 400, 9 * 60, 50, 60, 0.04f));
        lanes[10].addObject(new Car(x + 600, 10 * 60, 50, 60, 0.04f));
        lanes[11].addObject(new Car(x + 700, 11 * 60, 50, 60, 0.08f));
    }

    for (int x = 0; x < 1200; x += 300) {
        lanes[1].addObject(new Log(x, 1 * 60 + 5, 200, 60, 0.04f));
        lanes[2].addObject(new Turtle(x + 200, 2 * 60 + 5, 110, 60, 0.02f));
        lanes[3].addObject(new Log(x + 300, 3 * 60 + 5, 200, 60, 0.04f));
        lanes[4].addObject(new Log(x + 400, 4 * 60 + 5, 200, 60, 0.03f));
        lanes[5].addObject(new Turtle(x + 600, 5 * 60 + 5, 110, 60, 0.04f));
    }
}

void Level::configureLevel2() {
    std::cout << "Configuring Level 2" << std::endl;
    lanes.emplace_back(LaneType::Goal, windowSize.x, 0.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::River, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);

    for (int x = 0; x < 1200; x += 550) {
        lanes[7].addObject(new Car(x, 7 * 60, 50, 100, 0.04f));
        lanes[8].addObject(new Car(x + 200, 8 * 60, 100, 60, 0.04f));
        lanes[9].addObject(new Car(x + 400, 9 * 60, 100, 60, 0.04f));
        lanes[10].addObject(new Car(x + 600, 10 * 60, 100, 60, 0.04f));
        lanes[11].addObject(new Car(x + 700, 11 * 60, 100, 60, 0.08f));
    }

    for (int x = 0; x < 1200; x += 300) {
        lanes[1].addObject(new Log(x, 1 * 60 + 5, 200, 60, 0.04f));
        lanes[2].addObject(new Turtle(x + 200, 2 * 60 + 5, 110, 60, 0.02f));
        lanes[3].addObject(new Log(x + 300, 3 * 60 + 5, 200, 60, 0.04f));
        lanes[4].addObject(new Log(x + 400, 4 * 60 + 5, 200, 60, 0.03f));
        lanes[5].addObject(new Turtle(x + 600, 5 * 60 + 5, 110, 60, 0.04f));
    }
}

void Level::configureLevel3() {
    std::cout << "Configuring Level 3" << std::endl;
    lanes.emplace_back(LaneType::Goal, windowSize.x, 0.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 3.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 0.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, false);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Road, windowSize.x, 5.0f, true);
    lanes.emplace_back(LaneType::Grass, windowSize.x, 0.0f, true);

    for (int x = 0; x < 1200; x += 550) {
        lanes[7].addObject(new Car(x, 7 * 60, 50, 100, 0.04f));
        lanes[8].addObject(new Car(x + 200, 8 * 60, 100, 60, 0.04f));
        lanes[9].addObject(new Car(x + 400, 9 * 60, 100, 60, 0.04f));
        lanes[10].addObject(new Car(x + 600, 10 * 60, 100, 60, 0.04f));
        lanes[11].addObject(new Car(x + 700, 11 * 60, 100, 60, 0.08f));
    }

    for (int x = 0; x < 1200; x += 300) {
        lanes[1].addObject(new Car(x, 1 * 60 + 5, 200, 60, 0.02f));
        lanes[2].addObject(new Car(x + 200, 2 * 60 + 5, 110, 60, 0.02f));
        lanes[3].addObject(new Car(x + 300, 3 * 60 + 5, 200, 60, 0.04f));
        lanes[4].addObject(new Car(x + 400, 4 * 60 + 5, 200, 60, 0.03f));
        lanes[5].addObject(new Car(x + 600, 5 * 60 + 5, 110, 60, 0.04f));
    }
}
