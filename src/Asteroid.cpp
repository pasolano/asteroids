#include "Asteroid.hpp"

Asteroid::Asteroid(float yFrac, sf::Vector2u &winSize)
    : Projectile(yFrac, winSize, sf::Vector2f(10, 10), sf::Vector2f(50, 50))
{
}