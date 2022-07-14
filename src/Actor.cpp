#include "Actor.hpp"

// default constructor
// face up
Actor::Actor(float r) {
    alive = true;
    radius = r;
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

// return degrees from Vector2(1, 0);
float Actor::getRotation() {
    // shape function returns degrees from Vector2(0, -1);
    return shape->getRotation() - 90;
}

void Actor::setPosition(sf::Vector2f pos) {
    shape->setPosition(pos);
}