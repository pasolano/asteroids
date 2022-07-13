#include <SFML/System.hpp>
#include "Actor.hpp"
#include "KeyData.hpp"

#pragma once

class Ship : public Actor {
    float thrust;
    float rotSpeed;
    float size;

    public:
        Ship(float, float, float);
        void update(sf::Time&);
        void applyInput(float, float);
};