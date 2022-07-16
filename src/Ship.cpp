#include "Ship.hpp"
#include <iostream>

// yFrac is what fraction of the y-axis the ship should be compared to screen
// size
Ship::Ship(float yFrac, sf::Vector2u &winSize, float thrust, float rs,
           std::unordered_map<int, Actor *> &actors, int &last_id)
    : Actor(yFrac, winSize), actors(actors), last_id(last_id)
{
    this->thrust = thrust;
    rotSpeed = rs;
    shape = new sf::CircleShape(radius, 3);
    shape->setOrigin(radius, radius);
    shape->setPosition(winSize.x / 2, winSize.y / 2);
    shape->setFillColor(sf::Color::White);
    shape->setScale(0.7, 1);
}

void Ship::applyInput(float rotSpeed, float dCoef)
{
    float rot = rotSpeed * dCoef;

    if (KeyData::getKeyState(Left))
    {
        rotate(-rot);
    }
    if (KeyData::getKeyState(Right))
    {
        rotate(rot);
    }
    if (KeyData::getKeyState(Up))
    {
        float currRot = getRotation();
        sf::Vector2f acc = VecMath::vecAtDeg(currRot) * thrust * dCoef;
        velocity += acc;
    }
    if (KeyData::getKeyState(Down))
    {
        ;
    }
    if (KeyData::getKeyState(Shoot))
    {
        sf::Time t = bullet_timer.getElapsedTime();
        sf::Int64 micro_since_shot = t.asMicroseconds();
        if (micro_since_shot > 1000000)
        {
            bullet_timer.restart();
            shoot();
        }
    }
}

// Update ship every frame
void Ship::update(sf::Time &delta)
{
    // calculate acceleration
    sf::Int64 ms = delta.asMicroseconds();
    float dCoef = ms / 1000000.f;
    applyInput(rotSpeed, dCoef);

    // update position
    shape->move(velocity);
}

void Ship::shoot()
{
    const auto dir = getDirection();
    const auto vel = dir * bullet_speed;
    const auto offset = dir * getRadius();
    const auto front_of_ship = getPosition() + offset;
    actors[last_id++] =
        new Projectile(bullet_rad, winSize, front_of_ship, vel);
}