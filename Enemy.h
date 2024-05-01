#pragma once

#include <SDL2/SDL.h>
#include "utils.h"
#include <stdio.h>
#include <string>
#include <vector>

#define TILE_SIZE 100

enum
{
    Green,
    Yellow,
    Red
};

class Enemy
{
    public:
        
        Enemy();
        void move();
        bool checkCollision();
        void takeDamage();


    private:
        int enemyType; // ID
        int velocity;
        int damage;
        int HP;
        int armor;

        LTexture* enemyTexture;
};