#include <SFML/System.hpp>
#include "Actor.hpp"
#include "KeyData.hpp"

#pragma once

class Ship : public Actor {
    float thrust = 0.1;

    public:
        sf::CircleShape shape;
        Ship();
        void update(sf::Time&);
};