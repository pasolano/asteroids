#include <SFML/System.hpp>
#include <cmath>
#include <iostream>

#pragma once

float degToRad(float deg) {
    return deg * M_PI/180;
}

float radToDeg(float rad) {
    return rad * 180/M_PI;
}

void rotateVector(sf::Vector2f& v, float rads, bool inRad, float dCoef = 1) {
    if (!inRad) rads = degToRad(rads);
    float cDeg = cos(rads);
    float sDeg = sin(rads);
    float old_x = v.x;
    v.x = (v.x * cDeg - v.y * sDeg) * dCoef;
    v.y = (old_x * sDeg + v.y * cDeg) * dCoef;

}

float dot(sf::Vector2f& v1, sf::Vector2f& v2) {
    return v1.x * v2.x + v1.y * v2.y;
}

float det(sf::Vector2f& v1, sf::Vector2f& v2) {
    return v1.x * v2.y - v1.y * v2.x;
}

float lenOfVec(sf::Vector2f& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

float degBetVec(sf::Vector2f& v1, sf::Vector2f& v2) {
    return radToDeg(atan2(det(v1, v2), dot(v1, v2)));
}