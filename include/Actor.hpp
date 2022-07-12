#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#pragma once

class Actor{
    protected:
        sf::Vector2f velocity;
        sf::Vector2f direction;
        sf::Vector2f position;

    public:
        void accelerate(float, float);
        void accelerate(sf::Vector2f&);
        sf::Vector2f& getPosition();
        Actor();
};