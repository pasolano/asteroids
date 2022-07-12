#include <map>

#pragma once

enum Action {Left, Right, Up, Down};

class KeyData {
    static std::map<int, Action> keymap;
    static std::map<Action, bool> keystate;

    public:
        KeyData();
        static bool getKeyState(Action);
        static void setKeyState(int, bool);
};