#ifndef ENEMY_CPP
#define ENEMY_CPP
#include "Enemy.h"
#include <stdio.h>

Enemy::Enemy(int enemyType)
{
    switch (enemyType){
        case Green:
            Enemy::BaseEnemy(1,5,0,5,0);
            if (!Enemy::load("Picture/green_enemy.png")){
                printf("Failed to load green enemy\n");
            }
            break;
        case Yellow:
            Enemy::BaseEnemy(2,7,0,7,0);
            if (!Enemy::load("Picture/yellow_enemy.png")){
                printf("Failed to load yellow enemy\n");
            }
            break;
        case Red:
            Enemy::BaseEnemy(3,10,0,7,0);
            if (!Enemy::load("Picture/red_enemy.png")){
                printf("Failed to load red enemy\n");
            }
            break;
    }
}



#endif