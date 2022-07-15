#include <SFML/Graphics.hpp>
#include "KeyData.hpp"
#include "Actor.hpp"
#include <unordered_map>
// #include "VecMath.hpp"

#pragma once

class PlayerView {
    private:
        sf::RenderWindow* window = new sf::RenderWindow();
        sf::ContextSettings settings;
    public:
        void handleEvents();
        bool isOpen();
        void draw(std::unordered_map<int, Actor*>&);
        PlayerView();
        void putInBounds(Actor*);
        sf::Shape* updateShape(Actor*);
        sf::Vector2u getWinSize(); 
};