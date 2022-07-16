#include "Projectile.hpp"

Projectile::Projectile(float yFrac, sf::Vector2u &winSize, sf::Vector2f pos, sf::Vector2f vel) : Actor(yFrac, winSize)
{
    radius = yFrac * winSize.y;
    shape = new sf::CircleShape(radius);
    shape->setOrigin(radius, radius);
    shape->setPosition(pos);
    shape->setFillColor(sf::Color::White);

    velocity = vel;
}

void Projectile::update(sf::Time &delta)
{
    sf::Int64 ms = delta.asMicroseconds();
    float dCoef = ms / 1000000.f;

    shape->move(velocity * dCoef);
}
