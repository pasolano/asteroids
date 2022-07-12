#include <KeyData.hpp>

std::map<int, Action> KeyData::keymap = {{71, Left},
                                         {72, Right},
                                         {73, Up},
                                         {74, Down}};

std::map<Action, bool> KeyData::keystate = {{Left, false},
                                            {Right, false},
                                            {Up, false},
                                            {Down, false}};

KeyData::KeyData() {
    // TODO: read from config
}

bool KeyData::getKeyState(Action act) {
    return keystate[act];
}

void KeyData::setKeyState(int keycode, bool pressed) {
    auto temp = keymap.find(keycode);
    if (temp != keymap.end()) {
        Action action = temp->second;
        keystate[action] = pressed;
    }
}