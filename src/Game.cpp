#include "Game.hpp"

bool Game::isOngoing() const
{
    return ongoing;
}

void Game::setOngoing(bool val)
{
    ongoing = val;
}

void Game::update_m(std::unordered_map<int, Actor *> &m, sf::Time delta)
{
    auto iter = m.begin();
    while (iter != m.end())
    {
        auto &curr = iter->second;
        assert(curr);
        curr->update(delta);
        view->putInBounds(curr);
        iter++;
    }
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

    update_m(ships, delta);
    for (auto &s : ships)
    {
        update_m(((Ship *)s.second)->getBullets(), delta);
    }
    update_m(asteroids, delta);

    // check for collisions
    // TODO ship collision
    for (auto &s : ships)
    {
        auto &bullets_ref = ((Ship *)s.second)->getBullets();
        for (auto &b : bullets_ref)
        {
            Projectile *b_ref = (Projectile *)b.second;
            for (auto &a : asteroids)
            {
                if (b_ref->collidesWith(a.second))
                {
                    // TODO remove from respective maps
                    b_ref->setAlive(false);
                    a.second->setAlive(false);
                }
            }
        }
    }

    view->draw_all(ships, asteroids);
}

Game::Game()
{
    sf::Vector2u winSize = view->getWinSize();

    ships[0] = new Ship(0.05, winSize, 0.02, 180);

    asteroids[0] = new Asteroid(0.05, winSize);
}