#include <SFML/Graphics.hpp>
#include "KeyData.hpp"
#include "Ship.hpp"
#include <unordered_map>
#include "Asteroid.hpp"
// #include "VecMath.hpp"

#pragma once

class PlayerView
{
private:
    sf::RenderWindow *window = new sf::RenderWindow();
    sf::ContextSettings settings;

public:
    void handleEvents();
    bool isOpen() const;
    void draw_all(std::list<Actor *> ships, std::list<Actor *> asteroids);
    void draw(std::list<Actor *> &items);
    void draw(Actor *actor);
    PlayerView();
    void putInBounds(Actor *);
    sf::Shape *updateShape(Actor *);
    sf::Vector2u getWinSize() const;
};