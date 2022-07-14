#include <SFML/Graphics.hpp>
#include "KeyData.hpp"
#include "Actor.hpp"
// #include "VecMath.hpp"

#pragma once

class PlayerView {
    private:
        sf::RenderWindow* window = new sf::RenderWindow();
    public:
        void handleEvents();
        bool isOpen();
        void draw(std::vector<Actor*>&);
        PlayerView();
        void putInBounds(Actor*);
        sf::Shape* updateShape(Actor*);
};