#include "Game.hpp"

bool Game::isOngoing() const
{
    return ongoing;
}

void Game::setOngoing(bool val)
{
    ongoing = val;
}

void Game::update_l(std::list<Actor *> &l, sf::Time delta)
{
    for (auto &a : l)
    {
        assert(a);
        a->update(delta);
        view->putInBounds(a);
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

    update_l(ships, delta);
    for (auto &s : ships)
    {
        update_l(((Ship *)s)->getBullets(), delta);
    }
    update_l(asteroids, delta);

    // check for collisions
    // TODO ship collision
    for (auto &s : ships)
    {
        auto &bullets_ref = ((Ship *)s)->getBullets();
        for (auto &b : bullets_ref)
        {
            Projectile *b_ref = (Projectile *)b;
            for (auto &a : asteroids)
            {
                if (b_ref->collidesWith(a))
                {
                    /* TODO
                     * remove from respective maps and delete objects
                     * or
                     * reuse objects when needed
                     */
                    b_ref->setAlive(false);

                    // TODO: this after loop finishes
                    // bullets_ref.erase(b.first);
                    // delete b_ref;

                    a->setAlive(false);
                }
            }
        }
    }

    view->draw_all(ships, asteroids);
}

Game::Game()
{
    sf::Vector2u winSize = view->getWinSize();

    ships.push_back(new Ship(0.05, winSize, 0.02, 180));

    asteroids.push_back(new Asteroid(0.05, winSize));
}