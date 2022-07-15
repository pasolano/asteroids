#include <SFML/System.hpp>
#include "Actor.hpp"
#include "KeyData.hpp"
#include "Projectile.hpp"
#include <unordered_map>

#pragma once

class Ship : public Actor {
    float thrust;
    float rotSpeed;
    std::unordered_map<int, Actor*>& actors;
    sf::Clock bullet_timer;
    sf::Int64 micro_since_shot;
    int& last_id;

    public:
        Ship(float, sf::Vector2u&, float, float, std::unordered_map<int, Actor*>&, int&);
        void update(sf::Time&);
        void applyInput(float, float);
        void shoot();
};