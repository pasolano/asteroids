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
    }

    view->draw(actors);
}

Game::Game() {
    dClock = new sf::Clock();

    setOngoing(true);
    view = new PlayerView();
    
    ship = new Ship(20, 0.1, 0.0002);
    actors.push_back(ship);
}