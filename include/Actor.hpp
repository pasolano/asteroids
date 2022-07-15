#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "VecMath.hpp"

#pragma once

class Actor {
    protected:
        bool alive;
        sf::Shape* shape;
        sf::Vector2f velocity;
        float radius;
        sf::Vector2u& winSize;

    public:
        void accelerate(float, float);
        void accelerate(sf::Vector2f&);
        sf::Vector2f getPosition();
        virtual bool isVisible();
        bool isAlive();
        sf::Shape* getShape();
        Actor(float, sf::Vector2u&);
        virtual ~Actor();
        virtual void update(sf::Time&) = 0;
        void rotate(float);
        float getRadius();
        float getRotation();
        void setPosition(sf::Vector2f);
        void setRotation(float);
        sf::Vector2f getDirection();
};