#ifndef TOWER_H
#define TOWER_H
#include <SDL2/SDL.h>
#include "utils.h"
#include "Enemy.h"
#include <stdio.h>
#include <string>
#include <vector>

#define TILE_SIZE 100

enum
{
    Grey,
    GreenN,
    GreenS,
    Blue,
    Black
};

class Tower
{
    public:
        Tower();
        Enemy searchForTarget();
        void attack();

        int getBulletType();
        int getAttackSpeed();
        int getRange();

    private:
        int towerType;
        int bulletType;
        int attackSpeed;
        int range;
        SDL_Point coordinates;
        LTexture* towerTexture;
};
#endif