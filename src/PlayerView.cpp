#include "PlayerView.hpp"
#include <cassert>
#include <iostream>

PlayerView::PlayerView() {
    auto vmode = sf::VideoMode::getDesktopMode();
    // window->create(sf::VideoMode(vmode.width, vmode.height), "Asteroids");
    window->create(sf::VideoMode(200, 200), "Asteroids");
}

bool PlayerView::isOpen() {
    return window->isOpen();
}

void PlayerView::handleEvents() {
    sf::Event event;
    while (window->pollEvent(event))
    {
        std::cout << event.type << std::endl;
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
            window->draw(*(a->getShape()));
        }
    }

    window->display();
}