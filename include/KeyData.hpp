#include <map>
#include "SFML/Window.hpp"

#pragma once

enum Action {Left, Right, Up, Down, Shoot};

class KeyData {
    static std::map<sf::Keyboard::Key, Action> keymap;
    static std::map<Action, bool> keystate;

    public:
        KeyData();
        static bool getKeyState(Action);
        static void setKeyState(sf::Keyboard::Key, bool);
        static void setKeyState(Action, bool);
};