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
    std::unordered_map<int, Actor*> ships;
    std::unordered_map<int, Actor*> asteroids;
    sf::Clock *dClock = new sf::Clock();

public:
    void update();
    void setOngoing(bool);
    bool isOngoing() const;
    Game();
    void update_m(std::unordered_map<int, Actor*>& m, sf::Time delta);
};