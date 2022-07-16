#include "Actor.hpp"

#pragma once

class Projectile : public Actor
{
public:
    Projectile(float, sf::Vector2u &, sf::Vector2f, sf::Vector2f);
    void update(const sf::Time &delta) override;
};