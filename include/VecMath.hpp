#include <SFML/System.hpp>
#include <cmath>

#pragma once

class VecMath
{
public:
    static float degToRad(float deg);
    static float radToDeg(float rads);
    static void rotateVector(sf::Vector2f &v, float rads, bool inRad, float dCoef = 1);
    static float dot(sf::Vector2f v1, sf::Vector2f v2);
    static float det(sf::Vector2f v1, sf::Vector2f v2);
    static float lenOfVec(sf::Vector2f v);
    static float degBetVec(sf::Vector2f v1, sf::Vector2f v2);
    static sf::Vector2f vecAtDeg(float v);
};