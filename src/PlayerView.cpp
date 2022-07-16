#include "PlayerView.hpp"
#include <cassert>
#include <iostream>

PlayerView::PlayerView()
{
    auto vmode = sf::VideoMode::getDesktopMode();
    window->create(sf::VideoMode(vmode.width, vmode.height), "Asteroids", sf::Style::Fullscreen);
    settings.antialiasingLevel = 8;
}

bool PlayerView::isOpen() const
{
    return window->isOpen();
}

void PlayerView::handleEvents()
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        else if (event.type == sf::Event::KeyPressed)
        {
            KeyData::setKeyState(event.key.code, true);
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            KeyData::setKeyState(event.key.code, false);
        }
    }
}

void PlayerView::draw(std::unordered_map<int, Actor *> &actors)
{
    window->clear();

    auto iter = actors.begin();
    while (iter != actors.end())
    {
        auto &a_ref = iter->second;
        assert(a_ref->getShape()); // ensure shape was assigned
        if (a_ref->isVisible())
        {
            sf::Shape *a_shape = updateShape(a_ref);
            window->draw(*a_shape);
        }
        iter++;
    }

    window->display();
}

// checks for out of bounds
// if yes, teleports actor to opposite end of screen
void PlayerView::putInBounds(Actor *actor)
{
    sf::Vector2f pos = actor->getPosition();
    float rad = actor->getRadius();
    sf::Vector2u windims = window->getSize();

    // top boundary
    if (pos.y + rad < 0)
        pos.y = windims.y + rad;
    // bottom
    if (pos.y - rad > windims.y)
        pos.y = -rad;
    // left
    if (pos.x + rad < 0)
        pos.x = windims.x + rad;
    // right
    if (pos.x - rad > windims.x)
        pos.x = -rad;

    actor->setPosition(pos);
}

sf::Shape *PlayerView::updateShape(Actor *actor)
{
    return actor->getShape();
}

sf::Vector2u PlayerView::getWinSize() const
{
    return window->getSize();
}