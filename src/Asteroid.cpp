#include "Asteroid.hpp"

Asteroid::Asteroid(float yFrac, sf::Vector2u &winSize, sf::Vector2f pos, sf::Vector2f vel)
    : Projectile(yFrac, winSize, pos, vel)
{
}