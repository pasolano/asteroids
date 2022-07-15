#include "Actor.hpp"

// default constructor
// face up
Actor::Actor(float yFrac, sf::Vector2u& winSize) : winSize(winSize) {
    alive = true;
    radius = yFrac * winSize.y;
}

void Actor::accelerate(float x, float y) {
    velocity.x += x;
    velocity.y += y;
}

void Actor::accelerate(sf::Vector2f& acc) {
    accelerate(acc.x, acc.y);
}

sf::Vector2f Actor::getPosition() {
    return shape->getPosition();
}

bool Actor::isVisible() {
    return isAlive();
}

sf::Shape* Actor::getShape() {
    return shape;
}

bool Actor::isAlive() {
    return alive;
}

float Actor::getRadius() {
    return radius;
}

void Actor::rotate(float deg) {
    shape->rotate(deg);
}

float Actor::getRotation() {
    return shape->getRotation();
}

void Actor::setPosition(sf::Vector2f pos) {
    shape->setPosition(pos);
}

Actor::~Actor() {
    delete shape;
}

void Actor::setRotation(float rot) {
    shape->setRotation(rot);
}

sf::Vector2f Actor::getDirection() {
    float rot = shape->getRotation();
    return VecMath::vecAtDeg(rot);
}