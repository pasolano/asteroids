#include "VecMath.hpp"

float VecMath::degToRad(float deg)
{
    return deg * M_PI / 180;
}

float VecMath::radToDeg(float rad)
{
    return rad * 180 / M_PI;
}

void VecMath::rotateVector(sf::Vector2f &v, float rads, bool inRad, float dCoef = 1)
{
    if (!inRad)
        rads = degToRad(rads);
    float cDeg = cos(rads);
    float sDeg = sin(rads);
    float old_x = v.x;
    v.x = (v.x * cDeg - v.y * sDeg) * dCoef;
    v.y = (old_x * sDeg + v.y * cDeg) * dCoef;
}

float VecMath::dot(sf::Vector2f v1, sf::Vector2f v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

float VecMath::det(sf::Vector2f v1, sf::Vector2f v2)
{
    return v1.x * v2.y - v1.y * v2.x;
}

float VecMath::lenOfVec(sf::Vector2f v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}

float VecMath::degBetVec(sf::Vector2f v1, sf::Vector2f v2)
{
    return radToDeg(atan2(det(v1, v2), dot(v1, v2)));
}

sf::Vector2f VecMath::vecAtDeg(float deg)
{
    float rads = degToRad(deg - 90);
    return sf::Vector2f(cos(rads), sin(rads));
}