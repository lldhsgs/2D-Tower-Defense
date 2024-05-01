#ifndef BASEENEMY_CPP
#define BASEENEMY_CPP

#include "BaseEnemy.h"
#include <stdio.h>
#include <fstream>

int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};
int Map[12][8];
BaseEnemy::BaseEnemy()
{
    enemyDamage = 0;
    HP = 0;
    armor = 0;
    velocity = 0;
    price = 0;
}
BaseEnemy::BaseEnemy(int damage,int HP,int armor,int velocity,int price) : enemyDamage(damage),HP(HP),
armor(armor),velocity(velocity),price(price) {}

void BaseEnemy::move()
{
    int X,Y;
    std::ifstream inputMap("Map.txt");
    for(int i = 0; i < TOTAL_TILE_X;++i){
        for(int j = 0;j < TOTAL_TILE_Y;++j){
            inputMap >> Map[i][j];
        }
    }

    int tileX = getX() / TILE_SIZE;
    int tileY = getY() / TILE_SIZE;
    X = getX() + velocity * dx[Map[tileX][tileY]];
	Y = getY() + velocity * dy[Map[tileX][tileY]];
    BaseEnemy::setPosition(X,Y);
}



#endif