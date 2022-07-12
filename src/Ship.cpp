#include "Ship.hpp"

Ship::Ship() {
    shape = sf::CircleShape(20.f);
    shape.setFillColor(sf::Color::Green);
}

void Ship::move(float x, float y) {
    shape.move(x, y);
}

void Ship::move(sf::Vector2<float>& acc) {
    shape.move(acc.x, acc.y);
}