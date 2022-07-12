#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#pragma once

class Actor{
    protected:
        sf::Vector2<float> velocity;
        sf::Vector2<float> direction;
        sf::Vector2<float> position;

    public:
        void accelerate(float, float);
        void accelerate(sf::Vector2<float>);
        Actor();
};