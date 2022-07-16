#include "Actor.hpp"

// default constructor
// face up
Actor::Actor(float yFrac, sf::Vector2u winSize) : winSize(winSize)
{
    radius = yFrac * winSize.y;
}

void Actor::accelerate(float x, float y)
{
    velocity.x += x;
    velocity.y += y;
}

void Actor::accelerate(sf::Vector2f acc)
{
    accelerate(acc.x, acc.y);
}

sf::Vector2f Actor::getPosition() const
{
    return shape->getPosition();
}

bool Actor::isVisible() const
{
    return isAlive();
}

sf::Shape *Actor::getShape() const
{
    return shape;
}

bool Actor::isAlive() const
{
    return alive;
}

float Actor::getRadius() const
{
    return radius;
}

void Actor::rotate(float deg)
{
    shape->rotate(deg);
}

float Actor::getRotation() const
{
    return shape->getRotation();
}

void Actor::setPosition(sf::Vector2f pos)
{
    shape->setPosition(pos);
}

Actor::~Actor()
{
    delete shape;
}

void Actor::setRotation(float rot)
{
    shape->setRotation(rot);
}

sf::Vector2f Actor::getDirection() const
{
    float rot = shape->getRotation();
    return VecMath::vecAtDeg(rot);
}