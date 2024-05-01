#pragma once

#include "Game.hpp"
#include "Constants.hpp"
#include "Enemy.hpp"
#include "GameObject.hpp"

class Bullet
{
public:
    Bullet(int,int,int);
    ~Bullet();
    void Move();
    void Collide(Enemy*);
    void Render();
    bool isCollided();
    void setDirection(int);
    int getType();
    void setX(int);
    void setY(int);
    void setCollision();
private:
    int bulletType;
    int Damage;
    int VelX,VelY;
    bool Collided;
    GameObject* bullet;
};