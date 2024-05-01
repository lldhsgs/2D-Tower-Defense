#pragma once

#include "Game.hpp"
#include "Constants.hpp"
#include "GameObject.hpp"
#include <string>

class Enemy
{
public: 
    Enemy(int,int);
    ~Enemy();
    void Move();
    void Render();
    void setDirection(int);
    int getDirection();
    SDL_Point getCurrentTile(int);
    bool checkEnd();
    bool checkDead();
    int getDamage();
    void takeDamage(int);
    int getX();
    int getY();
    int getPrize();
private:
    int VelX,VelY;
    int damage;
    int HP;
    int prize;
    bool isDead = false;
    GameObject* enemy;
};