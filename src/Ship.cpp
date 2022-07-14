#include "Ship.hpp"
#include <iostream>

// yFrac is what fraction of the y-axis the ship should be compared to screen size
Ship::Ship(float yFrac, float thrust, float rs, sf::Vector2u &winSize) : Actor(radius) {
    float ySize = yFrac * winSize.y;
    this->thrust = thrust;
    rotSpeed = rs;
    shape = new sf::CircleShape(ySize, 3);
    shape->setOrigin(ySize, ySize);
    shape->setPosition(winSize.x / 2, winSize.y / 2);
    shape->setFillColor(sf::Color::White);
    shape->setScale(0.7, 1);
}

void Ship::applyInput(float rotSpeed, float dCoef) {
    float rot = rotSpeed * dCoef;

    if (KeyData::getKeyState(Left)) {
        rotate(-rot);
    }
    if (KeyData::getKeyState(Right)) {
        rotate(rot);
    }
    if (KeyData::getKeyState(Up)) {
        float currRot = getRotation(); // degrees from Vector2(1, 0);
        sf::Vector2f acc = VecMath::vecAtDeg(currRot) * thrust * dCoef;
        velocity += acc;
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
    shape->move(velocity);
}