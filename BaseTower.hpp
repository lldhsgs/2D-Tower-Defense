#pragma once

#include "Constants.hpp"
#include "GameObject.hpp"

class BaseTower
{
public:
    BaseTower();
    void Place(int,int,int); // place the tower at the chosen tile
    void Attack(); // attacking an enemy by summoning bullets
    void Render();
    int getWidth();
private:
    int TowerType;
    int price;
    int attackSpeed;
    int range;
    GameObject* Tower;
}; 