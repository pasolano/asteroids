#include "Ship.hpp"
#include <iostream>

Ship::Ship(float radius, float thrust) {
    this->thrust = thrust;
    position = sf::Vector2f(50, 50); // TODO: center of screen based on dims
    shape = new sf::CircleShape(radius, 3);
    shape->setOrigin(radius, radius);
    shape->setPosition(position);
    shape->setFillColor(sf::Color::White);
}

static sf::Vector2f getAcc(float mov) {
    sf::Vector2f acc;

    if (KeyData::getKeyState(Left)) {
        acc.x = -mov;
    }
    if (KeyData::getKeyState(Right)) {
        acc.x = mov;
    }
    if (KeyData::getKeyState(Up)) {
        acc.y = -mov;
    }
    if (KeyData::getKeyState(Down)) {
        acc.y = mov;
    }

    return acc;
}

// Update ship every frame
void Ship::update(sf::Time& delta) {
    // calculate acceleration
    sf::Int64 ms = delta.asMicroseconds();
    float mov = (ms * thrust) / 1000000.f;
    auto acc = getAcc(mov);

    // modify velocity
    accelerate(acc);

    // update position
    position += velocity;

    // update shape position
    shape->setPosition(getPosition());
}