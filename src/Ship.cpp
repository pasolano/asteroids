#include "Ship.hpp"
#include <iostream>

// yFrac is what fraction of the y-axis the ship should be compared to screen
// size
Ship::Ship(float yFrac, sf::Vector2u &winSize, float thrust, float rs)
    : Actor(yFrac, winSize)
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
        sf::Time time_since_shot = bullet_timer.getElapsedTime();
        sf::Int64 micro_since_shot = time_since_shot.asMicroseconds();
        if (micro_since_shot > 1000000)
        {
            bullet_timer.restart();
            shoot();
        }
    }
}

// Update ship every frame
void Ship::update(const sf::Time &delta)
{
    // calculate acceleration
    sf::Int64 ms = delta.asMicroseconds();
    float dCoef = ms / 1000000.f;
    applyInput(rotSpeed, dCoef);

    // update position
    shape->move(velocity);

    // update bullets
    for (auto iter = bullets.begin(); iter != bullets.end(); iter++)
    {
        iter->second->update(delta);
    }
}

void Ship::shoot()
{
    const auto dir = getDirection();
    const auto vel = dir * bullet_speed;
    const auto offset = dir * getRadius();
    const auto front_of_ship = getPosition() + offset;
    bullets[bullet_id++] =
        new Projectile(bullet_rad, winSize, front_of_ship, vel);
}

std::unordered_map<int, Actor *> &Ship::getBullets()
{
    return bullets;
}