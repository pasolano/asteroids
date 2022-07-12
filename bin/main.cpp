#include <iostream>
#include "Ship.hpp"
#include "KeyData.hpp"

float speed = 100;

sf::Clock cloc;

sf::Vector2<float> getAcc(float mov) {
    sf::Vector2<float> acc;

    if (KeyData::getKeyState(Left)) {
        acc.x = -mov;
    }
    if (KeyData::getKeyState(Right)) {
        acc.x = mov;
    }
    if (KeyData::getKeyState(Up)) {
        acc.y = -mov;
    }
    if (KeyData::getKeyState(Down)) {
        acc.y = mov;
    }

    return acc;
}

int main()
{
    KeyData* kd = new KeyData();
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    Ship ship = Ship();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                KeyData::setKeyState(event.key.code, true);
            }
            else if (event.type == sf::Event::KeyReleased) {
                KeyData::setKeyState(event.key.code, false);
            }
        }

        sf::Time time = cloc.restart();
        sf::Int64 ms = time.asMicroseconds();
        float mov = (ms * speed) / 1000000.f;

        sf::Vector2<float> acc = getAcc(mov);

        ship.move(acc);

        window.clear();
        window.draw(ship.shape);
        window.display();
    }

    return 0;
}
