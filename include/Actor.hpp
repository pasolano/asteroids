#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#pragma once

class Actor{
    protected:
        bool alive;
        sf::Shape* shape;
        sf::Vector2f velocity;
        sf::Vector2f direction;
        sf::Vector2f position;
        float radius;

    public:
        void accelerate(float, float);
        void accelerate(sf::Vector2f&);
        sf::Vector2f& getPosition();
        virtual bool isVisible();
        bool isAlive();
        sf::Shape* getShape();
        Actor(float);
        virtual void update(sf::Time&) = 0;
        float getRadius();
};