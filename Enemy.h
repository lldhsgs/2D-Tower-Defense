#ifndef ENEMY_H
#define ENEMY_H

#include "utils.h"
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

class Enemy
{
    public:
        
        Enemy();
        void move();
        bool checkCollision();
        void takeDamage();
        void render(int x,int y,int ID);

    private:
        int enemyType; // ID
        int velocity;
        int damage;
        int HP;
        int armor;

        LTexture enemyTexture;
};
#endif