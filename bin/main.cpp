#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

float speed = 100;

sf::Clock cloc;

enum Action {Left, Right, Up, Down};
std::map<int, Action> keymap {{71, Left}, {72, Right}, {73, Up}, {74, Down}};
std::map<Action, bool> keystate{{Left, false}, {Right, false}, {Up, false}, {Down, false}};

void setKeyState(bool pressed, int keycode) {
    auto temp = keymap.find(keycode);
    if (temp != keymap.end()) {
        Action action = temp->second;
        keystate[action] = pressed;
    }
}

void updateShape(sf::Shape& shape, float mov) {
    if (keystate[Left]) {
        shape.move(-mov, 0.f);
    }
    if (keystate[Right]) {
        shape.move(mov, 0.f);
    }
    if (keystate[Up]) {
        shape.move(0.f, -mov);
    }
    if (keystate[Down]) {
        shape.move(0.f, mov);
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(20.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::KeyPressed) {
                setKeyState(true, event.key.code);
            }
            else if (event.type == sf::Event::KeyReleased) {
                setKeyState(false, event.key.code);
            }
        }

        sf::Time time = cloc.restart();
        long ms = time.asMicroseconds();
        float mov = (ms * speed) / 1000000.f;
        updateShape(shape, mov);

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
