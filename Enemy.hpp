#pragma once

#include "Game.hpp"
#include "Constants.hpp"
#include "GameObject.hpp"
#include <string>

class Enemy
{
public: 
    Enemy(int);
    ~Enemy();
    void Move();
    void Render();
    void setDirection(int);
    int getDirection();
    SDL_Point getCurrentTile();
private:
    int VelX,VelY;
    int damage;
    int HP;
    GameObject* enemy;
};