#include "Actor.hpp"

// default constructor
// face up
Actor::Actor(float r) {
    direction.y = -1;
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

sf::Vector2f& Actor::getPosition() {
    return position;
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