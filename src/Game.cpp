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

    auto iter = actors.begin();
    while (iter != actors.end()) {
        auto& a = iter->second;
        assert(a);
        a->update(delta);
        view->putInBounds(a);
        iter++;
    }

    view->draw(actors);
}

Game::Game() {
    dClock = new sf::Clock();

    setOngoing(true);
    view = new PlayerView();
    
    sf::Vector2u winSize = view->getWinSize();

    actors[last_id++] = new Ship(0.05, winSize, 0.02, 180, actors, last_id);
}