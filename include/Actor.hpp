#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "VecMath.hpp"

#pragma once

class Actor
{
protected:
    bool alive = true;
    float radius;
    sf::Shape *shape;
    sf::Vector2f velocity;
    sf::Vector2u winSize;

public:
    Actor(float, sf::Vector2u);
    virtual ~Actor();

    sf::Vector2f getDirection() const;
    sf::Vector2f getPosition() const;
    float getRadius() const;
    float getRotation() const;
    sf::Shape *getShape() const;
    bool isAlive() const;
    virtual bool isVisible() const;

    void setPosition(sf::Vector2f pos);
    void setRotation(float rot);
    void setAlive(bool val);

    void accelerate(float, float);
    void accelerate(sf::Vector2f vel);
    void rotate(float);

    bool collidesWith(Actor *actor) const;

    virtual void update(const sf::Time &delta) = 0;
};