#include <iostream>
#include "Ship.hpp"
#include "KeyData.hpp"
#include "Game.hpp"

sf::Clock cloc;

int main()
{
    KeyData* kd = new KeyData();
    Game* game = new Game();

    while (game->isOngoing())
    {
        game->update();
    }

    return 0;
}
