#include "Actor.hpp"

// default constructor
// face up
Actor::Actor() {
    direction.y = -1;
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