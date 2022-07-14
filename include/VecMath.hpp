#include <SFML/System.hpp>
#include <cmath>

#pragma once

class VecMath {
    public:
        static float degToRad(float);
        static float radToDeg(float);
        static void rotateVector(sf::Vector2f&, float, bool, float);
        static float dot(sf::Vector2f&, sf::Vector2f&);
        static float det(sf::Vector2f&, sf::Vector2f&);
        static float lenOfVec(sf::Vector2f&);
        static float degBetVec(sf::Vector2f&, sf::Vector2f&);
        static sf::Vector2f vecAtDeg(float);
};