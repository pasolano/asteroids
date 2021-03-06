#include <SFML/System.hpp>
#include "Actor.hpp"
#include "KeyData.hpp"
#include "Projectile.hpp"
#include <list>

#pragma once

class Ship : public Actor
{
    float thrust;
    float rotSpeed;
    sf::Clock bullet_timer;
    float bullet_rad = 0.005;
    float bullet_speed = 2000;
    std::list<Actor *> bullets;
    int bullet_id = 0;

public:
    Ship(float, sf::Vector2u &, float, float);
    void update(const sf::Time &);
    void applyInput(float, float);
    void shoot();
    std::list<Actor *> &getBullets();
};