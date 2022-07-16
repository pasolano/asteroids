#include "Game.hpp"

bool Game::isOngoing() const
{
    return ongoing;
}

void Game::setOngoing(bool val)
{
    ongoing = val;
}

void Game::update()
{
    if (!view->isOpen())
    {
        setOngoing(false);
        return;
    }

    view->handleEvents();

    sf::Time delta = dClock->restart();

    auto iter = actors.begin();
    while (iter != actors.end())
    {
        auto &curr = iter->second;
        assert(curr);
        curr->update(delta);
        view->putInBounds(curr);
        iter++;
    }

    view->draw(actors);
}

Game::Game()
{
    sf::Vector2u winSize = view->getWinSize();

    actors[last_id++] = new Ship(0.05, winSize, 0.02, 180, actors, last_id);
}