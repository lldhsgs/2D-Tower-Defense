#ifndef BASEENEMY_H
#define BASEENEMY_H

#include "utils.h"
#include "Renderable.h"
// #include <SDL2/SDL.h>
// #include <stdio.h>
// #include <string>
// #include <vector>

#define TILE_SIZE 100

enum
{
    Green,
    Yellow,
    Red
};


class BaseEnemy : public Renderable
{
    public:
        BaseEnemy();
        BaseEnemy(int damage,int HP,int armor,int velocity,int price);
        void move();
        bool checkCollision();
        void takeDamage();
    private:
        int enemyDamage;
        int HP;
        int armor;
        int velocity;
        int price;
};
#endif