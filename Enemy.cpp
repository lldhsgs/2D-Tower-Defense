

#include "Enemy.hpp"

std::string enemies[] = {"Picture/green_enemy.png","Picture/yellow_enemy.png","Picture/red_enemy.png"};
Enemy::Enemy(int type)
{
    switch (type){
        case Small:
            damage = 1;
            HP = 3;
            break;
        case Medium:
            damage = 2;
            HP = 5;
            break;
        case Large:
            damage = 3;
            HP = 10;
    }
    enemy = new GameObject(enemies[type].c_str(),0,600);
}

void Enemy::Render()
{
    enemy->RenderCenter();
}

void Enemy::setDirection(int direction)
{
    VelX = dx[direction];
    VelY = dy[direction];
}

int Enemy::getDirection()
{
    for(int direction = 0;direction < 8;++direction){
        if (VelX == dx[direction] && VelY == dy[direction]){
            return direction;
        }
    }
    return -1;
}

SDL_Point Enemy::getCurrentTile()
{
    return {enemy->getX() / TILE_SIZE,enemy->getY() / TILE_SIZE};
}

void Enemy::Move()
{
    enemy->setX(enemy->getX() + VelX);
    enemy->setY(enemy->getY() + VelY);
}