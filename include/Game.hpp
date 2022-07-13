#include "PlayerView.hpp"
#include "Ship.hpp"
#include <vector>

#pragma once

class Game {
    bool ongoing;
    PlayerView* view;

    std::vector<Actor*> actors;

    Ship* ship;
    sf::Clock* dClock;

    public:
        void update();
        void setOngoing(bool);
        bool isOngoing();
        Game();
};