#include "Actor.hpp"

#pragma once

class Ship : protected Actor {
    public:
        sf::CircleShape shape;
        Ship();
        void move(float, float);
        void move(sf::Vector2<float>&);
};