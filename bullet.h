#pragma once

#include <SDL2/SDL.h>
#include "utils.h"
#include <stdio.h>
#include <string>
#include <vector>

#define TILE_SIZE 100

enum
{
    Normal,
    Wall,
    Laser
};

class Bullet
{
    public:

        Bullet();
        void move();
        
        int getDamage();
        int getBulletVelocity();

    private:
        int damage;
        int bulletVelocity;

        SDL_Point coordinates;
        LTexture* bulletTexture;
};