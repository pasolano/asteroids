#include "Actor.hpp"

// default constructor
// face up
Actor::Actor() {
    direction.y = -1;
}

void Actor::accelerate(float x, float y) {
    auto acc = sf::Vector2<float>(x, y);
    velocity += acc;
}

void Actor::accelerate(sf::Vector2<float> acc) {
    velocity += acc;
}