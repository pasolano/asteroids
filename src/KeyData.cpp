#include <KeyData.hpp>

std::map<sf::Keyboard::Key, Action> KeyData::keymap = {{sf::Keyboard::Left, Left},
                                                       {sf::Keyboard::Right, Right},
                                                       {sf::Keyboard::Up, Up},
                                                       {sf::Keyboard::Down, Down},
                                                       {sf::Keyboard::Space, Shoot}};

std::map<Action, bool> KeyData::keystate = {{Left, false},
                                            {Right, false},
                                            {Up, false},
                                            {Down, false},
                                            {Shoot, false}};

KeyData::KeyData() {
    // TODO: read from config
}

bool KeyData::getKeyState(Action act) {
    return keystate[act];
}

void KeyData::setKeyState(sf::Keyboard::Key keycode, bool pressed) {
    auto temp = keymap.find(keycode);
    if (temp != keymap.end()) {
        Action action = temp->second;
        setKeyState(action, pressed);
    }
}

void KeyData::setKeyState(Action action, bool pressed) {
    keystate[action] = pressed;
}