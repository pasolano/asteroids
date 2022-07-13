#include <SFML/Graphics.hpp>
#include "KeyData.hpp"
#include "Actor.hpp"

#pragma once

class PlayerView {
    private:
        sf::RenderWindow* window = new sf::RenderWindow();
    public:
        void handleEvents();
        bool isOpen();
        void draw(std::vector<Actor*>&);
        PlayerView();
        void outOfBounds(Actor*);
};