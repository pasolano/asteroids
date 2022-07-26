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

    // TODO ship collision
    for (auto &s : ships)
    {
        auto &bullets_ref = ((Ship *)s)->getBullets();
        auto bullets_iter = bullets_ref.begin();

        while (bullets_iter != bullets_ref.end())
        {
            bool collided = false;
            auto asteroids_iter = asteroids.begin();
            while (asteroids_iter != asteroids.end())
            {
                if ((*bullets_iter)->collidesWith(*asteroids_iter))
                {
                    delete *asteroids_iter;
                    delete *bullets_iter;
                    asteroids.erase(asteroids_iter);
                    bullets_ref.erase(bullets_iter++);
                    collided = true;
                    break;
                }
                else
                    asteroids_iter++;
            }
            if (!collided)
                bullets_iter++;
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