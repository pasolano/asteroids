#include "Game.hpp"

bool Game::isOngoing() {
    return ongoing;
}

void Game::setOngoing(bool val) {
    ongoing = val;
}

void Game::update() {
    if (!view->isOpen()) {
        setOngoing(false);
        return;
    }

    view->handleEvents();

    sf::Time delta = dClock->restart();

    for (Actor* a : actors) {
        a->update(delta);
        view->putInBounds(a);
    }

    view->draw(actors);
}

Game::Game() {
    dClock = new sf::Clock();

    setOngoing(true);
    view = new PlayerView();
    
    sf::Vector2u winSize = view->getWinSize();
    ship = new Ship(0.05, 0.02, 180, winSize);
    actors.push_back(ship);
}