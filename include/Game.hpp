#include "PlayerView.hpp"
#include "Ship.hpp"
#include <unordered_map>
#include <cassert>
#include <iostream>

#pragma once

class Game {
    bool ongoing;
    PlayerView* view;
    int last_id;
    std::unordered_map<int, Actor*> actors;

    Ship* ship;
    sf::Clock* dClock;

    public:
        void update();
        void setOngoing(bool);
        bool isOngoing();
        Game();
};