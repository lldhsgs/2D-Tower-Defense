#pragma once

#include "Constants.hpp"
#include "GameObject.hpp"
#include "Bullet.hpp"
class BaseTower
{
public:
    BaseTower();
    void Place(int,int,int); // place the tower at the chosen tile
    void Attack(int,Enemy*); // attacking an enemy by summoning bullets
    void Recharge();
    void Render();
    int getWidth();
    void Reset();
    Bullet* getBullet();
    bool getDelayed();
    void updateTimer();
    int getTimer();
private:
    int TowerType;
    int price;
    int DelayBetweenAttack;
    int timer;
    int range;
    bool Delayed;
    GameObject *Tower;
    Bullet* bullet;
}; 
