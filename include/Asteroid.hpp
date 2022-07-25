#include "Projectile.hpp"

class Asteroid : public Projectile
{
public:
    Asteroid(float yFrac, sf::Vector2u &winSize);
};