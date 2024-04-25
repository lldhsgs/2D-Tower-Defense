#ifndef ENEMY_CPP
#define ENEMY_CPP
#include "Enemy.h"
#include <stdio.h>

Enemy::Enemy()
{
    enemyType = 0;
    velocity = 0;
    damage = 0;
    HP = 0;
    armor = 0;
}

void Enemy::render(int x,int y,int ID)
{
    switch(ID){
        case Green:
            if (!enemyTexture.loadFromFile(gRenderer,"Picture/green_enemy.png")){
                printf("Failed to load green enemy\n");
            }
        case Yellow:
            if (!enemyTexture.loadFromFile(gRenderer,"Picture/yellow_enemy.png")){
                printf("Failed to load yellow enemy\n");
            }
        case Red:
            if (!enemyTexture.loadFromFile(gRenderer,"Picture/red_enemy.png")){
                printf("Failed to load red enemy\n");
            }
        enemyTexture.render(gRenderer,x,y);
    }
}
#endif