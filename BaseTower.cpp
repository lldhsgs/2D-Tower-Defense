

#include "BaseTower.hpp"
#include <string>
#include <iostream>
std::string cannons[] = {"Picture/grey_cannon.png","Picture/green_cannon.png","Picture/blue_cannon.png","Picture/black_cannon.png"};
BaseTower::BaseTower()
{
    range = 0;
    DelayBetweenAttack = 0;
    timer = 0;
    price = 0;
    Tower = nullptr;
    bullet = nullptr;
}

void BaseTower::Place(int towerType,int tileX,int tileY)
{
    if (towerType >= 4){
        printf("Tower not existing!\n");
        return;
    }
    TowerType = towerType;
    tileX *= 100;
    tileY *= 100;
    GameObject* temp = new GameObject(cannons[TowerType].c_str(),tileY,tileX);
    Tower = temp;
    switch (towerType + 100){
        case Grey:
            bullet = new Bullet(NORMAL_BULLET,tileY + TILE_SIZE/2,tileX + TILE_SIZE/2);
            DelayBetweenAttack = FPS;
            // printf("%d\n",bullet->getType());
            break;
        case Green:
            bullet = new Bullet(POISON_BULLET,tileY + TILE_SIZE/2,tileX + TILE_SIZE/2);
            DelayBetweenAttack = FPS/2;
            break;
        case Blue:
            bullet = new Bullet(LASER_BULLET,tileY + TILE_SIZE/2,tileX + TILE_SIZE/2);
            DelayBetweenAttack = FPS*2;
            break;
        case Black:
            bullet = new Bullet(NORMAL_BULLET,tileY + TILE_SIZE/2,tileX + TILE_SIZE/2);
            DelayBetweenAttack = FPS/5;
            break;
    }
    timer = DelayBetweenAttack;
    Delayed = false;
    // printf("%d %d\n",towerType,bullet->getType());
}

void BaseTower::Render()
{
//    printf("%d\n",Tower->getX());
    Tower->RenderCenter();
}
// int BaseTower::getWidth()
// {
//     return Tower->getWidth();
// }
void BaseTower::updateTimer()
{
    if (Delayed){
        ++timer;
        if (timer >= DelayBetweenAttack){
            Delayed = false;
            timer = 0;
        }
    }
    
}
void BaseTower::Attack(int direction,Enemy* enemy)
{
    if (bullet->isCollided()){ // the previous bullet already hit
        Delayed = true;
        Recharge();
    }
    if (Delayed) return;
        bullet->setDirection(direction);
        bullet->Move();
        bullet->Render();
        bullet->Collide(enemy); 
}

void BaseTower::Recharge()
{
    bullet->setX(Tower->getX());
    bullet->setY(Tower->getY());
    bullet->setCollision();
}

Bullet* BaseTower::getBullet()
{
    return bullet;
}
bool BaseTower::getDelayed()
{
    return Delayed;
}