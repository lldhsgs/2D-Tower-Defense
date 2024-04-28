#pragma once

#include "Constants.hpp"
#include "GameObject.hpp"

enum
{
    Grey,
    GreenN,
    GreenS,
    Blue,
    Black
};
class BaseTower
{
public:
    BaseTower();
    void Place(int,int,int); // place the tower at the chosen tile
    void Attack(); // attacking an enemy by summoning bullets
    void Render();
    int getWidth();
private:
    int price;
    int attackSpeed;
    int range;
    GameObject* Tower;
}; 