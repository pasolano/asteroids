#include "Ship.hpp"
#include "VecMath.hpp"
#include <iostream>

Ship::Ship(float radius, float thrust, float rs) {
    this->thrust = thrust;
    rotSpeed = rs;
    position = sf::Vector2f(50, 50); // TODO: center of screen based on dims
    shape = new sf::CircleShape(radius, 3);
    shape->setOrigin(radius, radius);
    shape->setPosition(position);
    shape->setFillColor(sf::Color::White);
    shape->setScale(0.7, 1);
}

// TODO: apply delta
void Ship::applyInput(float rotSpeed, float dCoef) {
    if (KeyData::getKeyState(Left)) {
        rotateVector(direction, -rotSpeed, dCoef);
    }
    if (KeyData::getKeyState(Right)) {
        rotateVector(direction, rotSpeed, dCoef);
    }
    if (KeyData::getKeyState(Up)) {
        velocity += direction * thrust * dCoef;
    }
    if (KeyData::getKeyState(Down)) {
        ;
    }
}

// Update ship every frame
void Ship::update(sf::Time& delta) {
    // calculate acceleration
    sf::Int64 ms = delta.asMicroseconds();
    float dCoef = ms / 1000000.f;
    applyInput(rotSpeed, dCoef);

    // update position
    position += velocity;

    // update shape position
    shape->setPosition(getPosition());
    sf::Vector2f unit = sf::Vector2f(0,-1); // TODO move so not remade every frame

    shape->setRotation(degBetVec(unit, direction));
}