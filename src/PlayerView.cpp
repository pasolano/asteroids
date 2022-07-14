#include "PlayerView.hpp"
#include <cassert>
#include <iostream>

PlayerView::PlayerView() {
    auto vmode = sf::VideoMode::getDesktopMode();
    window->create(sf::VideoMode(vmode.width, vmode.height), "Asteroids", sf::Style::Fullscreen);
    settings.antialiasingLevel = 8;
}

bool PlayerView::isOpen() {
    return window->isOpen();
}

void PlayerView::handleEvents() {
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
        else if (event.type == sf::Event::KeyPressed) {
            KeyData::setKeyState(event.key.code, true);
        }
        else if (event.type == sf::Event::KeyReleased) {
            KeyData::setKeyState(event.key.code, false);
        }
    }
}

void PlayerView::draw(std::vector<Actor*>& actors) {
    window->clear();

    for (Actor* a : actors) {
        assert(a->getShape() != nullptr); // ensure shape was assigned
        if (a->isVisible()) {
            sf::Shape* s = updateShape(a);
            window->draw(*s);
        }
    }

    window->display();
}

// checks for out of bounds
// if yes, teleports actor to opposite end of screen
void PlayerView::putInBounds(Actor* actor) {
    sf::Vector2f pos = actor->getPosition();
    float rad = actor->getRadius();
    sf::Vector2u windims = window->getSize();

    // top boundary
    if (pos.y + rad < 0) pos.y = windims.y + rad;
    // bottom
    if (pos.y - rad > windims.y) pos.y = -rad;
    // left
    if (pos.x + rad < 0) pos.x = windims.x + rad;
    // right
    if (pos.x - rad > windims.x) pos.x = -rad;

    actor->setPosition(pos);
}

sf::Shape* PlayerView::updateShape(Actor* actor) {
    return actor->getShape();
}

sf::Vector2u PlayerView::getWinSize() {
    return window->getSize();
}