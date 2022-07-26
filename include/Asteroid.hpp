#include "Projectile.hpp"

class Asteroid : public Projectile
{
public:
    Asteroid(float yFrac, sf::Vector2u &winSize, sf::Vector2f pos, sf::Vector2f vel);
};