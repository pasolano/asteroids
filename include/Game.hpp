#include "PlayerView.hpp"
#include "Ship.hpp"
#include <unordered_map>
#include <cassert>
#include <iostream>

#pragma once

class Game
{
    bool ongoing = true;
    PlayerView *view = new PlayerView();
    std::list<Actor *> ships;
    std::list<Actor *> asteroids;
    sf::Clock *dClock = new sf::Clock();

public:
    void update();
    void setOngoing(bool);
    bool isOngoing() const;
    Game();
    void update_l(std::list<Actor *> &m, sf::Time delta);
};