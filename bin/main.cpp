#include <iostream>
#include "Ship.hpp"
#include "KeyData.hpp"

float speed = 100;

sf::Clock cloc;

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

        sf::Time delta = cloc.restart();
        ship.update(delta);

        ship.shape.setPosition(ship.getPosition());

        window.clear();
        window.draw(ship.shape);
        window.display();
    }

    return 0;
}
